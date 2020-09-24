#!/bin/bash

# 1) move libhello.so to the path which ld is using (man ld)
#    (usually is done by install script or package manager) 
# 2) -mv libHello.so /path/to/your/library/folder/MyProjectLibs 
#    and edit /etc/ld.so.conf with adding your path
#    and run ldconfig
# 3) use environmental variables

export LD_LIBRARY_PATH=.

./hello.out

# session-lifetime environmantal variable was used

unset LD_LIBRARY_PATH

./hello.out
