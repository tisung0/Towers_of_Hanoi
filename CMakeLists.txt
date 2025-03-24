cmake_minimum_required(VERSION 3.10.0)
project(hanoi LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(hanoi_stack)

add_executable(hanoi hanoi.cpp)

target_link_libraries(hanoi hanoi_stack)
target_include_directories(hanoi PUBLIC ${PROJECT_SOURCE_DIR}/hanoi_stack)