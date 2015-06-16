MRuby::Build.new('host') do |conf|
  # Gets set by the VS command prompts.
  if ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR']
    toolchain :visualcpp
  else
    toolchain :gcc
  end

  conf.gembox "full-core"

  conf.gem "../mrbgems/mruby-apr"
  configure_mruby_apr(conf)

  if ENV['DEBUG'] && (ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR'])
    conf.cc.flags << "/DEBUG"
    conf.cxx.flags << "/DEBUG"
  end

end
