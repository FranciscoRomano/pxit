#------------------------------------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
#------------------------------------------------------------------------------------------------------------------------------#
# Project Configuration ########################################################################################################

project(core)
add_library(core)
target_include_directories(core PUBLIC "${CMAKE_SOURCE_DIR}/include")

if(IS_PLATFORM_LINUX)
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/linux/libGLX.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/linux/libX11.c")
endif()

if(IS_PLATFORM_WINDOWS)
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/gdi32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/user32.c")
endif()

#------------------------------------------------------------------------------------------------------------------------------#