module MRuby::Bindings
  class RenderedText
    attr_accessor :id, :body
    def initialize(id, body)
      @id = id
      @body = body
    end
  end
end
