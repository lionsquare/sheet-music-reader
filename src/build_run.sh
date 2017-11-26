#!/bin/bash

echo "Building Sheet Music Reader..."
cd ../build
cmake ../src .
make
echo ""

echo "Running Sheet Music Reader..."
./sheet-music-reader
cd ../src
echo ""

echo "Building Test Suite..."
g++ run_tests.cpp argparser.cpp /usr/lib/libgtest_main.a /usr/lib/libgtest.a -lpthread -o run_tests
echo ""

echo "Testing Sheet Music Reader..."
./run_tests
echo ""

