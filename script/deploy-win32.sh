#!/usr/bin/env bash

rm -rf build/*
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/mingw-toolchain.cmake ..
make -j8
cd ..

zip dashmaker-win.zip bin/win32/* bin/win32/**/*
