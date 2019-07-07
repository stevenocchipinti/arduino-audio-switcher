#!/bin/bash
echo "const char HTML[] PROGMEM = R\"=====("
cat $1
echo
echo ")=====\";"
