# Zen FUSE

Zen FUSE is an open source project implementing a distributed user space file
system on top of Zen Spaces.

# Project Status

Zen FUSE is at an early stage of development and is not ready to be used in a
production environment.

# License

Since this project utilizes libFUSE and is tightly coupled with the Linux kernel, 
I am forced to distribute this application using GPL 3.0.  At some time I hope
to remove the libFUSE dependency and redistribute this library with a more
permissive (MIT) license.

If you would like to use portions of this library without linking it to libFUSE,
feel free to license it using the MIT license.

# Building

These instructions assume you have a development environment with a vendor 
irectory; if you don't then you'll have translate these instructions based on 
your configuration.

## Dependencies

The following instructions will guide you through downloading, compiling, and
installing the Zen FUSE dependencies.

```
sudo apt install libfuse-dev
cd ~/dev/vendor
```

