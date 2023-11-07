cmake_minimum_required(VERSION 3.0.0)

project(wincon VERSION 0.1.0 LANGUAGES C)
add_library(pxit
  ${CMAKE_CURRENT_LIST_DIR}/source/pxit.c
)
target_include_directories(pxit PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include/
)

project(demo_00 LANGUAGES C CXX)
add_executable(demo_00
  ${CMAKE_CURRENT_LIST_DIR}/demos/demo_00.cpp
)
target_link_libraries(demo_00 pxit)
target_include_directories(demo_00 PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include/
)