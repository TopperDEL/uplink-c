#!/bin/bash

echo "*** Build for MacOS ***"
go build -buildmode c-shared -o "build/macOS/storj_uplink.dylib"

echo "*** Build for iOs x64 ***"
env \
GOOS='darwin' \
CC=cc \
CXX=c++ \
CGO_ENABLED=1 \
GOARCH=arm64 \
CGO_CFLAGS="-arch arm64 -fpic -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk -miphoneos-version-min=12.0" \
CGO_LDFLAGS="-arch arm64 -dynamic -fpic -shared -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk -miphoneos-version-min=12.0" \
go build -ldflags -w -v -tags ios -o "build/arm64/storj_uplink.a" -buildmode=c-archive

xcrun -sdk iphoneos clang -arch arm64 -fpic -shared -Wl,-all_load "build/arm64/storj_uplink.a" -framework Corefoundation -o "build/arm64/storj_uplink.dylib"
rm "build/arm64/storj_uplink.a"

echo "*** Build for iOs-Simulator x86 ***"
env \
GOOS='darwin' \
CC=cc \
CXX=c++ \
CGO_ENABLED=1 \
GOARCH=386 \
CGO_CFLAGS="-arch i386 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk" \
CGO_LDFLAGS="-arch i386 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk" \
go build -ldflags -w -v -tags ios -o "build/sim86/storj_uplink.dylib" -buildmode=c-shared

echo "*** Build for iOs-Simulator x64 ***"
env \
GOOS='darwin' \
CC=cc \
CXX=c++ \
CGO_ENABLED=1 \
GOARCH=amd64 \
CGO_CFLAGS="-arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk" \
CGO_LDFLAGS="-arch x86_64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk" \
go build -ldflags -w -v -tags ios -o "build/sim64/storj_uplink.dylib" -buildmode=c-shared

echo "*** Create fat library containing all architectures ***"	
lipo -create -output "build/libstorj_uplink.dylib" "build/sim64/storj_uplink.dylib" "build/arm64/storj_uplink.dylib" "build/sim86/storj_uplink.dylib" 
