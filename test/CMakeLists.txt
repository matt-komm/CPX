add_executable(cpx-test
    test.cpp
)
target_link_libraries(cpx-test cpx)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(cpx-test-plugin MODULE
    TestPlugin.cpp
)
set_target_properties(cpx-test-plugin PROPERTIES OUTPUT_NAME "test-plugin")
set_target_properties(cpx-test-plugin PROPERTIES PREFIX "")
set_target_properties(cpx-test-plugin PROPERTIES SUFFIX ".cpx")
target_link_libraries(cpx-test-plugin cpx)
