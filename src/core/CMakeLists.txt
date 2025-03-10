#------------------------------------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
#------------------------------------------------------------------------------------------------------------------------------#
# Project Configuration ########################################################################################################

project(core)
add_library(core)
target_include_directories(core PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gl20.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gl30.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gl31.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gl32.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/opengl/gles.c")
target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/window.c")

if(IS_PLATFORM_LINUX)
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/linux/libGLX.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/linux/libX11.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/glx_module.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/glx_window.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/x11_module.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/x11_window.c")
endif()

if(IS_PLATFORM_WINDOWS)
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/d3d9.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/dxgi.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/gdi32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/opengl32.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/windows/user32.c")
  #target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/wgl_module.c")
  #target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/wgl_window.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/win32_module.c")
  target_sources(core PRIVATE "${CMAKE_CURRENT_LIST_DIR}/win32_window.c")
endif()

#------------------------------------------------------------------------------------------------------------------------------#