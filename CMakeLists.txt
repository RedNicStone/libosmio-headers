
cmake_minimum_required(VERSION 3.11...3.26)

project(osmio-headers
        VERSION 0.1
        DESCRIPTION "A fast c library for interfacing with low level I/O uniformly and efficiently"
        LANGUAGES C)

add_library(osmio-headers
        INTERFACE)
add_library(libosmio-headers
        ALIAS osmio-headers)

target_include_directories(osmio-headers
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

option(LIBOSMIO_HIDE_LOADER_FUNCTIONS
        "Tell the libosmio core to hide all functions that are implemented by the loader. Useful for ICDs" OFF)

if (LIBOSMIO_HIDE_LOADER_FUNCTIONS)
    target_compile_definitions(osmio-headers
            INTERFACE LIBOSMIO_HIDE_LOADER_FUNCTIONS)
endif ()