module MRubyBindings
module Commands
module Init
  USAGE = <<EOS
Usage: mrbind init -m MODULE_NAME -g GEM_NAME
EOS
  def self.run
    yargs = Yargs.new(ARGV, :consume)
    conf = {}
    conf[:module_name] = yargs.value(:m, :module)
    conf[:gem_name] = yargs.value(:g, :gem)
    
    unless conf[:module_name]
      bail("Must specify module name: `-m MODULE_NAME`", USAGE)
    end
    
    unless conf[:gem_name]
      bail("Must specify gem name: `-g GEM_NAME`", USAGE)
    end
    
    erb = ERB.new(File.read("#{MRubyBindings::TEMPLATE_DIR}/mruby-bindings.rake.erb"), nil, '-')
    
    did_something = false
    unless Dir.exists?('rakelib')
      puts "Creating rakelib folder"
      Dir.mkdir('rakelib')
      did_something = true
    end
    unless File.exists?('rakelib/mruby-bindings.rake')
      puts "Writing rakelib/mruby-bindings.rake"
      File.open('rakelib/mruby-bindings.rake', 'w') do |f|
        f.write(erb.result(binding))
      end
      did_something = true
    end
    unless Dir['Rakefile*'].length > 0
      puts "Creating empty Rakefile"
      File.open('Rakefile.rb', 'w') {}
      did_something = true
    end
    
    unless did_something
      puts "Already initialized"
    end
  end
end
end
end
