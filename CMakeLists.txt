project(plugin_demo)

set(CMAKE_CXX_STANDARD 17)

add_library(plugin STATIC
        plugin/registry.cpp
        plugin/impl/Circle.cpp
        )

target_include_directories(plugin PUBLIC plugin)

add_executable(demo main.cpp)

target_link_libraries(demo plugin)