project(CPX)
cmake_minimum_required(VERSION 2.8.3)

include(DetectOS.cmake)
add_definitions(-DOS_${OSNAME})

#activate C++11 for GCC and Clang. MSVC use it be default.
message(STATUS "Detected Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
endif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
endif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

include_directories(include src)

OPTION(ENABLE_TEST "Build tests" ON)

if (ENABLE_TEST)
    enable_testing()
    # add exta warnings
    if (OSNAME STREQUAL "LINUX")
        set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic -Wno-unused-parameter ${CMAKE_CXX_FLAGS}" )
    endif (OSNAME STREQUAL "LINUX")
    if (OSNAME STREQUAL "WINDOWS")
        set(CMAKE_CXX_FLAGS "/Wall ${CMAKE_CXX_FLAGS}" )
    endif (OSNAME STREQUAL "WINDOWS")
    
    add_subdirectory(test)
endif (ENABLE_TEST)


add_library(cpx SHARED
    src/PluginFactory.cpp
    src/LibraryLoader.cpp
)

if (OSNAME STREQUAL "LINUX")
    target_link_libraries(cpx dl)
endif (OSNAME STREQUAL "LINUX")

if (OSNAME STREQUAL "MACOSX")
    target_link_libraries(cpx dl)
endif (OSNAME STREQUAL "MACOSX")



