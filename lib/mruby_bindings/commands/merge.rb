module MRubyBindings
module Commands
module Merge
  USAGE = <<EOS
Usage: mrbind merge --from FROM_DIR --to TO_DIR [FOLDER...]

Merges the generated bindings from FROM_DIR into the files in TO_DIR.
Rather than just copying over the existing files, this command preserves
the current version of any functions that have been modified by hand.


EOS

  def self.run
    conf = {}
    yargs = Yargs.new(ARGV, :consume)
    conf[:from] = yargs.value(:from)
    conf[:to] = yargs.value(:to)
    
    unless conf[:from]
      bail("Must specify `from` option: `--from GENERATOR_OUTPUT_DIR`", USAGE)
    end
    
    unless conf[:to]
      bail("Must specify `to` option: `--from GENERATOR_OUTPUT_DIR`", USAGE)
    end
    
    folders = ARGV.length == 0 ? ['src', 'mrblib', 'include'] : ARGV
    MRubyBindings::Merge.new(conf).run(folders)
  end
end
end
end
