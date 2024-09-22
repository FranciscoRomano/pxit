#--------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/src/platform")
#--------------------------------------------------------------------------------------------------#
project(pxit)
add_executable(pxit
  "${CMAKE_CURRENT_LIST_DIR}/src/main.c"
)
target_link_libraries(pxit PUBLIC pxit_platform)
target_include_directories(pxit PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
target_include_directories(pxit PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/OpenGL")
#target_link_options(pxit PRIVATE -static)
#--------------------------------------------------------------------------------------------------#