File.open(ARGV[0]).each_line do |l|
  regex = /#define\s+([a-zA-Z_]+)\s/
  if l =~ regex
    macro_name = l[regex, 1];
    puts "mrb_define_const(mrb, APR_module(mrb), \"#{macro_name}\", mrb_fixnum_value(#{macro_name}));"
  end
end
