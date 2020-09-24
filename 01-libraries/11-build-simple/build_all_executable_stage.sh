#!/bin/bash
# chmod +x build.sh
./build_all_objectfile_stage.sh

gcc -o executable.out hello.o main.o


