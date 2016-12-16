require 'csv'

module MRuby::Bindings
  class TypedefResolver
    def initialize
      @hash = {}
      filename = './mruby-bindings.out/discovery/typedefs.csv'
      if File.exists?(filename)
        CSV.foreach(filename, headers: true) do |row|
          @hash[row['name']] = row['underlying_type']
        end
      end

      # Super-secret-probably-risky-convenience feature...
      # If the typedef name is almost exactly the underlying type name,
      # assume that it's the canonical version of the type, rather than
      # a new unrelated type.
      # 
      # Example:
      # // New canonical name
      # struct my_type_t;
      # typedef struct my_type_t my_type;
      #
      # // New unrelated type
      # typedef double money;
      #
      # TODO: LOG THIS TO A CSV FILE
      @hash.dup.each do |k,v|

        reduction = [k,v].map { |name|
          name.sub(/^struct\s*/, '')[1..-2].
            gsub('_','').
            downcase
        }.uniq.select { |e| !e.nil? && e.length > 0 }

        if reduction.length == 1
          @hash[k] = k
          @hash[v] = k
        end

      end
    end

    # Returns nil if no typedef is found
    def resolve(name)
      underlying_type = @hash[name]
      if !underlying_type
        return nil
      end
      if underlying_type == name
        return name
      end
      return resolve(underlying_type) || underlying_type
    end

    # Return the given type if no typedef is found
    def canonicalize(type)
      type = type.sub(/^const\s*/,'') if type
      pointee = type[/^(\S+) \*$/, 1] if type
      if pointee
        "#{self.canonicalize(pointee)} *"
      else
        self.resolve(type) || type
      end
    end
  end
end
