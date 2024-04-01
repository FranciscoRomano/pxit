cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project(pxit)
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/OpenGL")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_LIST_DIR}/../bin/")
add_executable(pxit
  "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
)
target_link_libraries(pxit PRIVATE OpenGL)
target_link_options(pxit PRIVATE -mwindows)