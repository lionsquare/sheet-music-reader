#!/bin/bash

echo "Building Sheet Music Reader..."
cd ../build
cmake ../src .
make
cd ../src
echo ""

echo "Running Sheet Music Reader..."
../build/sheet-music-reader /home/moon/Projects/sheet-music-reader/ignite.png
echo ""

echo "Building Test Suite..."
cd tests/
cmake .
make
cd ..
echo ""

echo "Testing Sheet Music Reader..."
./tests/test-sheet-music-reader
echo ""

