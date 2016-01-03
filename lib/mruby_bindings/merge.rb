module MRubyBindings
class Merge
  attr_reader :conf

  def initialize(conf)
    @conf = conf
  end
  
  def run(folders=['src','include','mrblib'])
    Dir.mktmpdir do |tmpdir|
      Dir.mkdir('include') unless Dir.exists?('include')
      Dir.mkdir('src') unless Dir.exists?('src')
      Dir.mkdir('mrblib') unless Dir.exists?('mrblib')
      
      Dir["#{conf[:from]}/{#{folders.join(',')}}/*"].each do |src|
        target = src.sub(conf[:from], conf[:to])
        if File.exists?(target)
          pull_existing_file(src, target, tmpdir)
        else
          pull_new_file(src, target)
        end
      end
      
      unless File.exists?("#{conf[:to]}/mrbgem.rake")
        File.open("#{conf[:to]}/mrbgem.rake", 'w') do |f|
          f.write(File.read("#{conf[:from]}/mrbgem.rake"))
        end
      end
    end
  end
  
  def pull_existing_file(source, target, tmpdir)
    ifile = BindingFile.open(source, 'r')
    FileUtils.cp(target, "#{tmpdir}/#{File.basename(target)}")
    prev = BindingFile.open("#{tmpdir}/#{File.basename(target)}", 'r')
    ofile = File.open(target, 'w')
    while line = ifile.gets
      if (binding_name = line[START_BINDING_PATTERN, 1])
        if prev.has_binding?(binding_name) && prev.binding_edited?(binding_name)
          ofile.puts(line)
          ofile.puts("/* sha: #{prev.recorded_sha(binding_name)} */")
          ofile.puts(prev.binding_content(binding_name))
          ifile.read_to_binding_end
        else
          sha, content = ifile.digest_binding
          ofile.puts(line)
          ofile.puts("/* sha: #{sha} */")
          ofile.puts(content)
        end
      else
        ofile.puts(line)
      end
    end
    ifile.close
    prev.close
    ofile.close
  end
  
  def pull_new_file(source, target)
    ifile = BindingFile.open(source, 'r')
    ofile = File.open(target, 'w')
    while line = ifile.gets
      if START_BINDING_PATTERN =~ line
        sha, content = ifile.digest_binding
        ofile.puts(line)
        ofile.puts("/* sha: #{sha} */")
        ofile.puts(content)
      else
        ofile.puts(line)
      end
    end
    ifile.close
    ofile.close
  end
end
end
