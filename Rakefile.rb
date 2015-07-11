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
    puts $apr_dir
    File.delete "declarations.json" if File.exists? 'declarations.json'
    if ENV['OS'] =~ /windows/i
      apr_h =  "#{$apr_dir}/win/apr.h"
      Dir["#{$apr_dir}/*.h"].concat([apr_h]).each do |header|
        sh "clang2json -x c++ -I #{$apr_dir} -I #{$apr_dir}/win #{header} >> declarations.json"
      end
    else
      Dir["/usr/local/apr/include/apr-2/*.h"].each do |header|
        sh "clang2json -x c++ -I #{$apr_dir} -I #{$apr_dir}/win #{header} >> declarations.json"
      end
    end
  end

  desc "Generate ldjson file for cef headers"
  task :cef do
    File.delete "declarations.json" if File.exists? 'declarations.json'
    Dir["#{$cef_dir}/*.h"].each do |header|
      sh "clang2json -x c++ -I #{$cef_dir}  #{header} >> declarations.json"
    end
  end

  desc "Generate ldjson file for nanomsg headers"
  task :nanomsg do
    File.delete "declarations.json" if File.exists? 'declarations.json'
    Dir["#{$nn_dir}/*.h"].each do |header|
      sh "clang2json -x c++ -I #{$nn_dir} #{header} >> declarations.json"
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
    Dir.chdir "mruby" do
      sh "ruby minirake"
    end
  end

  desc "Clean the mruby bundled with lamina"
  task :clean do
    Dir.chdir "mruby" do
      sh "ruby minirake clean"
    end
  end
end
