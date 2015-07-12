# TODO:
# Most of the configuration here should be done on the gem spec,
# not on the global conf object.

$APR_GEM_DIR = File.dirname(__FILE__)

def configure_mruby_apr_win(conf)
  # apr.h is generated specially for each platform when building APR
  # I'm putting these generated headers into "#{$APR_GEM_DIR}/include/apr/PLATFORM"
  # (In this case, PLATFORM == win)
  conf.cc.include_paths << "#{$APR_GEM_DIR}/include/apr/win"
  conf.cxx.include_paths << "#{$APR_GEM_DIR}/include/apr/win"

  # Pre-built libraries are held under "#{$APR_GEM_DIR}/lib/PLATFORM"
  conf.linker.library_paths << "#{$APR_GEM_DIR}/lib/win"

  # I've appended the selected C runtime APR was built with onto the lib file name
  conf.linker.libraries << "apr-1_md"
  conf.linker.libraries << "Ws2_32"
  conf.linker.libraries << "Advapi32"
  conf.linker.libraries << "Shell32"
  conf.linker.libraries << "Mswsock"
end

def configure_mruby_apr_lin(conf)
  unless Dir.exists? '/usr/local/apr'
    puts 'Expected to find APR installed in /usr/local.'
    puts 'To install APR, download the source and run `configure && make && sudo make install`'
    raise 'APR not installed'
  end
  apr_include_dir = `/usr/local/apr/bin/apr-1-config --includes`.sub('-I', '').strip
  conf.cc.include_paths << apr_include_dir
  conf.cxx.include_paths << apr_include_dir
  conf.linker.library_paths << '/usr/local/apr/lib'
  conf.linker.libraries = conf.linker.libraries.concat `/usr/local/apr/bin/apr-1-config --libs`.
    split(' ').
    map { |flag|
      flag.gsub(/^-l/, '').strip
    }
  conf.linker.libraries << "iconv"
  conf.linker.flags_before_libraries << '/usr/local/apr/lib/libapr-1.a'
end

def configure_mruby_apr(conf)

  # Common include path (all platforms)
  conf.cc.include_paths << "#{$APR_GEM_DIR}/include/apr"
  conf.cxx.include_paths << "#{$APR_GEM_DIR}/include/apr"

  # This gem is only setup to build with the static apr lib.
  # To use the static lib, you need to declare this preprocessor macro.
  conf.cc.defines << "APR_DECLARE_STATIC"
  conf.cxx.defines << "APR_DECLARE_STATIC"

  if ENV['OS'] =~ /windows/i
    configure_mruby_apr_win(conf)
  else
    configure_mruby_apr_lin(conf)
  end
end

MRuby::Gem::Specification.new('mruby-apr') do |spec|
  spec.license = 'Apache Version 2'
  spec.author  = 'Jared Breeden'
  spec.summary = 'Bindings to the APR libraries'

  spec.cc.flags << [ '-std=c11' ]
  spec.cxx.flags << [ '-std=c++11' ]
  # TODO: Add dependency on mruby-regexp-pcre (or compatible)
  # TODO: Add dependency on mruby-errno
end
