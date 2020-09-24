#!/bin/bash
# chmod +x build.sh
gcc -c hello.c -o hello.o

objdump -d hello.o >> hello.o.txt
