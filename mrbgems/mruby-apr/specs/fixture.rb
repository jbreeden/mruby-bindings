class TestFixture

  def initialize(label, &block)
    @fixture_label = label
    @test_count = 0
    @fail_count = 0
    @current_test_passed = true
    @current_test_pending = false
    puts
    puts @fixture_label
    puts '-' * label.size
    self.instance_eval(&block)
    summarize
  end

  def describe(label, &block)
    puts
    puts "  - #{label}"
    self.instance_eval(&block)
  end

  def it(label, &block)
    @current_test_passed = true
    @current_test_pending = false
    exc = nil
    begin
      self.instance_eval(&block)
    rescue StandardError => ex
      exc = ex
      @current_test_passed = false
    end
    tag = ""
    if @current_test_pending
      tag = "[PENDING] "
    elsif !@current_test_passed
      tag = "[FAILED] "
    end
    puts "    + #{tag}#{label}"

    @test_count += 1
    @fail_count += 1 unless @current_test_passed

    if exc
      puts "    Uncaught #{exc.class.to_s}: #{exc}"
    end
  end

  def assert(condition)
    @current_test_passed &&= condition
    condition # So client can react to result
  end

  def assert_raises(excClass, &block)
    begin
      block[]
    rescue excClass
      return
    end
    @current_test_passed = false
  end

  def fail
    @current_test_passed = false
  end

  def pending
    @current_test_pending = true
  end

  def summarize
    puts
    puts "  #{@fail_count == 0 ? 'SUCCESS' : 'FAILURE' } [#{@fail_count}/#{@test_count} tests failed]"
  end
end
