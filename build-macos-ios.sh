#!/bin/bash

echo "*** Build for MacOS ***"
go build -buildmode c-shared -o storj_uplink-macos.dylib

echo "*** Build for iOs x86 ***"
env \
GOOS='darwin' \
CC=cc \
CXX=c++ \
CGO_ENABLED=1 \
GOARCH=arm \
CGO_CFLAGS="-arch arm -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS13.4.sdk -miphoneos-version-min=10.0" \
CGO_LDFLAGS="-arch arm -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS13.4.sdk -miphoneos-version-min=10.0" \
go build -ldflags -w -v -installsuffix goi -o "arm/storj_uplink.a" -buildmode=c-archive

echo "*** Build for iOs x64 ***"
env \
GOOS='darwin' \
CC=cc \
CXX=c++ \
CGO_ENABLED=1 \
GOARCH=arm64 \
CGO_CFLAGS="-arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS13.4.sdk -miphoneos-version-min=12.0" \
CGO_LDFLAGS="-arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS13.4.sdk -miphoneos-version-min=12.0" \
go build -ldflags -w -v -installsuffix goi -o "arm64/storj_uplink.a" -buildmode=c-archive

echo "*** Build for iOs-Simulator x86 ***"
env \
GOOS='darwin' \
CC=cc \
CXX=c++ \
CGO_ENABLED=1 \
GOARCH=386 \
CGO_CFLAGS="-arch i386 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator13.4.sdk" \
CGO_LDFLAGS="-arch i386 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator13.4.sdk" \
go build -ldflags -w -v -installsuffix goi -o "sim86/storj_uplink.a" -buildmode=c-archive


echo "*** Build for iOs-Simulator x64 ***"
env \
GOOS='darwin' \
CC=cc \
CXX=c++ \
CGO_ENABLED=1 \
GOARCH=amd64 \
CGO_CFLAGS="-arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator13.4.sdk" \
CGO_LDFLAGS="-arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator13.4.sdk" \
go build -ldflags -w -v -installsuffix goi -o "amd64/storj_uplink.a" -buildmode=c-archive
