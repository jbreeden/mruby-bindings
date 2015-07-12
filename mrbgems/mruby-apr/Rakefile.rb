# Util Functions
# --------------

def each_test_file(&block)
  Dir['specs/*.rb'].reject { |f| File.basename(f) == 'fixture.rb' }.each(&block)
end

def test_file_name(test_file)
  File.basename(test_file).sub(/\.rb$/, '')
end

def with_mruby(&block)
  IO.popen("../../mruby/bin/mruby", 'w', &block)
end

def exec_file(mruby, path)
  File.open(path, 'r') do |test|
    mruby.puts "$GEM_DIR = '#{File.expand_path('.')}'"
    test.each_line do |line|
      mruby.puts line
    end
  end
end

# Tasks
# -----

desc "Print the supported functions"
task "tell_functions" do
  File.open('include/mruby_APR.h', 'r') do |f|
    regex = /BIND_(.*)_FUNCTION TRUE/
    f.each_line do |l|
      puts l[regex, 1] if l =~ regex
    end
  end
end

namespace :test do

  each_test_file do |test_file|
    test = test_file_name(test_file)
    desc "Run the #{test} tests"
    task (test) do
      with_mruby do |mruby|
        exec_file(mruby, 'specs/fixture.rb')
        exec_file(mruby, test_file)
      end
    end
  end

  desc "Run all of the tests"
  task :all do
    with_mruby do |mruby|
      exec_file(mruby, 'specs/fixture.rb')
      Dir['specs/*.rb'].reject { |f| File.basename(f) == 'specs/fixture.rb' }.each do |f|
        exec_file(mruby, f)
      end
    end
  end

end
