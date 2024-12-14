#------------------------------------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
#------------------------------------------------------------------------------------------------------------------------------#
# Project Configuration ########################################################################################################

project(core)
add_library(core)
target_include_directories(core PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_gles.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/window.c")

if(IS_PLATFORM_LINUX)
  #target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/GLX/module.c")
  #target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/X11/module.c")
  #target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/X11/window.c")
  #target_compile_definitions(core PRIVATE "IS_PLATFORM_LINUX=1")
  target_compile_definitions(core PRIVATE "IS_PLATFORM_LINUX=0")
else()
  target_compile_definitions(core PRIVATE "IS_PLATFORM_LINUX=0")
endif()

if(IS_PLATFORM_WINDOWS)
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_wgl.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/module_win32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/window_win32.c")
  target_compile_definitions(core PRIVATE "IS_PLATFORM_WINDOWS=1")
else()
  target_compile_definitions(core PRIVATE "IS_PLATFORM_WINDOWS=0")
endif()

#------------------------------------------------------------------------------------------------------------------------------#