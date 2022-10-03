#!/bin/bash
cc -fPIC *.c -o libdynamic.so
cc -shared -o liball.so *.o
