#!/bin/sh
g++ test.cpp -o test && ./test < in.txt > out.txt && diff out.txt out_expected.txt
