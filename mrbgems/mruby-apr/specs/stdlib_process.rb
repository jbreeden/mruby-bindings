TestFixture.new('Standard Lib: Process') do
  describe 'Process::spawn' do
    it 'Spawns a shell command if given a string' do
      pid = Process.spawn 'ruby -e "exit 1"'
      Process.wait(pid)
      puts $?.inspect
      assert($?.exitstatus == 1)
    end

    it 'Spawns a program, with no shell, if given argv as multiple args' do
      pid = Process.spawn 'ruby', '-e', '"exit 0"'
      Process.wait(pid)
      puts $?.inspect
    end
  end
end
