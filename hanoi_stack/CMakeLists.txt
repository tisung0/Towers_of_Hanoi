# hanoi_stack subfolder

add_library(hanoi_stack STATIC
    src/disk.cpp
    src/myStack.cpp
    src/board.cpp
)

target_include_directories(hanoi_stack PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
