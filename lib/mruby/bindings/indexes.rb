require 'csv'
require 'mruby/bindings'

module MRuby::Bindings

  # Data shall be stored in "indexes" of "repos."
  # Indexes shall respond to methods, indicating names of repos.
  # Repos shall respond to "each," and yield hashes.
  # There shall be no "rewind," for one day our inputs may be streamed to us.
  # Also, why would you need to look at a thing twice? Make up your mind already.
  # So the interface is written, so shall it be.

  class CSVRepo
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
    # Class macro for defining the directory to expose.
    def self.directory(name=nil)
      return @directory if name.nil?
      @directory = name
    end

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

      path = "#{self.directory}/#{filename_str}.csv"

      path_exists = File.exists?(path)

      if name_str.end_with?('?')
        return path_exists
      end

      if path_exists
        return @files[name] = CSVRepo.new(CSV.open(path, headers: true))
      end

      super
    end
  end

  class DiscoveryIndex < CSVDirectoryIndex
    directory './mruby-bindings.out/discovery'
  end

  class SummaryIndex < CSVDirectoryIndex
    directory './mruby-bindings.out/summary'
  end
end
