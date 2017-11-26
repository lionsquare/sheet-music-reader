#!/bin/bash

echo "Building Sheet Music Reader..."
cd ../build
cmake ../src .
make
echo ""

echo "Running Sheet Music Reader..."
./sheet-music-reader /home/moon/Projects/sheet-music-reader/ignite.png
cd ../src
echo ""

echo "Building Test Suite..."
g++ run_tests.cpp argparser.cpp reader.cpp /usr/lib/libgtest_main.a /usr/lib/libgtest.a -lpthread -o tests/run_tests
echo ""

echo "Testing Sheet Music Reader..."
./tests/run_tests
echo ""

