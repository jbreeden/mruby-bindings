module CTypes
  class BoxingFn
    attr_accessor :name,      # The function name
      # An sprintf-style template for rendering the boxing/unboxing code inline
      :invocation_template,
      # Code to run before returning iff an object was uboxed as a parameter to
      # a function/method. Does not apply to objects being unboxed when setting
      # a field, since the field should retain the set value. For an example,
      # see the defintion for "char *" below.
      :param_cleanup_template
  end
end

module CTypes
  class Definition
    attr_accessor :type_name, :boxing_fn, :unboxing_fn, :type_check, :out_param

    def initialize(type_name)
      self.type_name = type_name
      self.out_param = false
      self.boxing_fn = BoxingFn.new
      boxing_fn.name = "TODO_mruby_box_#{type_name.type_to_identifier.split(' ').join('_')}"
      self.unboxing_fn = BoxingFn.new
      unboxing_fn.name = "TODO_mruby_unbox_#{type_name.type_to_identifier.split(' ').join('_')}"
    end
    
    def aliased_as(t_name)
      dup = Definition.new(t_name)
      dup.boxing_fn = self.boxing_fn
      dup.unboxing_fn = self.unboxing_fn
      dup.type_check = self.type_check
      dup
    end
  end
end

module CTypes
  @types = {}
  @typedefs = {}

  class << self
    def define(*type_names, &block)
      type_names = type_names.flatten
      type_names.each do |type_name|
        definition = Definition.new(type_name)
        @types[type_name] = definition
        definition.instance_eval &block
      end
    end

    def typedef(underlying_type, new_type)
      @typedefs[new_type] = underlying_type
    end

    def [](type_name)
      # Resolve typedef chain to first known type
      known_type = type_name
      loop {
        # Found a type definition... break!
        break if @types[known_type] || known_type.nil?
        
        # Traverse the next level of typedefs
        known_type = @typedefs[known_type]
      }

      type = @types[known_type]
      if known_type == type_name || type.nil?
        return type
      else
        return type.aliased_as(type_name)
      end
    end

    def learn_data_type(type)
      # Only need to learn a new type once
      return if CTypes[type['type_name']]

      CTypes.define(type['type_name']) do
        # We don't know the type, but we know the pointee type from a struct/class decl
        if type['type_is_pointer'] && $classes[type['pointee_type_usr']]
          boxing_fn.name = "mruby_box_#{type['pointee_type_name'].type_to_identifier}"
          boxing_fn.invocation_template = "mrb_value %{as} = (%{box} == NULL ? mrb_nil_value() : #{boxing_fn.name}(mrb, %{box}));"
          unboxing_fn.name = "mruby_unbox_#{type['pointee_type_name'].type_to_identifier}"
          unboxing_fn.invocation_template = "#{type['type_name']} %{as} = (mrb_nil_p(%{unbox}) ? NULL : #{unboxing_fn.name}(%{unbox}));"

          self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, #{$classes[type['pointee_type_usr']]['ruby_name']}_class(mrb))) {
  mrb_raise(mrb, E_TYPE_ERROR, "#{$classes[type['pointee_type_usr']]['ruby_name']} expected");
  return mrb_nil_value();
}
EOF
        # We know the exact type from a struct/class decl
        elsif $classes[type['type_usr']]
          boxing_fn.name = "mruby_box_#{type['type_name'].type_to_identifier}"
          boxing_fn.invocation_template = <<EOF
/* WARNING: Boxing a pointer to a value type.
 * If this is a stack variable, it will be deleted when this function returns.
 * If a longer lifespan is required, it should be put on the heap - consider
 * customizing this function (or add a `CTypes` definition to cover all instances)
 */
mrb_value %{as} = #{boxing_fn.name}(mrb, &%{box});
EOF
          unboxing_fn.name = "mruby_unbox_#{type['type_name'].type_to_identifier}"
          unboxing_fn.invocation_template = "#{type['type_name'].type_to_identifier} %{as} = *(#{unboxing_fn.name}(%{unbox}));"

          self.type_check = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, #{type['type_name'].type_to_identifier}_class(mrb))) {
  mrb_raise(mrb, E_TYPE_ERROR, "#{type['type_name'].type_to_identifier} expected");
  return mrb_nil_value();
}
EOF
        # We don't know the type at all, insert TODO's
        else
          boxing_fn.name = "TODO_mruby_box_#{type['type_name'].type_to_identifier.split(' ').join('_')}"
          boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(mrb, %{box});"
          unboxing_fn.name = "TODO_mruby_unbox_#{type['type_name'].type_to_identifier.split(' ').join('_')}"
          if type['type_name'].include? '(*)'
            # Inserting the identifier into the correct place for function pointers
            # We won't ever have a "class" declaration for these, so it only happens
            # with these "unkown" types.
            unboxing_fn.invocation_template = "#{type['type_name'].sub('(*)', '(*%{as})')} = #{unboxing_fn.name}(%{unbox});"
          else
            unboxing_fn.invocation_template = "#{type['type_name']} %{as} = #{unboxing_fn.name}(%{unbox});"
          end

          self.type_check = <<EOF
TODO_type_check_#{type['type_name'].type_to_identifier}(%{value});
EOF
        end
      end
    end

  end
end
