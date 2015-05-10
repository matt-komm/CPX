add_executable(cpx-test
    test.cpp
)
#target_link_libraries(cpx-test cpx)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(cpx-test-plugin MODULE
    TestPlugin.cpp
)
#target_link_libraries(cppps-test-plugin cpx)
