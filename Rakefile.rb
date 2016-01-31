load 'lib/mruby_bindings/version.rb'

desc 'Build the gem'
task :build do
  sh 'gem build ./mruby-bindings.gemspec'  
end

desc 'Install the gem'
task :install => :build do
  sh "gem install ./mruby-bindings-#{MRubyBindings::VERSION}.gem"
end
