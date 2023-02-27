project(plugin_demo)

set(CMAKE_CXX_STANDARD 17)

add_library(plugin STATIC
        plugin/registry.cpp
        )

add_library(circle_shape SHARED
        plugin/impl/Circle.cpp
        )

target_include_directories(plugin PUBLIC plugin)

add_executable(demo main.cpp)

target_link_libraries(demo plugin)

get_target_property(DEMO_OUTPUT_DIR demo RUNTIME_OUTPUT_DIRECTORY)
set_target_properties(circle_shape PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(circle_shape PUBLIC plugin)
target_link_libraries(circle_shape plugin)