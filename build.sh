#!/bin/bash

cc=gcc
src=src/*.c
name=libfract

flags=(
    -std=c99
    -Wall
    -Wextra
    -pedantic
    -O2
    -ffast-math
    -I.
)

if echo "$OSTYPE" | grep -q "darwin"; then
    dlib=(
        -dynamiclib
    )
    suffix=.dylib
elif echo "$OSTYPE" | grep -q "linux"; then
    dlib=(
        -lm
        -shared
        -fPIC
    )
    suffix=.so
else
    echo "This OS is not supported by this shell script yet..." && exit
fi

cmd() {
    echo "$@" && $@
}

shared() {
    cmd mkdir -p tmp
    cmd $cc -c $src ${flags[*]} && cmd mv *.o tmp/ || exit
    
    cmd mkdir -p bin
    cmd $cc tmp/*.o -o bin/$name$suffix ${dlib[*]}
}

static() {
    cmd mkdir -p tmp
    cmd $cc ${flags[*]} -c $src && cmd mv *.o tmp/ || exit
    
    cmd mkdir -p bin
    cmd ar -cr bin/$name.a tmp/*.o
}

cleand() {
    [ -d $1 ] && cmd rm -r $1
}

cleanf() {
    [ -f $1 ] && cmd rm $1
}

clean() {
    cleand bin
    cleand tmp
    return 0
}

install() {
    [ "$EUID" -ne 0 ] && echo "Run with sudo to install" && exit
    
    make all -j # or static && shared
    cmd cp fract.h /usr/local/include/

    [ -f bin/$name.a ] && cmd mv bin/$name.a /usr/local/lib
    [ -f bin/$name.so ] && cmd mv bin/$name.so /usr/local/lib
    [ -f bin/$name.dylib ] && cmd mv bin/$name.dylib /usr/local/lib
    
    echo "Successfully installed $name"
    return 0
}

uninstall() {
    [ "$EUID" -ne 0 ] && echo "Run with sudo to uninstall" && exit

    cleanf /usr/local/include/fract.h
    cleanf /usr/local/lib/$name.a
    cleanf /usr/local/lib/$name.so
    cleanf /usr/local/lib/$name.dylib

    echo "Successfully uninstalled $name"
    return 0
}

case "$1" in
    "shared")
        shared;;
    "static")
        static;;
    "all")
        shared && static;;
    "make")
        make all -j;;
    "clean")
        clean;;
    "install")
        install;;
    "uninstall")
        uninstall;;
    *)
        echo "Run with 'shared' or 'static' to build"
        echo "Use 'install' to build and install in /usr/local"
        echo "Use 'clean' to remove local builds"
esac
