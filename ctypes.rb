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
    attr_accessor :recv_type,
      :format_specifier,
      :type_name, 
      :boxing_fn,
      :unboxing_fn,
      :type_check,
      :return_cleanup

    def initialize(type_name, &block)
      self.type_name = type_name
      self.recv_type = "mrb_value"
      self.format_specifier = "o"
      self.boxing_fn = BoxingFn.new
      boxing_fn.name = "TODO_mruby_box_#{type_name.type_to_identifier.split(' ').join('_')}"
      self.unboxing_fn = BoxingFn.new
      unboxing_fn.name = "TODO_mruby_unbox_#{type_name.type_to_identifier.split(' ').join('_')}"
      self.instance_eval(&block) if block_given?
    end
    
    def aliased_as(t_name)
      duplicate = self.dup
      if duplicate.recv_type == self.type_name
        duplicate.recv_type = t_name
      end
      duplicate.type_name = t_name
      duplicate
    end
    
    def dup
      dup = Definition.new(type_name)
      dup.recv_type = self.recv_type
      dup.format_specifier = self.format_specifier
      dup.boxing_fn = self.boxing_fn
      dup.unboxing_fn = self.unboxing_fn
      dup.type_check = self.type_check
      dup
    end
    
    def declare_box(name)
      if self.recv_type.end_with?('*')
        "#{self.recv_type} #{name} = NULL;"
      else
        "#{self.recv_type} #{name};"
      end
    end
    
    def needs_unboxing?
      if @needs_unboxing.nil?
        !@out_only && self.format_specifier == 'o'
      else
        @needs_unboxing
      end
    end
    
    def needs_unboxing=(val)
      @needs_unboxing = !!val
    end
    
    def needs_type_check?
      if @needs_type_check.nil?
        self.needs_unboxing?
      else
        @needs_type_check
      end
    end
    
    def needs_type_check=(val)
      @needs_type_check = !!val
    end
    
    def out_only?
      @out_only
    end
    
    def out_only=(val)
      @out_only = !!val
    end
    
    def inspect
      # Simple format for diagnostic output (keeps it cleaner)
      "#<CType[#{type_name}]>"
    end
  end
end

module CTypes
  @param_types = {}
  @return_types = {}
  @types = {}
  @typedefs = {}

  class << self
    def define(*type_names, &block)
      type_names = type_names.flatten
      type_names.each do |type_name|
        definition = Definition.new(type_name, &block)
        @types[type_name] = definition
      end
    end

    def typedef(underlying_type, new_type)
      @typedefs[new_type] = underlying_type
    end
    
    def get_fn_param_type(fn, param)
      @param_types[[fn, param]]
    end
    
    def set_fn_param_type(fn, param, type)
      @param_types[[fn, param]] = type
    end
    
    def get_fn_return_type(fn)
      @return_types[fn]
    end
    
    def set_fn_return_type(fn, type)
      @return_types[fn] = type
    end

    def [](type_name)
      if type_name.kind_of? Hash
        if type_name['type_name']
          type_name = type_name['type_name']
        elsif type_name['type']
          type_name = type_name['type']['type_name']
        elsif type_name['return_type']
          type_name = type_name['return_type']['type_name']
        end
      end
      
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
        # memoize result
        @types[type_name] = type.aliased_as(type_name)
        return @types[type_name]
      end
    end
    
    def []=(name, val)
      @types[name] = val
    end

    def learn_enum(name)
      @types[name] = @types['int'].aliased_as(name)
    end

    def learn_data_type(type)
      # Only need to learn a new type once
      if seen = CTypes[type['type_name']]
        return seen
      end

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
      CTypes[type['type_name']]
    end

  end
end
