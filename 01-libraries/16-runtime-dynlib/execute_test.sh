#!/bin/bash

export LD_LIBRARY_PATH=.
echo -e "\033[0;32m================="
echo "run executable:"
./test.out

echo -e "\033[0;31m"
rm -v *.so

echo -e "\033[0;32mrun executable again:"
./test.out

unset LD_LIBRARY_PATH

echo -e "\033[1;37m================="
