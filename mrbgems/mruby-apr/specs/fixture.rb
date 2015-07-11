class TestFixture

  def initialize(label, &block)
    @fixture_label = label
    @test_count = 0
    @fail_count = 0
    @current_test_pased = true
    puts
    puts @fixture_label
    puts '-' * label.size
    self.instance_eval(&block)
    summarize
  end

  def describe(label, &block)
    puts
    puts "  #{label}"
    self.instance_eval(&block)
  end

  def it(label, &block)
    @current_test_pased = true
    exc = nil
    begin
      self.instance_eval(&block)
    rescue StandardError => ex
      exc = ex
      @current_test_pased = false
    end
    puts "   - #{"[FAILED]" unless @current_test_pased} #{label}"

    @test_count += 1
    @fail_count += 1 unless @current_test_pased

    if exc
      puts "    Uncaught #{exc.class.to_s}: #{exc}"
    end
  end

  def assert(condition)
    @current_test_pased &&= condition
    condition # So client can react to result
  end

  def summarize
    puts
    puts "  #{@fail_count == 0 ? 'SUCCESS' : 'FAILURE' } [#{@test_count - @fail_count}/#{@test_count} tests passed]"
  end
end
