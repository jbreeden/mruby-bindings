module MRuby::Bindings
  module TypeChecks
    class CaseOfMethod
      def initialize(meth)
        @meth = meth
      end

      def ===(type)
        TypeChecks.send(@meth, type)
      end
    end

    def self.case_of(const, meth)
      self.const_set(const, CaseOfMethod.new(meth))
    end

    def self.enum?(type)
      type && type.match(/^enum\s*\S*$/)
    end
    case_of :Enum, :enum?

    def self.value_type?(type)
      type && type.match(/^(struct\s*)?\S*$/)
    end
    case_of :ValueType, :value_type?

    def self.function_pointer?(type)
      type && type.match(/\(\*\)/)
    end
    case_of :FunctionPointer, :function_pointer?

    def self.pointer?(type)
      type && type.match(/\*|\[/)
    end
    case_of :Pointer, :pointer?
  end
end

