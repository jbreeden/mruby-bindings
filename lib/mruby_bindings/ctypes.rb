require 'mruby_bindings/names'

module CTypes
  
  @enabled_macros = {}
  @param_types = {}
  @return_types = {}
  @fn_headers = {}
  @fn_footers = {}
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
    
    def get_fn_header(fn)
      @fn_headers[fn]
    end
    
    def set_fn_header(fn, header)
      @fn_headers[fn] = header
    end
    
    def get_fn_footer(fn)
      @fn_footers[fn]
    end
    
    def set_fn_footer(fn, footer)
      @fn_footers[fn] = footer
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
    
    def translate_type_names(&block)
      raise ArgumentError.new("Block required") unless block_given?
      @type_translator = block
    end
    
    def type_translator
      @type_translator ||= proc { |name| MRubyBindings.type_name_to_rb_class(name) }
    end
    
    def translate_fn_names(&block)
      raise ArgumentError.new("Block required") unless block_given?
      @fn_translator = block
    end
    
    def fn_translator
      @fn_translator ||= proc { |name| name }
    end
    
    def translate_enum_names(&block)
      raise ArgumentError.new("Block required") unless block_given?
      @enum_translator = block
    end
    
    def enum_translator
      @enum_translator ||= proc { |name| name }
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

    # mruby-bindings learns how to box/unbox types on demand, when a function
    # parameter or return value is seen with the given type. If we've also
    # seen a type declaration for this type, we'll have boxing/unboxing functions
    # to call. Otherwise, insert some TODO stubs for the user to swap out.
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
