# CTypes.define('Example') do
#   self.needs_unboxing = true
#   self.needs_boxing_cleanup = false
#   self.needs_unboxing_cleanup = false
#   self.needs_type_check = true
#   
#   self.recv_template = 'mrb_value %{value};'
#   self.format_specifier = 'o'
#   self.get_args_template = '&%{value}'
#   self.type_check_template = nil
#   self.invocation_arg_template = '%{value}'
#   self.field_swap_template = %{old} = %{new};
#   
#   self.unboxing_fn.invocation_template = '%{as} = TODO_mruby_unbox_Example(%{unbox});'
#   self.unboxing_fn.cleanup_template = 'free(%{value});'
#   
#   self.boxing_fn.invocation_template = '%{as} = TODO_mruby_box_Example(%{box});'
#   self.boxing_fn.cleanup_template = 'free(%{value});'
# end

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
