# Mruby::Bindings

Intended to generate mruby bindings to C libraries.

WARNING: This project is still experimental, and unstable. If you're coming here from some of the projects generated with this tool (like mruby-apr), you'll find that mruby-bindings has since been rewritten, and so the API is very different now. There are still some significant defects that mean you probably shouldn't use it for anything serious. I intend to start versioning the project once I think it's usable and stable. Until then... feel free to look around, open issues, or make pull requests.

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
# Note: mruby-bindings looks for a file named
#       "declarations.json" by default, so the
#       name is significant.
find your/c/library -name '*.h' | xargs -n 1 clang2json >> declarations.json
```

Next, you'll have to create one input file that tells mruby-bindings how to behave.
Call it `./mruby-bindings.in/hooks.rb`, and add the following code:

```ruby
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

      # See: ./lib/mruby/bindings/hooks.rb for other
      #      settings that you can override in this file.
    end
  end
end
```

Then, you'll run mruby-bindings, which will look for
declarations.json in your current working directory,
and use that to generate your bindings.

```bash
your/project/folder$ mruby-bindings main
SPAWNING: ingest-declarations
DONE: ingest-declarations
...(more output)...
SPAWNING: write-gem
DONE: write-gem
SPAWNING: pull-generated
DONE: pull-generated
```

This should create a directory called `./mruby-bindings.out/`. This directory
just holds intermediate results. The finalized gem files should be pulled
into `./src`, `./include`, `./mrbgem`. You should also find an `mrbgem.rake`
file in your project's root folder.

From here, you should be able to build your gem just like any other mrbgem.
Though, realistically, you'll probably have to do some minor modifications first.
Even so, most of the code you will need to complete bindings to your C library
should be there for you.

## More Details

After the initial run, the only files that should be overwitten by subsequent
invocations should be those whose parent directory is named "generated." All
other files, including the "main" C file (`./src/mruby_MODULENAME.c`) and the `mrbgem.rake`
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

## Code Layout

If you're having to dive into the code, here are some things to know:

- The installed executable is `./exe/mruby-bindings`
- The `mruby-bindings` command just delegates to
  scripts in the `plumbing/` directory. To run `plumbing/main`,
  you would run `mruby-bindings main`. You can run multiple
  commands by passing multiple arguments to `mruby-bindings`.
- The plumbing scripts are meant to be small and focused.
  The do not talk to each other directly, but rather read
  and write intermediate results as CSV, JSON, or YAML.
- These intermediate results are never changed once written, as a rule.
  If you needed to add extra plumbing, you should be able to use the
  intermediate results of a prior command without worrying about it
  being modified.
- The core logic is of course in `lib/`
- The `templates/` folder holds - gasp! - templates.
  If you really want to change the way functions are generated,
  or how classes are defined, you could edit these.
