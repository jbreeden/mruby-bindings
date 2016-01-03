module MRubyBindings
  class BindingFile < File
    require 'digest'
    
    def initialize(*args, &block)
      super
      @put_back = nil
      @digest = Digest::SHA2.new
      @bindings = {}
      @recorded_shas = {}
      @actual_shas = {}
      analyze
    end
    
    def analyze
      while line = self.gets
        if fn = line[START_BINDING_PATTERN, 1]
          next_line = self.gets
          sha = (next_line || '')[BINDING_SHA_PATTERN, 1]
          # If no sha line, put back the line for digestion
          put_back(next_line) if next_line && sha.nil?
          @recorded_shas[fn] = sha
          actual_sha, content = digest_binding
          @actual_shas[fn] = actual_sha
          @bindings[fn] = content
        end
      end
      self.rewind
    end
    
    def gets
      if @put_back
        result = @put_back
        @put_back = nil
        result
      else
        super
      end
    end
    
    def has_binding?(name)
      !!@bindings[name]
    end
    
    def binding_edited?(binding_name)
      @recorded_shas[binding_name] != @actual_shas[binding_name]
    end
    
    def recorded_sha(binding_name)
      @recorded_shas[binding_name]
    end
    
    def actual_sha(binding_name)
      @actual_shas[binding_name]
    end
    
    def binding_content(binding_name)
      @bindings[binding_name]
    end
    
    def digest_binding
      digest_until(END_BINDING_PATTERN)
    end
    
    def digest_until(pattern)
      contents = read_until(pattern)
      sha = @digest.hexdigest(contents.gsub(/\n|\r|\s/, ''))
      [sha, contents]
    end
    
    def read_to_binding_end
      read_until(END_BINDING_PATTERN)
    end
    
    def read_until(pattern)
      contents = ''
      while (line = self.gets) && !(pattern =~ line)
        contents << line
      end
      put_back(line) unless line.nil?
      contents
    end
    
    def put_back(line)
      @put_back = line
    end
  end
end
