#!/usr/bin/env bash

rm -rf build/*
cd build
cmake ..
make -j8
cd ..

zip dashmaker-linux.zip bin/linux/* bin/linux/**/*
