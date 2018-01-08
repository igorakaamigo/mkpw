cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
include(../scripts/HunterGate.cmake)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.221.tar.gz"
    SHA1 "dc138cc9d1b5badf01e62ab0849f73c82e8ffd1d"
)

project(mkpw-test)

hunter_add_package(GTest)
find_package(GMock CONFIG REQUIRED)

add_executable(
  ${CMAKE_PROJECT_NAME}
  ../src/application.hpp
  ../src/application.cpp
  application_tests.cpp
)

target_link_libraries(
  ${CMAKE_PROJECT_NAME}
  PRIVATE
  GMock::main
)

