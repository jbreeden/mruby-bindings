require 'csv'

module MRuby::Bindings
  class TypedefResolver
    def initialize
      @typedefs = {}
      @preferred_names = {}
      filename = './mruby-bindings.out/discovery/typedefs.csv'
      if File.exists?(filename)
        CSV.foreach(filename, headers: true) do |row|
          @typedefs[row['name']] = row['underlying_type'] unless @typedefs[row['name']]
        end
      end

      # If the typedef name is almost exactly the underlying type name,
      # assume that it's the preferred name of the type, rather than
      # a new unrelated type.
      # 
      # Example:
      # // New preferred name
      # struct my_type_t;
      # typedef struct my_type_t my_type;
      #
      # // New unrelated type
      # typedef double money;
      @typedefs.each do |k,v|

        # Fuzzy match (yields a single name if matched)
        reduction = [k,v].map { |name|
          name.sub(/^struct\s*/, '')[1..-2].
            gsub('_','').
            downcase
        }.uniq.select { |e| !e.nil? && e.length > 0 }

        if reduction.length == 1
          @preferred_names[k] = k
          @preferred_names[v] = k
        else
          @preferred_names[k] = k
          @preferred_names[v] = v
        end
      end
    end

    # Returns nil if no typedef is found
    def resolve(type)
      resolve_hash(@typedefs, type)
    end

    # Return the given type if no typedef is found
    def canonicalize(type)
      canonicalize_hash(@typedefs, type)
    end

    def resolve_preferred_name(type)
      resolve_hash(@preferred_names, type)
    end

    def preferred_name(type)
      canonicalize_hash(@preferred_names, type)
    end

    def resolve_hash(hash, type)
      underlying_type = hash[type]
      if !underlying_type
        return nil
      end
      if underlying_type == type
        return type
      end
      return resolve_hash(hash, underlying_type) || underlying_type
    end

    def canonicalize_hash(hash, type)
      type = type.sub(/^const\s*/,'') if type
      pointee = type[/^(\S+) \*$/, 1] if type
      if pointee
        "#{self.canonicalize_hash(hash, pointee)} *"
      else
        self.resolve_hash(hash, type) || type
      end
    end
  end
end
