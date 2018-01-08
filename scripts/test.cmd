cmake -Htest -Bbuild\_test -DHUNTER_STATUS_DEBUG=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build\_test --config Debug
build\_test\Debug\mkpw-test.exe
del build\_test\Debug\mkpw-test.exe
