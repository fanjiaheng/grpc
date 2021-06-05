#!/bin/bash

protoc -I=./proto --cpp_out=./include --grpc_out=./include --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin  helloworld.proto