class TestFixture

  def initialize(&block)
    @test_count = 0
    @fail_count = 0
    self.instance_eval(&block)
    summarize
  end

  def describe(label, &block)
    puts
    puts label
    self.instance_eval(&block)
  end

  def it(label, &block)
    exc = nil
    passed = begin
      self.instance_eval(&block)
    rescue StandardError => ex
      exc = ex
      false
    end
    puts " - #{"[FAILED]" unless passed} #{label}"

    @test_count += 1
    @fail_count += 1 unless passed

    if exc
      puts "Uncaught exception: #{exc}"
      puts "Backtrace:"
      exc.backtrace.each do |sf|
        puts "  #{sf}"
      end
    end
  end

  def summarize
    puts "-----------------"
    puts "#{@test_count - @fail_count}/#{@test_count} tests passed"
    puts
    if @fail_count == 0
      puts "Success!"
    else
      puts "Failure"
    end
  end
end

TestFixture.new do
  APR::apr_initialize
  err, @pool = APR::apr_pool_create nil

  describe 'APR::apr_file_create' do
    it 'Opens a file' do
      err, file = APR.apr_file_open 'test2.txt', APR::APR_FOPEN_CREATE | APR::APR_FOPEN_WRITE, 0, @pool
      (err == 0) && file.kind_of?(APR::AprFileT)
    end
  end
end
