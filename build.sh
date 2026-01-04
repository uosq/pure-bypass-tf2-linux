#!/usr/bin/env bash

gcc -shared -fPIC \
	src/main.c \
	src/libdetour/libdetour.c \
	src/libsigscan/libsigscan.c \
	-o build/libpure.so \
	-O2 -s