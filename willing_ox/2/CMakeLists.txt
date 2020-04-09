set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

add_executable(stack stack.cpp)
target_link_libraries(stack)

add_executable(queue queue.cpp)
target_link_libraries(queue)