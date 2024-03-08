cmake_minimum_required(VERSION 3.20.0)
project(monitor LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

enable_testing()
include(CTest)
add_executable(window usage.cpp)
target_link_libraries(window X11)