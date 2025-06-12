cmake_minimum_required(VERSION 3.31)
project(SecOCTest2)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        ${PROJECT_SOURCE_DIR}/include/CCL
        ${PROJECT_SOURCE_DIR}/include/cryptopp/
)

link_directories(${PROJECT_SOURCE_DIR}/lib/cryptopp)

add_library(SecOCTest2 SHARED
        include/CCL/CCL_VC_x86.def
        include/CCL/CCL.cpp
        library.cpp
)

target_link_libraries(SecOCTest2 cryptlib.lib)
