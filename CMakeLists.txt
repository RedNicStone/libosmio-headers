
cmake_minimum_required(VERSION 3.7...3.26)

project(osmio
        VERSION 0.1
        DESCRIPTION "A fast c library for interfacing with low level I/O uniformly and efficiently"
        LANGUAGES C)

file(GLOB_RECURSE LIBOSMIO_INCLUDE_HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)

add_library(osmio
        INTERFACE ${LIBOSMIO_INCLUDE_HEADERS}
        ALIAS libosmio)

target_include_directories(osmio
        INTERFACE ${CMAKE_SOURCE_DIR}/include)

option(LIBOSMIO_HIDE_LOADER_FUNCTIONS
        "Tell the libosmio core to hide all functions that are implemented by the loader. Useful for ICDs" OFF)
target_compile_definitions(osmio
        PUBLIC ${LIBOSMIO_INCLUDE_HEADERS}
        LIBOSMIO_HIDE_LOADER_FUNCTIONS)
