#!/bin/bash

./delete_files.sh
./copy_files.sh

# just rename as code is the same
mv -v hello.c  hello.cpp

./build_c_cpp_dynlib.sh

echo "trying to run the executable"
./execute_hello.sh

echo ""
echo ""
echo "the problem is:"
echo " * we have executable /"hello.out/" in C"
echo " * we have library /"libhello.so/" in C++"
echo " * C++ compiler uses name mangling (see https://en.wikipedia.org/wiki/Name_mangling )"
echo ""
echo ""
