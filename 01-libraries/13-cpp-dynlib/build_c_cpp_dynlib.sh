#!/bin/bash

File=./hello.h
unpatched_size=6


if [ -f "$File" ]; then
    lines=$(wc -l < "$File")
    if [ "$lines" -gt "$unpatched_size" ]; then
        g++ -o libhello.so -shared -fPIC hello.cpp
    else
        gcc -o libhello.so -shared -fPIC hello.cpp
        nm libhello.so
        echo ""
        echo "note this: "
        echo ""
        nm libhello.so | grep "print_hello"
        echo ""
        echo ""
        echo "expected:"
        echo "run the command: c++filt <mangled name>"
        echo ""
        echo ""
    fi   
else 
    echo "You should copy files first!"
fi


