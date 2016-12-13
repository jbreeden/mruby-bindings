module MRuby::Bindings
  module TypeMatchers
    def self.match_pattern(name, pattern)
      regex = Regexp.new(pattern)
      klass = self.const_set(name, Class.new)
      klass.define_instance_method(:===) do |type|
        type.match(regex)
      end
    end

    match_pattern :Enum, /^enum\s*\S*$/
  end
end
