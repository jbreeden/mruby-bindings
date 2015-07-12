mruby-apr
=========

Bindings to the Apache APR library, providing a portable runtime library for mruby.

Description
-----------

Apache APR provides a cross platform runtime library for C, allowing portable access to system resources
(eg processes, files, sockets, etc.). `mruby-apr` provides bindings to this library to bring these capabilities
to mruby, without having to code the cross-platform logic over again.

These bindings are provided at 2 distinct levels:

1. Direct bindings to libapr are provided in the `APR` module.
  + These bindings provide a nearly identical api to libapr from mruby as is available in C.
  + The main point of difference is that out-parameters in the C API correspond to multiple return values in the mruby API.
2. The direct bindings are used to implement portions of the CRuby standard library, purely in mruby.
  + This provides a familiar and idiomatic API to system resources for ruby programmers.
  + As with the Rubinius implementation, this should make it easier for Ruby programmers to hack on the stdlib.

`mruby-apr` is intended for mruby builds targeting the platforms supported by libapr. This includes Windows, Mac, Linux, and other fairly common operating systems. So, while some limited embedded targets may be out of the question, this mrbgem could be
useful when embedding mruby as a scripting language in a desktop or mobile app.

Implemented So Far
------------------

```
Directories
-----------

  - APR::apr_dir_open(path: String, pool: AprPoolType): [errno: Fixnum, dir: AprDirT]
    + Gets file information for each entry in the directory

  - APR::apr_dir_read(finfo: AprFinfoT, wanted: Fixnum, dir: AprDirT): errno: Fixnum
    + Gets file information for each entry in the directory

  - APR::apr_dir_make(path: String, permissions: Fixnum, pool: AprPoolType): errno: Fixnum
    + Creates a directory

  - APR::apr_dir_make_recursive(path: String, permissions: Fixnum, pool: AprPoolType): errno: Fixnum
    + Creates a directory and any required parent directories

  - APR::apr_dir_remove(path: String, pool: AprPoolType): errno: Fixnum
    + Deletes a directory

  SUCCESS [0/5 tests failed]

File IO
-------

  - APR::apr_file_open(name: String, mode: Fixnum, permissions: Fixnum, pool: AprPoolT): [errno: Fixnum, file: AprFileT]
    + Can open a file for writing
    + Can open a file for reading

  - APR::apr_file_puts(buf: String, file: AprFileT)
    + Can write to an open, writable, file

  - APR::apr_file_gets(at_most_n_bytes: Fixnum, file: AprFileT): [errno: Fixnum, str: String]
    + Reads length (1st param) characters and returns the string
    + Reads as many characters as possible when length is beyond EOF

  - APR::apr_file_write(file: AprFileT, buffer: String, num_bytes: Fixnum): [errno: Fixnum, bytes_written: Fixnum]
    + Can write strings with nulls to a file

  - APR::apr_file_read(file: AprFileT, Fixnum: num_bytes): [errno: Fixnum, str: String]
    + Can read strings with nulls from a file
    + Returns EOF on first attempt to read past EOF

  - APR::apr_file_close(file: AprFileT): errno: Fixnum
    + Closes an AprFileT

  - APR::apr_file_seek(thefile: AprFileT, where: Fixnum, offset: Fixnum): [errno: Fixnum, resulting_offset: Fixnum]
    + Can seek back from the end of the file

  - APR::apr_file_copy(from_path: String, to_path: String, perms: int, pool: AprPoolType): errno: Fixnum
    + Copies files by name

  - APR::apr_file_rename(from_path: String, to_path: String, pool: AprPoolType): errno: Fixnum
    + Renames a file

  - APR::apr_file_remove(from_path: String, to_path: String, perms: int, pool: AprPoolType): errno: Fixnum
    + Removes a file

  - APR::apr_file_lock(file: AprFileT, lock_type: Fixnum): errno: Fixnum
    + Locks a file (either flock or iocntl based, depending on platform)

  - APR::apr_file_unlock(file: AprFileT): errno: Fixnum
    + Unlocks a file (either flock or iocntl based, depending on platform)

  - APR::apr_file_attrs_set(fname: String, attrs: Fixnum, attr_mask: Fixnum, pool: AprPoolT): errno: Fixnum
    + Sets attributes on a file

  SUCCESS [0/16 tests failed]

Processes
---------

  - APR::apr_proc_create(command: String, argv: Array<String>, env: Array<String>, proc_attr: AprProcattrT, pool: AprPoolT): [errno: Fixnum, proc: AprProcT]
    + Can run a shell command and redirect output to a file
    + Can run a shell command and pipe output to parent via APR.apr_file_pipe_create

  - APR::apr_procattr_io_set(procattr: AprProcattrT, in: Fixnum, out: Fixnum, err: Fixnum): errno: Fixnum
    + Can automatically create pipes between the parent and child processes (for std in, out, & err)

  SUCCESS [0/3 tests failed]

Sockets
-------

  - APR::apr_sockaddr_info_get
    + Creates a socket

  SUCCESS [0/1 tests failed]

Standard Lib: File
------------------

  - File::open(filename, mode="r" [, &block])
    + Returns an open File object, if filename exists
    + Raises a SystemCallError if filename does not exist
    + If given a block, it is passed the File, and the File is automatically closed when the block terminates

  - File#puts(obj, ...)
    + Writes the given objects to the File, appending the field separator ($\) between each item
    + Raises an IOError if the file is not open for writing
    + Appends to the file if opened with mode="a"
    + Does not append a record separator after any args that already end with a record separator sequence
    + If called with any array arguments, flattens the arrays and writes each element on a new line
    + If called without arguments, outputs a single record separator

  - File#gets | gets(sep=$/) | gets(limit) | gets(sep, limit)
    + Reads until sep when called as `gets(sep=$/)` (the separator is included in the result)
    + Returns "" if limit is 0
    + Reads at most `limit` bytes when called as `gets(limit)`
    + Reads at most `limit` bytes when called as `gets(sep, limit)`
    + Raises an IOError if the stream isn't open for reading
    + Returns nil if called at end of file

  - File#read
    + Reads length bytes from the file
    + If length is omitted or is nil, it reads until EOF
    + If length is provided, nil means it met EOF at beginning
    + If length is provided, 1 to length-1 bytes string means it met EOF after reading the result
    + If length is provided, the length bytes string means it doesn’t meet EOF
    + If length is zero, it returns ""
    + At end of file, it returns "" if length omitted or nil
    + Raises an IOError if the file isn't open for reading

  - File#write
    + Writes the given string to the file
    + If the argument is not a string, it will be converted to a string using to_s
    + Returns the number of bytes written
    + Raises an IOError if the file isn't open for writing

  - File#each(&block)
    + Executes the given block for each line in the file, passing in the line
    + Returns an Enumerator if no block is given

  - File#each_line(&block)
    + Is an alias for each

  - File#each_byte(&block)
    + Executes the given block for each character in the file
    + Returns an Enumerator if no block is given

  - File#eof | eof?
    + Returns true if EOF has been hit, or else false
    + Returns true for an empty file, even if no reads have been performed yet

  - File#getbyte
    + Returns the next character, or nil if at EOF

  - File#getc
    + Returns the next character, or nil if at EOF

  - File#ungetbyte
    + Pushes back bytes onto a file buffer

  - File#ungetc
    + Pushes back bytes onto a file buffer

  SUCCESS [0/38 tests failed]

Standard Lib: Process
---------------------

  - Process::spawn
    + Spawns a shell command if given a string
    + Spawns a program, with no shell, if given argv as multiple args

  SUCCESS [0/2 tests failed]

Time
----

  - APR::apr_time_now(pool: AprPoolT): time: AprTimeT
    + Gets the current time

  SUCCESS [0/1 tests failed]
```
