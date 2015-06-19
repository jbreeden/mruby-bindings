mruby-nanomsg
=============

Mruby bindings to nanomsg. A component of the [lamina project](https://github.com/jbreeden/lamina).

Uselessness Notice
------------------

This gem is virtually useless at the moment. It just provides compiler options to link nanomsg with mruby, which is used by [lamina](https://github.com/jbreeden/lamina).

As lamina development continues, actual bindings will probably be written.

Building
--------

Includes a pre-built static-library build of nanomsg for Windows. On unix systems, expects to find nanomsg at `/usr/local/lib/libnanomsg.a` (the default installation directory when running `configure && make && sudo make install` on the nanomsg source).

Endless Possibilities
---------------------

Right now mruby doesn't support threading. There is some discussion about this in the mruby issue tracker. However, most practical nanomsg uses require threads for things like listening to sockets. I'm considering some possibilities...

You can create parallel mruby vm's in multiple threads of your app. This has some memory impacts, but on a desktop system (where lamina is used) these are negligible. Using this approach, an actor system could be developed for mruby. Then actors could be implemented for socket listeners and the like. Or, maybe that's an awful idea. I *really* like [celluloid](https://github.com/celluloid/celluloid) though, so actors with a similar feel would probably be my first attempt at such a threading solution.

I believe nanomsg can also be used in a non-blocking manner, so maybe threads can be avoided altogether. This introduces periodic polling into the client app though... which I wouldn't want to require (especially in a lamina app, where your ruby code isn't running all that often).
