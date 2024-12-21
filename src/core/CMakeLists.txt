#------------------------------------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
#------------------------------------------------------------------------------------------------------------------------------#
# Project Configuration ########################################################################################################

project(core)
add_library(core)
target_include_directories(core PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gles.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gles20.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gles30.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gles31.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gles32.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/window.c")

if(IS_PLATFORM_LINUX)
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_glx.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_x11.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/window_x11.c")
endif()

if(IS_PLATFORM_WINDOWS)
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/api/gdi32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/api/opengl32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/api/user32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_wgl.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_win32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/window_win32.c")
endif()

#------------------------------------------------------------------------------------------------------------------------------#