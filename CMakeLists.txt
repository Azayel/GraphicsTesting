cmake_minimum_required(VERSION 3.21)
project(Visualization)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glfw3 REQUIRED)



file(GLOB SOURCES "src/*.cpp")
add_executable(Visualization ${SOURCES} src/glad.c)

target_include_directories(Visualization PUBLIC includes/)
target_link_libraries(Visualization glfw dl)



