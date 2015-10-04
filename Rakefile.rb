$apr_dir = File.expand_path "headers/apr"
$sqlite_dir = File.expand_path "headers/sqlite3"

def generate_bindings(gem_name, module_name, output_dir)
  IO.popen("ruby mruby_bindings.rb -f -g #{gem_name} -m #{module_name} -o #{output_dir}", 'w') do |io|
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
      Dir["/usr/local/apr/include/apr-1/*.h"].each do |header|
        sh "clang2json -x c++ -I #{$apr_dir} -I #{$apr_dir}/win #{header} >> declarations.json"
      end
    end
  end

  desc "Generate ldjson file for SQLite headers"
  task :sqlite do
    File.delete "declarations.json" if File.exists? 'declarations.json'
    sh "clang2json -I #{$sqlite_dir} #{$sqlite_dir}/sqlite3.h >> declarations.json"
  end
end

namespace :bindings do
  desc "Generates bindings for APR"
  task :apr => ['scrape:apr'] do
    generate_bindings('mruby-apr', 'APR', 'apr_bindings')
  end

  desc "Generates bindings for nspr"
  task :sqlite => ['scrape:sqlite'] do
    generate_bindings('mruby-sqlite3', 'SQLite', 'sqlite_bindings')
  end
end
