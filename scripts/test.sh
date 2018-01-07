#!/usr/bin/env sh

BINARY=mkpw-test
CMAKE=cmake
TYPE=Debug
DEST=build/_test

$CMAKE -Htest -B$DEST -DHUNTER_STATUS_DEBUG=ON -DCMAKE_BUILD_TYPE=$TYPE
$CMAKE --build $DEST --config $TYPE
$DEST/$BINARY
rm $DEST/$BINARY
