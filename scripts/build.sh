#!/usr/bin/env sh

TYPE=Release
DEST=build/_release

CMAKE=cmake

$CMAKE -H. -B$DEST -DHUNTER_STATUS_DEBUG=ON -DCMAKE_BUILD_TYPE=$TYPE
$CMAKE --build $DEST --config $TYPE
