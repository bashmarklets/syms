#!/bin/bash
# Copyright (c) 2019, Stein Gunnar Bakkeby
# Lists symlinks in the current directory, or alternatively recursively
# by including the -r argument.

syms () {
    if [[ "$1" = "-r" ]]; then
        find . -type l -exec ls -l {} + | sed 's/ -> / ➟ /g'
    else
        find . -maxdepth 1 -type l -exec ls -l {} + | sed 's/ -> / ➟ /g'
    fi
}

# NB: It is worth noting that the transformation of -> to ➟ isn't
# actually there for display purposes. It is there in the unfortunate
# event that a user should by mistake copy and paste ls -l output on the
# command line. In such a case the > captures the empty output of
# "command not found" and overwrites the file that the symlink refers to.
# The user will typically also be unaware of what has transpired.
# By changing the > to another character we can avoid this sceneario and
# further surprises down the line.
