#!/usr/bin/env sh

cd data-structures
mkdir -p build
cd build
cmake -DCMAKE_CXX_FLAGS=$CXX_FLAGS ..
make
CTEST_OUTPUT_ON_FAILURE=1 make test

cd ../..

