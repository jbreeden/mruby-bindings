module MRubyBindings
  def self.type_name_to_id(type)
    type.sub(/\s*(struct|enum)\s*/, '').
      sub(/\s*const\s*/, '').
      gsub(/\*|&|\(|\)|,|(::)/,
        '*' => ' PTR ',
        '&' => ' REF ',
        '(' => ' LPAREN ', ')' => ' RPAREN ',
        ',' => 'COMMA',
        '::' => '_'
      ).
      split(/\s+/).
      join('_')
  end
  
  def self.type_name_to_rb_class(type)
    type.sub(/(struct|enum)\s*/, '').
      split('_').
      map { |token| "#{token[0].upcase if token.length > 0}#{token[1..(token.length)] if token.length > 1}" }.
      join('')
  end
  
  # Just makes the first character of each `_` separated token is captialized
  def self.to_rb_const(name)
    case_corrected = name.split('_').map { |token| 
      if token.nil? || token.length == 0
        ''
      else
        token[0].upcase + token[1..(token.length)] 
      end
    }.join('_')
    
    case_corrected.sub(/^[^a-zA-Z]+/, '')
  end
end
