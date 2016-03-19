project(CPX)
cmake_minimum_required(VERSION 2.8.3)

include(detectOS.cmake)
add_definitions(-DOS_${OSNAME})


set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic -std=c++0x -Wno-unused-parameter -Wno-missing-braces ${CMAKE_CXX_FLAGS}" )

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

add_library(cpx SHARED
    src/PluginFactory.cpp
    src/LibraryLoader.cpp
)

if (OSNAME STREQUAL "LINUX")
    target_link_libraries(cpx dl)
endif (OSNAME STREQUAL "LINUX")


OPTION(ENABLE_TEST "Build tests" ON)

if (ENABLE_TEST)
    add_subdirectory(test)
endif (ENABLE_TEST)









