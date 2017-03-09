# Mruby::Bindings

WARNING: This project lacks documentation, useful help commands, maturity, and a respectable maintainer.

If you're not the type of person to let little things like that stop you,
then it might help you generate some bindings to your favorite C libraries for use from MRuby.

## Usage

First, install [clang2json](http://github.com/jbreeden/clang2json).
Use this tool to extract type declarations from your C library into a
line delimited json file.

```bash
# Something like this should do the trick...

# I assume you have a folder to hold your new gem,
# lets go to it.
cd your/project/folder

# Clear any old contents before we start appending new stuff
[ -f declarations.json ] && rm declarations.json

# Then run clang2json on your *.h or *.c files
# Note: mruby-bindings is hardcoded to look for
#       a file named "declarations.json" at the
#       moment.
find your/c/library -name '*.h' | xargs -n 1 clang2json >> declarations.json
```

Next, you'll have to create one input file that tells mruby-bindings how to behave.
Call it `./mruby-bindings.in/hooks.rb`, and add the following code:

```
module MRuby
  module Bindings
    module Hooks
      def self.module_name
        # All of the classes & methods for your library
        # will be generated under a Ruby module with this name.
        "SomeValidRubyModuleName"
      end

      def self.gem_name
        # Your desired gem name.
        # The convention is for them to
        # start with "mruby" and be hyphen-separated.
        "mruby-gem-name"
      end
    end
  end
end
```

Then, you'll run mruby-bindings, which will look for
declarations.json in your current working directory,
and use that to generate your bindings.

```bash
jbreeden@jbreeden-eos-ssd:~/projects/mruby.d/mruby-ui$ mruby-bindings main
SPAWNING: ingest-declarations
DONE: ingest-declarations
...(more output)...
SPAWNING: write-gem
DONE: write-gem
SPAWNING: pull-generated
DONE: pull-generated
```

This should create a directory called `./mruby-bindings.out/`. This directory
just holder intermediate results. The finalized gem files should be pulled
into `./src`, `./include`, `./mrbgem`. You should also find an `mrbgem.rake`
file in your project's root folder.

From here, you should be able to build your gem just like any other mrbgem.
Though, realistically, you'll probably have to do some minor modifications first.
Even so, most of the code you will need to complete bindings to your C library
should be there for you.

## Other Stuff

After the initial run, the only files that should be overwitten by subsequent
invocations should be those whose parent directory is named "generated." All
other files, including the "main" C file (in `./src`) and the `mrbgem.rake`
file should be untouched, so you can keep any changes you make there.

If you feel you need to change something inside one of the "generated" files,
then that's a shortcoming of this tool (and please feel free to submit a feature
request). The aim is to allow all necessary overrides to be done without modifying
those sources. Sometimes these overrides will be done in your `./mruby-bindings.in/hooks.rb`
file. Other times it will be done by adding your own C code (perhaps to declare a
supertype for one of the generated classes), and the generated code should detect the
customization and behave appropriately (in this case, by not trying to re-declare the type
with no supertype).

Note: You can safely delete `mruby-bindings.out/` if you're not actively running
mruby-bindings. It's contents are created anew for each run.
