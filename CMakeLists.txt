cmake_minimum_required(VERSION 3.25)
project(mmqlc)
set(CMAKE_CXX_STANDARD 23) # C++ standard version
find_package(Boost REQUIRED) # Find boost
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})  # If Boost Found then include
else ()
    message(FATAL_ERROR "Boost Was Not Found On Your System !")
endif ()

add_subdirectory(src MmQLC)

