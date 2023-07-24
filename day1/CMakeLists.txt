cmake_minimum_required(VERSION 3.26)
project(myProject)

# Activation of assembly
option(DUMP_ASM "Create full assembly of final executable" OFF)

# Standards defintion
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON")

# Sources files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_executable(myProject ${SOURCES})

# Flags and optimization
if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wdouble-promotion
        -Wformat=2
        -Wundef
        -Wno-unused-parameter
        $<$<COMPILE_LANGUAGE:CXX>: -Wconversion -Wold-style-cast -Wsuggest-override>
        $<$<CONFIG:Debug>:-O0 -g -fdebug-macro>
        $<$<CONFIG:Release>:-Ofast -g0>)
elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        BUILD_DIR := build
        C_COMPILER := clang
        CXX_COMPILER := clang++
        # C_COMPILER := gcc
        # CXX_COMPILER := g++
        BUILD_SYSTEM := Ninja
        # BUILD_SYSTEM := MinGW Makefiles
        BUILD_TYPE := Debug
        # BUILD_TYPE := Release
        configure:
        cmake \

        --no-warn-unused-cli \

        -G$ (BUILD_SYSTEM)\

        -B$ (BUILD_DIR)\

        -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE \

        -DCMAKE_BUILD_TYPE=$ (BUILD_TYPE)\

        -DCMAKE_C_COMPILER=$ (C_COMPILER)\

        -DCMAKE_CXX_COMPILER=$ (CXX_COMPILER)\

        -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake # vcpkg archlinux
        build: configure
        cmake --build $ (BUILD_DIR)--verbose
        run: build
        build/myProject
        clean:
        rm -rf build
        -Wdouble-promotion
        -Wformat=2
        -Wundef
        -Wno-unused-parameter
        $<$<COMPILE_LANGUAGE:CXX>: -Wold-style-cast -Wconversion -Wsuggest-override>
        $<$<CONFIG:Debug>:-Og -g3 -ggdb>
        $<$<CONFIG:Release>:-O3 -g0>)
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
        /W4
        /w14640
        /permissive)
endif()

# Include files
set(INCLUDE_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(myProject PRIVATE
    ${INCLUDE_DIRECTORIES})

add_subdirectory(tests)
