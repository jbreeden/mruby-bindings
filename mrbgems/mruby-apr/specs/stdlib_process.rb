TestFixture.new('Standard Lib: Process') do
  describe 'Process::spawn' do
    it 'Spawns a shell command if given a string' do
      pid = Process.spawn 'ruby -e "exit 1"'
      Process.wait(pid)
      assert($?.exitstatus == 1)
    end

    it 'Spawns a program, with no shell, if given argv as multiple args' do
      # This will fail, since without the shell "ruby" should be specified as the full path "/usr/bin/ruby"
      pid = Process.spawn 'ruby', '-e', '"exit 0"'
      Process.wait(pid)
      assert($?.exitstatus != 0)
    end
  end
end
