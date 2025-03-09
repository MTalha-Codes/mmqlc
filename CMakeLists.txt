cmake_minimum_required(VERSION 3.25)
project(mmqlc)
set(CMAKE_CXX_STANDARD 23) # C++ standard version
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_subdirectory(src MmQLC)

