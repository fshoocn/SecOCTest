cmake_minimum_required(VERSION 3.31)
project(SecOCTest2)

set(CMAKE_CXX_STANDARD 20)

add_library(SecOCTest2 SHARED
        include/CCL/CCL_VC_x86.def
        library.cpp)
