#!/bin/bash

find ../12-build-dynlib/ -name '*.h' -exec cp -prv '{}' '.' ';'
find ../12-build-dynlib/ -name '*.c' -exec cp -prv '{}' '.' ';'
find ../12-build-dynlib/ -name '*.out' -exec cp -prv '{}' '.' ';'
echo "files are copied"
