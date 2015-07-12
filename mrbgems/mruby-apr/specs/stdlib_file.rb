TestFixture.new('Ruby API: File') do
  empty_file = "#{$GEM_DIR}/sandbox/empty_file.txt"
  two_line_file = "#{$GEM_DIR}/sandbox/two_line_file.txt"
  file_for_writing = "#{$GEM_DIR}/sandbox/file_for_writing.txt"

  describe 'File::open(filename, mode="r" [, &block])' do
    it 'Returns an open File object, if filename exists' do
      f = File.open(two_line_file)
      assert(f.class == File)
      assert(!f.closed?)
    end

    it 'Raises a SystemCallError if filename does not exist' do
      assert_raises(SystemCallError) do
        File.open('this_path_doesnt_exist')
      end
    end

    it 'If given a block, it is passed the File, and the File is automatically closed when the block terminates' do
      file = nil
      File.open(two_line_file) do |f|
        file = f
        break
      end
      assert(file.closed?)
    end
  end

  describe 'File#puts(obj, ...)' do
    it "Writes the given objects to the File, appending the field separator ($\\) between each item" do
      orig_out_sep = $\
      orig_in_sep = $/
      File.open(file_for_writing, 'w') do |f|
        f.puts 'test'
        $\ = 'END'
        f.puts 'test2'
      end
      read = []
      File.open(file_for_writing, 'r') do |f|
        read.push f.gets
        $/ = 'END'
        read.push f.gets
      end
      $\ = orig_out_sep
      $/ = orig_in_sep
      assert(read[0] == "test\n" && read[1] == "test2END")
    end

    it 'Raises an IOError if the file is not open for writing' do
      assert_raises(IOError) do
        File.open(file_for_writing) do |f|
          f.puts 'test'
        end
      end
    end

    it 'Appends to the file if opened with mode="a"' do
      File.open(file_for_writing, 'w') do |f|
        f.puts 'one line'
        f.puts 'two lines'
      end
      File.open(file_for_writing, 'a') do |f|
        f.puts 'three lines'
      end
      line_count = 0
      File.open(file_for_writing) do |f|
        until f.gets.nil?
          line_count += 1
        end
      end
      assert(line_count == 3)
    end

    it 'Does not append a record separator after any args that already end with a record separator sequence' do
      line = "line with newline \n"
      File.open(file_for_writing, 'w') do |f|
        f.puts line
      end
      read = nil
      File.open(file_for_writing) do |f|
        orig_in_sep = $/
        # Change the input sep so we don't accidentally stop reading
        # before an erroneous double newline, breaking the test
        $/ = "\t"
        read = f.gets(100)
        $/ = orig_in_sep
      end
      assert(read == line)
    end

    it 'If called with any array arguments, flattens the arrays and writes each element on a new line' do
      File.open(file_for_writing ,'w') do |f|
        f.puts [1, 2, [3, 4, [5, 6], 7], 8, [9, 10]], 11, 12, [13, [14, 15]]
      end
      line_count = 0
      File.open(file_for_writing) do |f|
        until f.gets.nil?
          line_count += 1
        end
      end
      assert(line_count == 15)
    end

    it 'If called without arguments, outputs a single record separator' do
      File.open(file_for_writing ,'w') do |f|
        f.puts
      end
      read = nil
      File.open(file_for_writing) do |f|
        orig_in_sep = $/
        $/ = "DNE"
        read = f.gets(100)
        $/ = orig_in_sep
      end
      assert(read == "\n")
    end
  end

  describe 'File#gets | gets(sep=$/) | gets(limit) | gets(sep, limit)' do
    it 'Reads until sep when called as `gets(sep=$/)` (the separator is included in the result)' do
      read = nil
      File.open(two_line_file) do |f|
        read = f.gets
      end
      assert(read == "This file has two lines.\n")
    end

    it 'Returns "" if limit is 0' do
      read = nil
      File.open(two_line_file) do |f|
        read = f.gets(0)
      end
      assert(read == "")
    end

    it 'Reads at most `limit` bytes when called as `gets(limit)`' do
      read = nil
      File.open(two_line_file) do |f|
        read = f.gets(4)
      end
      assert(read == "This")
    end

    it 'Reads at most `limit` bytes when called as `gets(sep, limit)`' do
      read = nil
      File.open(two_line_file) do |f|
        read = f.gets("\n", 4)
      end
      assert(read == "This")
    end

    it 'Raises an IOError if the stream isn\'t open for reading' do
      assert_raises(IOError) do
        File.open(two_line_file, 'a') do |f|
          read = f.gets
        end
      end
    end

    it 'Returns nil if called at end of file' do
      File.open(two_line_file) do |f|
        assert(f.gets != nil)
        assert(f.gets != nil)
        assert(f.gets.nil?)
      end
    end
  end

  describe 'File#read' do
    it 'Reads length bytes from the file' do
      read = nil
      File.open(two_line_file) do |f|
        read = f.read(4)
      end
      assert(read == 'This')
    end

    it 'If length is omitted or is nil, it reads until EOF' do
      read = nil
      File.open(two_line_file) do |f|
        read = f.read
      end
      assert(read == "This file has two lines.\nThis is the second line.\n")
    end

    it 'If length is provided, nil means it met EOF at beginning' do
      read = "definitely not nil yet"
      File.open(empty_file) do |f|
        read = f.read(10)
      end
      assert(read == nil)
    end

    it 'If length is provided, 1 to length-1 bytes string means it met EOF after reading the result' do
      read = nil
      File.open(two_line_file) do |f|
        read = f.read(1000)
      end
      assert(read.length < 1000)
    end

    it 'If length is provided, the length bytes string means it doesn’t meet EOF' do
      read = nil
      File.open(two_line_file) do |f|
        read = f.read(10)
      end
      assert(read.length == 10)
    end

    it 'If length is zero, it returns ""' do
      read = nil
      File.open(two_line_file) do |f|
        read = f.read(0)
      end
      assert(read == "")
    end

    it 'At end of file, it returns "" if length omitted or nil' do
      got_empty_str = false
      File.open(two_line_file) do |f|
        loop {
          read = f.read(nil)
          if read == ""
            got_empty_str = true
            break
          end
        }
      end
      assert(got_empty_str)
    end

    it 'Raises an IOError if the file isn\'t open for reading' do
      assert_raises(IOError) do
        File.open(two_line_file, 'a') do |f|
          f.read
        end
      end
    end
  end

  describe 'File#write' do
    it 'Writes the given string to the file' do
      File.open(file_for_writing, 'w') do |f|
        f.write('my message')
      end
      read = nil
      File.open(file_for_writing) do |f|
        read = f.read
      end
      assert (read == 'my message')
    end

    it 'If the argument is not a string, it will be converted to a string using to_s' do
      o = Object.new
      class << o
        def to_s
          "to_s result"
        end
      end

      File.open(file_for_writing, 'w') do |f|
        f.write(o)
      end
      read = nil
      File.open(file_for_writing) do |f|
        read = f.read
      end
      assert (read == 'to_s result')
    end

    it 'Returns the number of bytes written' do
      bytes_written = 0
      File.open(file_for_writing, 'w') do |f|
        bytes_written = f.write('1234')
      end
      assert(bytes_written == 4)
    end

    it 'Raises an IOError if the file isn\'t open for writing' do
      assert_raises(IOError) do
        File.open(two_line_file) do |f|
          f.write('my message')
        end
      end
    end
  end

  describe 'File#each(&block)' do
    it 'Executes the given block for each line in the file, passing in the line' do
      lines = []
      File.open(two_line_file) do |f|
        f.each do |l|
          lines.push l
        end
      end
      assert (lines[0] == "This file has two lines.\n" && lines[1] == "This is the second line.\n")
    end

    it 'Returns an Enumerator if no block is given' do
      f = nil
      begin
        f = File.open(two_line_file)
        result = f.each
        assert(result.class == Enumerator)
        assert(result.next == "This file has two lines.\n")
        assert(result.next == "This is the second line.\n")
      ensure
        f.close unless f.nil?
      end
    end
  end

  describe 'File#each_line(&block)' do
    it 'Is an alias for each' do
      lines = []
      File.open(two_line_file) do |f|
        f.each do |l|
          lines.push l
        end
      end
      assert (lines[0] == "This file has two lines.\n" && lines[1] == "This is the second line.\n")
    end
  end

  describe 'File#each_byte(&block)' do
    it 'Executes the given block for each character in the file' do
      bytes = []
      File.open(two_line_file) do |f|
        f.eof?
        f.each_byte do |b|
          bytes.push b
        end
      end
      assert(bytes[0] == 'T'.ord)
      assert(bytes[1] == 'h'.ord)
      # ... you get the idea
    end

    it 'Returns an Enumerator if no block is given' do
      f = nil
      begin
        f = File.open(two_line_file)
        result = f.each_byte
        assert(result.class == Enumerator)
        assert(result.next == "T".ord)
        assert(result.next == "h".ord)
      ensure
        f.close unless f.nil?
      end
    end
  end

  describe 'File#eof | eof?' do
    it 'Returns true if EOF has been hit, or else false' do
      f = nil
      begin
        f = File.open(two_line_file)
        assert(f.eof? == false)
        f.read
        assert(f.eof? == true)
      ensure
        f.close unless f.nil?
      end
    end

    it 'Returns true for an empty file, even if no reads have been performed yet' do
      f = nil
      begin
        f = File.open(empty_file)
        assert(f.eof? == true)
      ensure
        f.close unless f.nil?
      end
    end
  end

  describe 'File#getbyte' do
    it 'Returns the next character, or nil if at EOF' do
      first_byte = nil
      last_byte = 'not nil yet'
      File.open(two_line_file) do |f|
        first_byte = f.getbyte
        f.read # read full
        last_byte = f.getbyte
      end
      assert(first_byte == 'T'.ord && last_byte == nil)
    end
  end

  describe 'File#getc' do
    it 'Returns the next character, or nil if at EOF' do
      first_byte = nil
      last_byte = 'not nil yet'
      File.open(two_line_file) do |f|
        first_byte = f.getc
        f.read # read full
        last_byte = f.getc
      end
      assert(first_byte == 'T' && last_byte == nil)
    end
  end

  describe 'File#ungetbyte' do
    it 'Pushes back bytes onto a file buffer ' do
      read = []
      File.open(empty_file) do |f|
        # ungets in reverse order like CRuby.
        # Unlike CRuby implementation (but like the CRuby documentation)
        # only the last character will be read back
        f.ungetbyte 'abcde'
        read.push f.read
        f.ungetbyte 65 # 'A'
        read.push f.getc
      end
      assert(read[0] == 'a' && read[1] == 'A')
    end
  end

  describe 'File#ungetc' do
    it 'Pushes back bytes onto a file buffer ' do
      read = []
      File.open(empty_file) do |f|
        # ungets in reverse order like CRuby.
        # Unlike CRuby implementation (but like the CRuby documentation)
        # only the last character will be read back
        f.ungetbyte 'abcde'
        read.push f.read
        f.ungetbyte 65 # 'A'
        read.push f.getc
      end
      assert(read[0] == 'a' && read[1] == 'A')
    end
  end
end
