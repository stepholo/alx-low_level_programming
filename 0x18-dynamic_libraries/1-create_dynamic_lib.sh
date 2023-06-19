#!/bin/bash
cc -fpic -c *.c
cc *.o -shared -o liball.so
export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
