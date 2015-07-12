TestFixture.new('Ruby API: IO') do
  describe 'IO.pipe' do
    it 'Creates a pair of File objects to be used as the read & write ends of the pipe' do
      r, w = IO.pipe
      w.write('my message')
      msg = r.read(10)
      assert(msg == 'my message')
    end
  end
end
