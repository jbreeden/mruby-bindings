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

  Dir['specs/*.rb'].reject { |f| File.basename(f) == 'specs/fixture.rb' }.each do |test_file|
    test = File.basename(test_file).sub(/\.rb$/, '')
    desc "Run the #{test} tests"
    task (File.basename(test_file).sub(/\.rb$/, '')) do
      IO.popen("../../mruby/bin/mruby", 'w') do |mruby|
        File.open('specs/fixture.rb', 'r') do |fixture|
          fixture.each_line do |line|
            mruby.puts line
          end
        end
        File.open("specs/#{test}.rb", 'r') do |test|
          test.each_line do |line|
            mruby.puts line
          end
        end
      end
    end
  end

  task :all do
    IO.popen("../../mruby/bin/mruby", 'w') do |mruby|
      File.open('specs/fixture.rb', 'r') do |fixture|
        fixture.each_line do |line|
          mruby.puts line
        end
      end
      Dir['specs/*.rb'].reject { |f| File.basename(f) == 'specs/fixture.rb' }.each do |f|
        File.open(f, 'r') do |test|
          test.each_line do |line|
            mruby.puts line
          end
        end
      end
    end
  end

end
