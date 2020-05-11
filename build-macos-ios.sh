#!/bin/bash

echo "Build for MacOS"
go build -buildmode c-shared -o storj_uplink-macos.dylib

echo "Build for iOs x86"
export GOARM=7
export GOOS=darwin
export GOARCH=arm
export CC=iphoneos-clang
export CXX=iphoneos-clang++
export CGO_CFLAGS=-isysroot=iphoneos -miphoneos-version-min=7.0 -arch armv7
export CGO_CXXFLAGS=-isysroot=iphoneos -miphoneos-version-min=7.0 -arch armv7
export CGO_LDFLAGS=-isysroot=iphoneos -miphoneos-version-min=7.0 -arch armv7
export CGO_ENABLED=1
go build -tags ios -x -ldflags=-w -o=storj_uplink-arm.dylib

echo "Build for iOs x64"
export GOOS=darwin
export GOARCH=arm64
export CC=iphoneos-clang
export CXX=iphoneos-clang++
export CGO_CFLAGS=-isysroot=iphoneos -miphoneos-version-min=7.0 -arch arm64
export CGO_CXXFLAGS=-isysroot=iphoneos -miphoneos-version-min=7.0 -arch arm64
export CGO_LDFLAGS=-isysroot=iphoneos -miphoneos-version-min=7.0 -arch arm64
export CGO_ENABLED=1
go build -tags ios -x -ldflags=-w -o=storj_uplink-arm64.dylib

echo "Build for iOs-Simulator x86"
export GOOS=darwin
export GOARCH=386
export CC=iphonesimulator-clang
export CXX=iphonesimulator-clang++
export CGO_CFLAGS=-isysroot=iphonesimulator -mios-simulator-version-min=7.0 -arch i386
export CGO_CXXFLAGS=-isysroot=iphonesimulator -mios-simulator-version-min=7.0 -arch i386
export CGO_LDFLAGS=-isysroot=iphonesimulator -mios-simulator-version-min=7.0 -arch i386
export CGO_ENABLED=1
go build -tags ios -x -ldflags=-w -o=storj_uplink-sim86.dylib

echo "Build for iOs-Simulator x64"
export GOOS=darwin
export GOARCH=amd64
export CC=iphonesimulator-clang
export CXX=iphonesimulator-clang++
export CGO_CFLAGS=-isysroot=iphonesimulator -mios-simulator-version-min=7.0 -arch x86_64 
export CGO_CXXFLAGS=-isysroot=iphonesimulator -mios-simulator-version-min=7.0 -arch x86_64 
export CGO_LDFLAGS=-isysroot=iphonesimulator -mios-simulator-version-min=7.0 -arch x86_64 
export CGO_ENABLED=1
go build -tags ios -x -ldflags=-w -o=storj_uplink-sim64.dylib