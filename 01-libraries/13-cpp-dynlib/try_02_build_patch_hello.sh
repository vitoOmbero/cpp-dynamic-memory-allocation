#!/bin/bash

./delete_files.sh
./copy_files.sh

# patch
mv -v hello.c  hello.cpp

sed -i '/\#define HELLO_H/a \#ifdef __cplusplus\
extern "C" \
\#endif' hello.h

./build_c_cpp_dynlib.sh

echo "trying to run the executable"
./execute_hello.sh
