#------------------------------------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
#------------------------------------------------------------------------------------------------------------------------------#
# Project Configuration ########################################################################################################

project(core)
add_library(core)
target_include_directories(core PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_gles.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/surface.c")

if(IS_PLATFORM_LINUX)
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_glx.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_x11.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/surface_x11.c")
endif()

if(IS_PLATFORM_WINDOWS)
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/library/gdi32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/library/gles.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/library/gles20.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/library/gles30.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/library/gles31.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/library/gles32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/library/opengl32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/library/user32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_wgl.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_win32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/surface_win32.c")
endif()

#------------------------------------------------------------------------------------------------------------------------------#