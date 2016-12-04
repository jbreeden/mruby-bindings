require 'csv'
require 'mruby/bindings'

module MRuby::Bindings
  class CSVDirectoryIndex
    def self.directory(name=nil)
      return @directory if name.nil?
      @directory = name
    end

    def initialize
      files = Dir[self.class.directory + '/*.csv']
      @lookup_tables = files.reduce({}) do |acc, cur|
        current_table = acc[File.basename(cur).sub('.csv', '')] = []
        CSV.foreach(cur, headers: true) do |row|
          current_table.push(row)
        end
        acc
      end
    end

    def method_missing(name)
      name_str = name.to_s
      hyphenated_name = name_str.sub('_', '-')
      if (name_str_minus_q = name_str[/(.*)\?$/, 1])
        @lookup_tables.has_key? name_str_minus_q
      elsif @lookup_tables.keys.include?(name_str)
        @lookup_tables[name_str] 
      elsif @lookup_tables.keys.include?(hyphenated_name)
        @lookup_tables[hyphenated_name] 
      else
        super
      end
    end
  end

  class DiscoveryIndex < CSVDirectoryIndex
    directory './mruby-bindings.out/discovery'
  end

  class SummaryIndex < CSVDirectoryIndex
    directory './mruby-bindings.out/summary'
  end
end
