#!/bin/bash

cc=gcc
src=src/*.c
name=libfract
inc=-I.

flags=(
    -std=c99
    -Wall
    -Wextra
    -O2
)

dlib() {
    if echo "$OSTYPE" | grep -q "darwin"; then
        $cc ${flags[*]} $inc -dynamiclib $src -o $name.dylib 
    elif echo "$OSTYPE" | grep -q "linux"; then
        $cc -shared ${flags[*]} $inc ${lib[*]} -lm -fPIC $src -o $name.so 
    else
        echo "OS is not supported yet..." && exit
    fi
}

slib() {
    $cc ${flags[*]} $inc -c $src && ar -cr $name.a *.o && rm *.o
}

cleanf() {
    [ -f $1 ] && rm $1 && echo "Deleted $1"
}

clean() {
    cleanf $name.a
    cleanf $name.so
    cleanf $name.dylib
    return 0
}

install() {
    [ "$EUID" -ne 0 ] && echo "Run with sudo to install" && exit

    dlib && slib
    cp fract.h /usr/local/include

    [ -f $name.a ] && mv $name.a /usr/local/lib
    [ -f $name.so ] && mv $name.so /usr/local/lib
    [ -f $name.dylib ] && mv $name.dylib /usr/local/lib

    echo "Succesfully installed fract in /usr/local"
    return 0
}

uninstall() {
    [ "$EUID" -ne 0 ] && echo "Run with sudo to uninstall" && exit

    cleanf /usr/local/include/fract.h
    cleanf /usr/local/lib/$name.a
    cleanf /usr/local/lib/$name.so
    cleanf /usr/local/lib/$name.dylib

    echo "Succesfully uninstalled fract"
    return 0
}

case "$1" in
    "shared")
        dlib;;
    "static")
        slib;;
    "clean")
        clean;;
    "install")
        install;;
    "uninstall")
        uninstall;;
    *)
        echo "Run with 'shared' or 'static' to build."
        echo "Use 'install' to build and install in /usr/local"
        echo "Use 'clean' to remove local builds.";;
esac
