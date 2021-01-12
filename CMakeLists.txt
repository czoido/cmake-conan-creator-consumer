cmake_minimum_required(VERSION 3.1)
project(mypkg CXX)

if(CONAN_EXPORTED) 
    message("-----> LOCAL CACHE <------")
    # in conan local cache
    # we are creating the package doing:
    # > conan create .
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message("------> USER SPACE <-------")
    # user space, we are testing the library doing:
    # > mkdir build && cd build
    # > cmake .. -DCMAKE_BUILD_TYPE=Release
    # > cmake --build .  
    # define requires in conanfile.py not in conan_cmake_run as arguments 
    if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
        message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
        file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/develop/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake"  TLS_VERIFY ON)
        endif()
    include(${CMAKE_BINARY_DIR}/conan.cmake)
    # Make sure to use conanfile.py to define dependencies, to stay consistent
    conan_cmake_run(CONANFILE conanfile.py BASIC_SETUP)
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(mypkg mypkg.cpp)
