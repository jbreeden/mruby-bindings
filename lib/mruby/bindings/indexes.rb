require 'csv'
require "yaml"
require 'mruby/bindings'

module MRuby::Bindings

  # Data shall be stored in "indexes" of "collections."
  # Indexes shall respond to methods, indicating names of collections.
  # Collections shall respond to "each," and yield hashes.
  # There shall be no "rewind," for one day our inputs may be streamed to us.
  # Also, why would you need to look at a thing twice? Make up your mind already.
  # So the interface is written, so shall it be.
  
  module SendAncestors
    def send_ancestors(m, *args, &block)
      ancestors[1..-1].each do |a|
        if a.respond_to?(m)
          return a.send(m, *args, &block)
        end
      end
      raise NoMethodError.new("No ancestor responds to #{m}")
    end
  end

  module DirectoryIndex
    module ClassMethods
      include SendAncestors

      # Class macro for defining the directory to expose.
      def directory(*args)
        if args.empty?
          return @directory || send_ancestors(:directory)
        end
        @directory = args[0]
      end

      # Class macro for defining the file extension to support.
      def ext(*args)
        if args.empty?
          return @ext || send_ancestors(:ext)
        end
        @ext = args[0]
      end
    end

    module InstanceMethods
      def directory
        self.class.directory
      end

      def ext
        self.class.ext
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

        path = "#{self.directory}/#{filename_str}.#{self.ext}"
        puts path

        path_exists = File.exists?(path)

        if name_str.end_with?('?')
          return path_exists
        end

        if path_exists
          return @files[name] = self.materialize(path)
        end

        super
      end
    end

    def self.included(other)
      other.send(:include, InstanceMethods)
      other.send(:extend, ClassMethods)
    end
  end

  class CSVCollection
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

  class CSVDirectoryIndex
    include DirectoryIndex
    ext 'csv'

    def materialize(path)
      CSVCollection.new(CSV.open(path, headers: true))
    end
  end

  class YAMLCollection
    include Enumerable

    def initialize(file)
      @file = file
    end

    def each
      YAML.load_stream(@file).each { |obj|
        yield obj
      }
    end
  end

  class YAMLDirectoryIndex
    include DirectoryIndex
    ext 'yaml'

    def materialize(path)
      YAMLCollection.new(File.open(path))
    end
  end

  class DiscoveryIndex < CSVDirectoryIndex
    directory MRuby::Bindings::Paths::DISCOVERY_DIR
  end

  class SummaryIndex < CSVDirectoryIndex
    directory MRuby::Bindings::Paths::SUMMARY_DIR
  end

  class RenderIndex < YAMLDirectoryIndex
    directory MRuby::Bindings::Paths::RENDER_DIR
  end
end
