#!/bin/bash

echo "build project"

rm -rf build
mkdir build
cd build
cmake ..
make
cp grpc_client ../
cd ..