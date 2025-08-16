# wvkbd-contrib

My contributed layout sets for [wvkbd](https://git.sr.ht/~proycon/wvkbd).
For the available layout sets, please check the `layout` directory.

**Please don't contribute your layout sets to this repository. Instead, you can
fork this repository, and manage your layout sets on your repository.**
Because people's preferences are different, and I cannot manage a variety of the designs.

## Getting started

Check the `layout` directory, and choose the layout set which you want to use
such as `hello` and `split`. Use the layout set `hello` as an example on the
following steps.

Download the code.

```
$ git clone --recurse-submodules https://github.com/junaruga/wvkbd-contrib.git
$ cd wvkbd-contrib
```

Install the dependency libraries. See [this page](doc/install_deps.md).

Build the layout set. It creates the binary file on the current directory.

```
$ make LAYOUT=hello
```

Copy the created binary file to your `bin` directory such as `~/.local/bin`.

```
$ cp -p wvkbd-hello /path/to/bin
```

If you want to see the command line help, run:

```
$ wvkbd-hello --help
```

If you want to clean the files, run:

```
$ make LAYOUT=hello clean
```

For other layout sets, the commands are the same as well.
