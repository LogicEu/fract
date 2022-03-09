#!/bin/bash

cc=gcc
src=src/*.c
name=libfract

flags=(
    -std=c99
    -Wall
    -Wextra
    -O2
)

inc=(
    -I.
)

fail_op() {
    echo "Run with -d to build dynamically, or -s to build statically."
    exit
}

fail_os() {
    echo "OS is not supported yet..."
    exit
}

mac_dlib() {
    $cc ${flags[*]} ${inc[*]} -dynamiclib $src -o $name.dylib 
}

linux_dlib() {
    $cc -shared ${flags[*]} ${inc[*]} ${lib[*]} -lm -fPIC $src -o $name.so 
}

dlib() {
    if echo "$OSTYPE" | grep -q "darwin"; then
        mac_dlib
    elif echo "$OSTYPE" | grep -q "linux"; then
        linux_dlib
    else
        fails_os
    fi
}

slib() {
    $cc ${flags[*]} ${inc[*]} -c $src && ar -crv $name.a *.o && rm *.o
}

cleanf() {
    if [ -f $1 ]; then
        rm $1  
    fi
}

clean() {
    cleanf $name.a
    cleanf $name.so
    cleanf $name.dylib
}

case "$1" in
    "-d")
        dlib;;
    "-s")
        slib;;
    "-clean")
        clean;;
    *)
        fail_op;;
esac
