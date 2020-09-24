#!/bin/bash

# -fPIC  - for x86-64
# lib<filename>.so - naming convention

gcc -o libhello.so -shared -fPIC hello.c

nm libhello.so

echo "lib is compiled"

# -L. - to look for libs in currents path

gcc main.c -fPIC -L. -lhello -o hello.out

echo "executable is compiled..."

echo "..but it can't be executed!"
# 1) move libhello.so to the path which ld is using (man ld)
#    (usually is done by install script or package manager) 
# 2) -mv libHello.so /path/to/your/library/folder/MyProjectLibs 
#    and edit /etc/ld.so.conf with adding your path
#    and run ldconfig
# 3) use environmental variables