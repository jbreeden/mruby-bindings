TestFixture.new('Ruby API: Process') do
  file_for_writing = "#{$GEM_DIR}/sandbox/file_for_writing.txt"

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

    it 'Supports redirecting in, out, & err streams to/from a PipeFile\'s created by IO.pipe' do
      r, w = IO.pipe
      Process.spawn("echo my message", out: w)
      w.close # Close in parent so we can get EOF!
      msg = r.read
      assert (msg == "my message\n")
    end

    it 'Supports redirecting to ordinary file objects' do
      out_file = File.open(file_for_writing, 'w')
      pid = Process.spawn("echo my message", out: out_file)
      Process.wait(pid)
      out_file.close
      read = nil
      File.open(file_for_writing) do |f|
        read = f.read
      end
      assert(read == "my message\n")
    end
  end
end
