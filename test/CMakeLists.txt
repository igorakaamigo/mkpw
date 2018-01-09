#
# MIT License
#
# Copyright (c) 2018 Igor M Osipov
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
include(../scripts/HunterGate.cmake)
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.19.221.tar.gz"
        SHA1 "dc138cc9d1b5badf01e62ab0849f73c82e8ffd1d"
)

project(mkpw-test)

hunter_add_package(Boost COMPONENTS program_options random system)
find_package(Boost CONFIG REQUIRED COMPONENTS program_options random system)

hunter_add_package(GTest)
find_package(GMock CONFIG REQUIRED)

add_executable(
        ${CMAKE_PROJECT_NAME}
        ../src/application.hpp
        ../src/application.cpp
        ../src/generator.hpp
        ../src/generator.cpp
        support/application_tests.hpp
        support/application_tests.cpp
        support/generator_tests.hpp
        support/generator_tests.cpp
        application_tests.cpp
        generator_tests.cpp
)

target_link_libraries(
        ${CMAKE_PROJECT_NAME}
        PRIVATE
        Boost::program_options
        Boost::random
        GMock::main
        Boost::system
)
