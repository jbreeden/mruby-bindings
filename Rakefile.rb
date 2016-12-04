task :ctags do
  sh "ctags -R $(find . -name '*.rb')"
end
