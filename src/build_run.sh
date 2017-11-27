#!/bin/bash

echo "Building Sheet Music Reader..."
cd ../build
cmake ../src .
cd ../src
#g++ main.cpp reader.cpp argparser.cpp -lopencv_core -o sheet-music-reader 
echo ""

echo "Running Sheet Music Reader..."
../build/sheet-music-reader /home/moon/Projects/sheet-music-reader/ignite.png
echo ""

echo "Building Test Suite..."
g++ run_tests.cpp argparser.cpp reader.cpp /usr/lib/libgtest_main.a /usr/lib/libgtest.a -lpthread -lopencv_core -o tests/run_tests
echo ""

echo "Testing Sheet Music Reader..."
./tests/run_tests
echo ""

