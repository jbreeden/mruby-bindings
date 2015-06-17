
namespace :test do

  Dir['specs/*.rb'].reject { |f| File.basename(f) == 'specs/fixture.rb' }.each do |test_file|
    test = File.basename(test_file).sub(/\.rb$/, '')
    desc "Run the #{test} tests"
    task (File.basename(test_file).sub(/\.rb$/, '')) do
      IO.popen("../../mruby-1.1.0/bin/mruby.exe", 'w') do |mruby|
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
    IO.popen("../../mruby-1.1.0/bin/mruby.exe", 'w') do |mruby|
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
