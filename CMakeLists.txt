cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(pName rep3)
project(${pName})
add_executable(${pName} src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(ext/glfw)
target_link_libraries(${pName} glfw)

add_subdirectory(ext/glad)
target_link_libraries(${pName} glad)