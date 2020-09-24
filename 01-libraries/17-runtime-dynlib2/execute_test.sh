#!/bin/bash

export LD_LIBRARY_PATH=.
echo -e "\033[0;32m================="
echo "run executable:"
./test.out libfoo.so foo 2

echo -e "\033[0;32mrun executable again:"
./test.out libbar.so bar 3

unset LD_LIBRARY_PATH

echo -e "\033[1;37m================="
