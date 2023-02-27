cmake_minimum_required(VERSION 3.10)
project(plugin_demo)

set(CMAKE_CXX_STANDARD 17)

add_library(shape STATIC
        plugin/registry.cpp
        plugin/impl/Circle.cpp
        )

target_include_directories(shape PUBLIC plugin)

add_executable(demo main.cpp)

target_link_libraries(demo shape)
target_link_options(shape INTERFACE -u__ZN6Circle12m_registeredE)