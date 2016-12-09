require 'csv'
require "yaml"
require 'mruby/bindings'

module MRuby::Bindings

  # Data shall be stored in "indexes" of "streams."
  # Indexes shall respond to methods, indicating names of streams.
  # Streams shall respond to "each," and yield objects.
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
    def materialize_file(path)
      ext = File.extname(path).sub('.', '')
      self.send("materialize_#{ext}", path)
    end

    def materialize_csv(path)
      CSVStream.new(CSV.open(path, headers: true))
    end

    def materialize_yaml(path)
      YAMLStream.new(File.open(path))
    end
  end

  module DirectoryIndex
    module ClassMethods
      # Class macro for defining the directory to expose.
      def directory(*args)
        if args.empty?
          return @directory
        end
        @directory = args[0]
      end
    end

    module InstanceMethods
      include MaterializeFiles

      def directory
        self.class.directory
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

        glob = "#{self.directory}/#{filename_str}.*"
        path = Dir[glob][0]

        path_exists = !path.nil? && File.exists?(path)

        if name_str.end_with?('?')
          return path_exists
        end

        if path_exists
          return @files[name] = self.materialize_file(path)
        end

        super
      end
    end

    def self.included(other)
      other.send(:include, InstanceMethods)
      other.send(:extend, ClassMethods)
    end
  end

  def self.index(name, dir)
    new_class = Class.new
    new_class.send(:include, DirectoryIndex)
    new_class.send(:directory, dir)
    self.const_set(name, new_class)
  end

  index :BlueprintIndex, MRuby::Bindings::Paths::BLUEPRINT_DIR
  index :DiscoveryIndex, MRuby::Bindings::Paths::DISCOVERY_DIR
  index :IngestIndex, MRuby::Bindings::Paths::INGEST_DIR
  index :RenderIndex, MRuby::Bindings::Paths::RENDER_DIR
  index :SummaryIndex, MRuby::Bindings::Paths::SUMMARY_DIR
end
