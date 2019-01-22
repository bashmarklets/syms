# syms
One can see symlinks and what they refer to simply by running `ls -l` in a given directory and this is generally sufficient for day to day use. If you work with symlinks a lot, on the other hand, then sometimes you may want to list symlinks, and only symlinks, in the given directory.

`syms` is a simple and shorthand function that let's you do exactly this. The main benefit of this is that you don't have to scroll if the directory has many files.

## Example output
```bash
[bash@marklet:/dev]
$ syms                                                                                                           
lrwxrwxrwx 1 root root 11 Jan 22 19:23 ./core ➟ /proc/kcore
lrwxrwxrwx 1 root root 13 Jan 22 19:23 ./fd ➟ /proc/self/fd
lrwxrwxrwx 1 root root 25 Jan 22 19:23 ./initctl ➟ /run/systemd/initctl/fifo
lrwxrwxrwx 1 root root 28 Jan 22 19:23 ./log ➟ /run/systemd/journal/dev-log
lrwxrwxrwx 1 root root  4 Jan 22 19:23 ./rtc ➟ rtc0
lrwxrwxrwx 1 root root 15 Jan 22 19:23 ./stderr ➟ /proc/self/fd/2
lrwxrwxrwx 1 root root 15 Jan 22 19:23 ./stdin ➟ /proc/self/fd/0
lrwxrwxrwx 1 root root 15 Jan 22 19:23 ./stdout ➟ /proc/self/fd/1
```

You can also search recursively with `syms -r` should you ever need that.

## How to install

Either download/clone this repository and add the following to your `~/.bashrc` file:
```bash
source path/to/syms.inc
```

or alternatively just copy-paste the function directly into your `~/.bashrc` file:

```bash
syms () {
    if [[ "$1" = "-r" ]]; then
        find . -type l -exec ls -l {} + | sed 's/ -> / ➟ /g'
    else
        find . -maxdepth 1 -type l -exec ls -l {} + | sed 's/ -> / ➟ /g'
    fi
}
```

NB: The source approach is recommended if you end up picking up more than one of these bookmarklets as it avoids clutter.
