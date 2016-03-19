add_executable(cpx-test
    test.cpp
)
target_link_libraries(cpx-test cpx)
add_custom_target(runtests cpx-test WORKING_DIRECTORY ${PROJECT_BINARY_DIR} )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})


add_library(cpx-test-plugin MODULE
    TestPlugin.cpp
)
set_target_properties(cpx-test-plugin PROPERTIES OUTPUT_NAME "test-plugin")
set_target_properties(cpx-test-plugin PROPERTIES PREFIX "")
set_target_properties(cpx-test-plugin PROPERTIES SUFFIX ".cpx")
target_link_libraries(cpx-test-plugin cpx)


add_library(cpx-test-plugin-copy MODULE
    TestPluginCopy.cpp
)
set_target_properties(cpx-test-plugin-copy PROPERTIES OUTPUT_NAME "test-plugin-copy")
set_target_properties(cpx-test-plugin-copy PROPERTIES PREFIX "")
set_target_properties(cpx-test-plugin-copy PROPERTIES SUFFIX ".cpx")
target_link_libraries(cpx-test-plugin-copy cpx)


add_library(cpx-test-plugin-other MODULE
    TestPluginOther.cpp
)
set_target_properties(cpx-test-plugin-other PROPERTIES OUTPUT_NAME "test-plugin-other")
set_target_properties(cpx-test-plugin-other PROPERTIES PREFIX "")
set_target_properties(cpx-test-plugin-other PROPERTIES SUFFIX ".cpx")
target_link_libraries(cpx-test-plugin-other cpx)
