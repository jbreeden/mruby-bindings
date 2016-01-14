require 'mruby_bindings/names'

module CTypes
  class BoxingFn
    attr_accessor(
      # - Unused. Should remove
      :name,
      # - Required
      :invocation_template,
      # - Optional (default is no unboxing cleanup)
      :cleanup_template)
      
    def dup
      duplicate = CTypes::BoxingFn.new
      duplicate.invocation_template = self.invocation_template
      duplicate.cleanup_template = self.cleanup_template
      duplicate
    end
  end
end

module CTypes
  class Definition
    attr_accessor(
      # - Optional (default = 'mrb_value %{value};')
      # - Template Args: value
      :recv_template,
      # - Optional (default = 'o')
      :format_specifier,
      # - Optional (default = '&%{value}')
      # - Template Args: value
      :get_args_template,
      # - Optional (default = "%{value}")
      :invocation_arg_template,
      # - Required
      :type_name,
      # - Semi-Optional (default is a TODO message) 
      # - Template Args: box & as
      :boxing_fn,
      # - Semi-Optional (default is a TODO message) 
      # - Template Args: unbox & as
      :unboxing_fn,
      # - Optional (default is no type check)
      # - Template Args: value
      :type_check_template,
      # - Optional (default is '%{old} = %{new};')
      # - Template Args: old, new
      :field_swap_template)

    def initialize(type_name, &block)
      self.type_name = type_name
      self.recv_template = "mrb_value %{value};"
      self.get_args_template = "&%{value}"
      self.invocation_arg_template = "%{value}"
      self.format_specifier = "o"
      self.field_swap_template = "%{old} = %{new};"
      self.boxing_fn = BoxingFn.new
      boxing_fn.invocation_template = "%{as} = TODO_mruby_box_#{MRubyBindings.type_name_to_id(type_name).split(' ').join('_')}(%{box});"
      self.unboxing_fn = BoxingFn.new
      unboxing_fn.invocation_template = "%{as} = TODO_mruby_unbox_#{MRubyBindings.type_name_to_id(type_name).split(' ').join('_')}(%{unbox});"
      self.instance_eval(&block) if block_given?
    end
    
    def aliased_as(t_name)
      duplicate = self.dup
      duplicate.type_name = t_name
      duplicate
    end
    
    def dup
      dup = Definition.new(type_name)
      self.instance_variables.each do |var|
        dup.instance_variable_set(var, self.instance_variable_get(var))
      end
      dup.boxing_fn = boxing_fn.dup if boxing_fn
      dup.unboxing_fn = unboxing_fn.dup if unboxing_fn
      dup
    end
    
    def out_only=(val)
      @out_only = !!val
    end
    
    def needs_unboxing=(val)
      @needs_unboxing = !!val
    end
    
    def needs_boxing_cleanup=(val)
      @needs_boxing_cleanup = !!val
    end
    
    def needs_unboxing_cleanup=(val)
      @needs_unboxing_cleanup = !!val
    end
    
    def needs_field_swap=(val)
      @needs_field_swap = !!val
    end
    
    def ignore=(val)
      @ignore = !!val
    end
    
    def unknown=(val)
      @unknown = !!val
    end
    
    # Template Interface
    # ------------------
    
    def recv(arg)
      return '' unless recv_template
      recv_template % {value: recv_name(arg)}
    end
    
    def get_args_argv(arg)
      return '' unless get_args_template
      get_args_template % {value: recv_name(arg)}
    end
    
    def invocation_argv(arg)
      return '' unless invocation_arg_template
      invocation_arg_template % {value: native_name(arg)}
    end
    
    def type_check(arg)
      return '' unless type_check_template
      type_check_template % {value: recv_name(arg)}
    end
    
    def unbox(arg)
      return '' unless unboxing_fn.invocation_template
      unboxing_fn.invocation_template % {unbox: ruby_name(arg), as: native_name(arg)}
    end
    
    def box(arg)
      return '' unless boxing_fn.invocation_template
      boxing_fn.invocation_template % {box: native_name(arg), as: ruby_name(arg)}
    end
    
    def box_return(native, ruby)
      return '' unless boxing_fn.invocation_template
      boxing_fn.invocation_template % {box: native, as: ruby}
    end
    alias box_lit box_return
    
    def cleanup_return(name)
      return '' unless boxing_fn.cleanup_template
      boxing_fn.cleanup_template % {value: name}
    end
    
    def cleanup_out_param(arg)
      cleanup_return(native_name(arg))
    end
    
    def cleanup_unboxing(arg)
      return '' unless unboxing_fn.cleanup_template
      unboxing_fn.cleanup_template % {value: native_name(arg)}
    end
    
    def swap_fields(old, new)
      return '' unless field_swap_template
      field_swap_template % {old: old, new: new}
    end
    
    def ignore?
      @ignore
    end
    
    def unknown?
      @unknown
    end
    
    def needs_unboxing?
      if @needs_unboxing.nil?
        !@out_only && self.format_specifier == 'o'
      else
        @needs_unboxing
      end
    end
    
    def needs_type_check?
      if @needs_type_check.nil?
        self.needs_unboxing?
      else
        @needs_type_check
      end
    end
    
    def needs_boxing_cleanup?
      if @needs_boxing_cleanup.nil?
        !!self.boxing_fn.cleanup_template
      else
        @needs_boxing_cleanup
      end
    end
    
    def needs_unboxing_cleanup?
      if @needs_unboxing_cleanup.nil?
        !!self.unboxing_fn.cleanup_template
      else
        @needs_unboxing_cleanup
      end
    end
    
    def needs_field_swap?
      if @needs_field_swap.nil?
        !!self.field_swap_template
      else
        @needs_field_swap
      end
    end
    
    # Queries
    # -------
    
    def recv_name(param_name)
      self.needs_unboxing? ? ruby_name(param_name) : native_name(param_name)
    end
    
    def native_name(param_name)
      "native_#{param_name}"
    end
    
    def ruby_name(param_name)
      param_name
    end
    
    def needs_type_check=(val)
      @needs_type_check = !!val
    end
    
    def out_only?
      @out_only
    end
    
    def inspect
      # Simple format for diagnostic output (keeps it cleaner)
      "#<CType[#{type_name}]>"
    end
  end
end

module CTypes
  @enabled_macros = {}
  @param_types = {}
  @return_types = {}
  @types = {}
  @typedefs = {}
  @destructors = Hash.new { |h, k| h[k] = 'free' }
  @skip_functions = {}

  class << self
    def define(*type_names, &block)
      type_names = type_names.flatten
      type_names.each do |type_name|
        definition = Definition.new(type_name, &block)
        @types[type_name] = definition
      end
    end

    def typedef(underlying_type, new_type)
      # Skip the typedef if we already know the new type
      # (In case the user has provided a custom definition for it)
      @typedefs[new_type] = underlying_type unless @typedefs[new_type] || @types[new_type]
    end
    
    def set_macro_type(name, type)
      @enabled_macros[name] = type
    end
    
    def get_macro_type(name)
      @enabled_macros[name]
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
    
    def set_destructor(type, fn)
      @destructors[type] = fn
    end
    
    def get_destructor(type)
      @destructors[type]
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
          boxing_fn.name = "mruby_box_#{MRubyBindings.type_name_to_id(type['pointee_type_name'])}"
          boxing_fn.invocation_template = "mrb_value %{as} = (%{box} == NULL ? mrb_nil_value() : #{boxing_fn.name}(mrb, %{box}));"
          unboxing_fn.name = "mruby_unbox_#{MRubyBindings.type_name_to_id(type['pointee_type_name'])}"
          unboxing_fn.invocation_template = "#{type['type_name']} %{as} = (mrb_nil_p(%{unbox}) ? NULL : #{unboxing_fn.name}(%{unbox}));"

          self.type_check_template = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, #{$classes[type['pointee_type_usr']]['ruby_name']}_class(mrb))) {
  mrb_raise(mrb, E_TYPE_ERROR, "#{$classes[type['pointee_type_usr']]['ruby_name']} expected");
  return mrb_nil_value();
}
EOF
        # We know the exact type from a struct/class decl
        elsif $classes[type['type_usr']]
          boxing_fn.name = "mruby_box_#{MRubyBindings.type_name_to_id(type['type_name'])}"
          boxing_fn.invocation_template = <<EOF
#{type['type_name']}* new_%{as} = TODO_move_#{MRubyBindings.type_name_to_id(type['type_name'])}_to_heap(%{box});
mrb_value %{as} = #{boxing_fn.name}(mrb, &%{box});
EOF
          unboxing_fn.name = "mruby_unbox_#{MRubyBindings.type_name_to_id(type['type_name'])}"
          unboxing_fn.invocation_template = "#{type['type_name']} %{as} = *(#{unboxing_fn.name}(%{unbox}));"

          self.type_check_template = <<EOF
if (!mrb_obj_is_kind_of(mrb, %{value}, #{$classes[type['type_usr']]['ruby_name']}_class(mrb))) {
  mrb_raise(mrb, E_TYPE_ERROR, "#{$classes[type['type_usr']]['ruby_name']} expected");
  return mrb_nil_value();
}
EOF
        # We don't know the type at all, insert TODO's
        else
          self.unknown = true
          boxing_fn.name = "TODO_mruby_box_#{MRubyBindings.type_name_to_id(type['type_name']).split(' ').join('_')}"
          boxing_fn.invocation_template = "mrb_value %{as} = #{boxing_fn.name}(mrb, %{box});"
          unboxing_fn.name = "TODO_mruby_unbox_#{MRubyBindings.type_name_to_id(type['type_name']).split(' ').join('_')}"
          if type['type_name'].include? '(*)'
            # Inserting the identifier into the correct place for function pointers
            # We won't ever have a "class" declaration for these, so it only happens
            # with these "unknown" types.
            unboxing_fn.invocation_template = "#{type['type_name'].sub('(*)', '(*%{as})')} = #{unboxing_fn.name}(%{unbox});"
          else
            unboxing_fn.invocation_template = "#{type['type_name']} %{as} = #{unboxing_fn.name}(%{unbox});"
          end

          self.type_check_template = <<EOF
TODO_type_check_#{MRubyBindings.type_name_to_id(type['type_name'])}(%{value});
EOF
        end
      end
      CTypes[type['type_name']]
    end

  end
end
