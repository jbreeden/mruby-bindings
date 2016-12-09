require 'csv'
require 'json'
require 'yaml'
require 'mruby/bindings'

module MRuby::Bindings

  # Data shall be stored in "indexes" of "streams."
  # Indexes shall respond to methods, indicating names of streams.
  # Streams shall respond to "each," and yield objects.
  # Streams shall not yield objects that reveal their origin
  #  - Such as storage location, or storage format.
  #  - i.e. no CSV::Row or the like, convert to hashes if needed.
  # There shall be no "rewind," for one day our streams may be real streams, instead of files on disk.
  # So the interface is written, so shall it be.
  
  class CSVStream
    include Enumerable

    def initialize(csv)
      @csv = csv
    end

    def each(*args)
      if block_given?
        @csv.each(*args) do |e|
          yield e.to_h
        end
      else
        enum_for :each
      end
    end
  end

  class JSONStream
    include Enumerable

    def initialize(file)
      @file = file
    end

    def each
      if block_given?
        @file.each_line { |l|
          yield JSON.parse(l)
        }
      else
        enum_for :each
      end
    end
  end

  class YAMLStream
    include Enumerable

    def initialize(file)
      @file = file
    end

    def each
      if block_given?
        YAML.load_stream(@file).each { |obj|
          yield obj
        }
      else
        enum_for :each
      end
    end
  end

  module MaterializeFiles
    def self.materialize_file(path)
      ext = File.extname(path).sub('.', '')
      self.send("materialize_#{ext}", path)
    end

    def self.materialize_csv(path)
      CSVStream.new(CSV.open(path, headers: true))
    end

    def self.materialize_json(path)
      JSONStream.new(File.open(path))
    end

    def self.materialize_yaml(path)
      YAMLStream.new(File.open(path))
    end
  end

  class DirectoryIndex
    module ClassMethods
      # Class macro for defining the directory to expose.
      def directory(*args)
        if args.empty?
          return @directory
        end
        @directory = args[0]
      end

      # Class macro for defining a method for accessing the given file.
      # Delegates to method_missing directly, skipping the rest of the method
      # lookup chain. Also allows better refletion on instances of this class.
      def file(name)
        define_method(name) {
          begin
            self.method_missing(name)
          rescue NoMethodError
            raise Errno::ENOENT.new("Cannot correlate method `#{name}` to a file on disk")
          end
        }
      end
    end

    def initialize
      @files = {}
    end

    def method_missing(name)
      name_str = name.to_s

      hit = @files[name_str]
      return hit if hit

      filename_str = name_str.gsub('_', '-')
      filename_str = filename_str.end_with?('?') ? filename_str[0..-2] : filename_str

      glob = "#{self.class.directory}/#{filename_str}.*"
      path = Dir[glob][0]

      path_exists = !path.nil? && File.exists?(path)

      if name_str.end_with?('?')
        return path_exists
      end

      if path_exists
        return @files[name] = MaterializeFiles.materialize_file(path)
      end

      super
    end

    def self.inherited(other)
      other.send(:extend, ClassMethods)
      super
    end
  end

  class BlueprintIndex < DirectoryIndex
    directory MRuby::Bindings::Paths::BLUEPRINT_DIR
    file :ctypes
    file :functions
  end

  class DiscoveryIndex < DirectoryIndex
    directory MRuby::Bindings::Paths::DISCOVERY_DIR
    file :fields
    file :functions
    file :parms
    file :typedefs
    file :types
  end

  class IngestIndex < DirectoryIndex
    directory MRuby::Bindings::Paths::INGEST_DIR
    file :field_decl
    file :function_decl
    file :macro_definition
    file :parm_decl
    file :struct_decl
    file :typedef_decl
  end

  class RenderIndex < DirectoryIndex
    directory MRuby::Bindings::Paths::RENDER_DIR
    file :classes
    file :class_initializations
    file :class_macros
    file :enum_constants
    file :function_initializations
    file :functions
  end

  class SummaryIndex < DirectoryIndex
    directory MRuby::Bindings::Paths::SUMMARY_DIR
    file :type_occurrences
  end
end
