$NANOMSG_GEM_DIR = File.dirname(__FILE__)

def configure_mruby_nanomsg_win(conf)
  # Pre-built libraries are held under "#{$NANOMSG_GEM_DIR}/lib/PLATFORM"
  conf.linker.library_paths << "#{$NANOMSG_GEM_DIR}/lib/win"

  # I've appended the selected C runtime nanomsg was built with onto the lib file name
  conf.linker.libraries << "nanomsg_md"
  conf.linker.libraries << "Rpcrt4"
  conf.linker.libraries << "Mswsock"
end

def configure_mruby_nanomsg_lin(conf)
  conf.linker.flags_before_libraries << '/usr/local/lib/libnanomsg.a'
  conf.linker.libraries << 'anl'
end


def configure_mruby_nanomsg(conf)
  # Common include path (all platforms)
  conf.cc.include_paths << "#{$NANOMSG_GEM_DIR}/include/nanomsg"
  conf.cxx.include_paths << "#{$NANOMSG_GEM_DIR}/include/nanomsg"

  # Building against the static nanomsg library requires
  # defining NN_NOEXPORTS to prevent the use of __declspec(dllimport)
  # in the header files
  conf.cc.defines << "NN_NO_EXPORTS"
  conf.cxx.defines << "NN_NO_EXPORTS"

  if ENV['OS'] =~ /windows/i
    configure_mruby_nanomsg_win(conf)
  else
    configure_mruby_nanomsg_lin(conf)
  end
end

MRuby::Gem::Specification.new('mruby-nanomsg') do |spec|
  spec.license = 'MIT'
  spec.author  = 'Jared Breeden'
  spec.summary = 'Bindings to the nanomsg library'
end
