$apr_dir = File.expand_path "headers/apr"
$cef_dir = File.expand_path "headers/cef"
$nn_dir = File.expand_path "headers/nanomsg"

def generate_bindings(gem_name, module_name, output_dir)
  IO.popen("ruby mruby_bindings.rb #{gem_name} #{module_name} #{output_dir}", 'w') do |io|
    File.open('declarations.json', 'r') do |file|
      while line = file.gets
        io.puts line
      end
    end
  end
end

namespace :scrape do
  desc "Generate ldjson file for apr headers"
  task :apr do
    File.delete "declarations.json" if File.exists? 'declarations.json'
    Dir["#{$apr_dir}/*.h"].concat(["#{$apr_dir}/win/apr.h"]).each do |header|
      sh "\"clang2json.exe\" -x c++ -I #{$apr_dir} -I #{$apr_dir}/win #{header} >> declarations.json"
    end
  end

  desc "Generate ldjson file for cef headers"
  task :cef do
    File.delete "declarations.json" if File.exists? 'declarations.json'
    Dir["#{$cef_dir}/*.h"].each do |header|
      sh "\"clang2json.exe\" -x c++ -I #{$cef_dir}  #{header} >> declarations.json"
    end
  end

  desc "Generate ldjson file for nanomsg headers"
  task :nanomsg do
    File.delete "declarations.json" if File.exists? 'declarations.json'
    Dir["#{$nn_dir}/**/*.h"].each do |header|
      sh "\"clang2json.exe\" -x c++ -I #{$nn_dir} #{header} >> declarations.json"
    end
  end
end

namespace :bindings do
  desc "Generates bindings for APR"
  task :apr => ['scrape:apr'] do
    generate_bindings('mruby-apr', 'APR', 'apr_bindings')
  end

  desc "Generates bindings for CEF"
  task :cef => ['scrape:cef'] do
    generate_bindings('mruby-cef', 'Cef', 'cef_bindings')
  end

  desc "Generates bindings for nanomsg"
  task :nanomsg => ['scrape:nanomsg'] do
    generate_bindings('mruby-nanomsg', 'NN', 'nanomsg_bindings')
  end
end

namespace :mruby do
  desc "Build the mruby bundled with lamina"
  task :build do
    Dir.chdir "mruby-1.1.0" do
      sh "ruby minirake"
    end

    # Hack:
    # Something is going wrong in mruby build process...
    # Not getting the .exe extensions for executables.
    # I'll try to fix this later
    if ENV['OS'] =~ /windows/i
      Dir.chdir "mruby-1.1.0/bin" do
        mv 'mirb', 'mirb.exe'
        mv 'mruby', 'mruby.exe'
        mv 'mrbc', 'mrbc.exe'
        mv 'mruby-strip', 'mruby-strip.exe'
      end
    end
  end

  desc "Clean the mruby bundled with lamina"
  task :clean do
    Dir.chdir "mruby-1.1.0" do
      sh "ruby minirake clean"
    end
  end
end
