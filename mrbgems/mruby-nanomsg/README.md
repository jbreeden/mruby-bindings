mruby-nanomsg
=============

Mruby bindings to nanomsg. A component of the [lamina project](https://github.com/jbreeden/lamina).

This is intended to be used for inter-thread and inter-process communication in lamina. Lamina, being built on Chromium Embedded Framework, does have IPC builtin. However, it does not appear as friendly or scalable as nanomsg. This could be used as a general purpose messaging system for mruby (allowing communications with CRuby, or node, or Go, or...)

Building
--------

Includes a pre-built static-library build of nanomsg for Windows. On unix systems, expects to find nanomsg at `/usr/local/lib/libnanomsg.a` (the default installation directory when running `configure && make && sudo make install` on the nanomsg source).

Actors?
-------

MRuby doesn't support threading with a single VM. I'm considering some possibilities...

You can create parallel mruby vm's in multiple threads of your app. This has some memory impacts, but on a desktop system (where lamina is used) these are negligible. Using this approach, an actor system could be developed for mruby. Then actors could be implemented for socket listeners and the like. Or, maybe that's an awful idea. I *really* like [celluloid](https://github.com/celluloid/celluloid) though, so actors with a similar feel would probably be my first attempt at such a threading solution. Since you couldn't create an actor with a block like you do a thread in CRuby, the API could be similar to web workers. Ex "Hey, start an actor running this file" or even a string based message saying "start an actor, and call this function to kick it off."
