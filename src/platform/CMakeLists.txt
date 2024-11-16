#------------------------------------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
#------------------------------------------------------------------------------------------------------------------------------#
# Project Configuration ########################################################################################################

project(platform)
add_library(platform)
target_include_directories(platform PUBLIC "${CMAKE_SOURCE_DIR}/include")

if(IS_PLATFORM_LINUX)
  find_package(X11 REQUIRED)
  target_sources(platform PRIVATE "${CMAKE_CURRENT_LIST_DIR}/X11/library.c")
  target_sources(platform PRIVATE "${CMAKE_CURRENT_LIST_DIR}/X11/window.c")
  target_include_directories(platform PRIVATE "${X11_INCLUDE_DIR}")
endif()

if(IS_PLATFORM_WINDOWS)
  target_sources(platform PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Win32/context.c")
endif()

#------------------------------------------------------------------------------------------------------------------------------#