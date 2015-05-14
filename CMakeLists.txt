project(CPX)
cmake_minimum_required(VERSION 2.8.3)

include(detectOS.cmake)
add_definitions(-DOS_${OSNAME})


set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic -std=c++0x -Wno-unused-parameter" ${CMAKE_CXX_FLAGS} )
#set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/release)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

add_library(cpx
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


file(
    GLOB headers 
    "${PROJECT_SOURCE_DIR}/include/cpx/*.hpp"
)
install(
    FILES ${headers}
    DESTINATION include/cpx
)


#install(
#    TARGETS cpx
#    DESTINATION libs
#)






