cmake_minimum_required(VERSION 3.28.3)

set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(scratch++)

add_executable(${PROJECT_NAME} src/compiler/test.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)
