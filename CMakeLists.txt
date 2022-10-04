# CMakeList.txt : CMake project for Conways-Game-Of-Life, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

SET(PROJECT_NAME Conways-Game-Of-Life)
project(${PROJECT_NAME})

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(src)
add_subdirectory(lib)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PUBLIC
glfw
)