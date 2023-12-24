cmake_minimum_required(VERSION 3.12)
project(cpp-alg VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)
add_library(gcd_of_strings src/gcd_of_strings.h src/gcd_of_strings.cpp)

add_subdirectory(test)
