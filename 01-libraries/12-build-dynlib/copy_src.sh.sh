#!/bin/bash

find ../11-build-simple/ -name '*.h' -exec cp -prv '{}' '.' ';'
find ../11-build-simple/ -name '*.c' -exec cp -prv '{}' '.' ';'
echo "files are copied"
