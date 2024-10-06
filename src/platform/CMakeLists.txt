#--------------------------------------------------------------------------------------------------#
# Project Configuration ############################################################################

  cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
  project(px_platform)
  add_library(px_platform)
  target_include_directories(px_platform PUBLIC "${CMAKE_SOURCE_DIR}/include")

#--------------------------------------------------------------------------------------------------#
# GNU/Linux Operating System #######################################################################

  if(IS_PLATFORM_LINUX)
    # target_sources(px_platform PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Linux/platform.c")
    # X Windowing System (X11)
    find_package(X11 REQUIRED)
    target_sources(px_platform PRIVATE "${CMAKE_CURRENT_LIST_DIR}/WaylandClient/library.c")
    target_sources(px_platform PRIVATE "${CMAKE_CURRENT_LIST_DIR}/X11/library.c")
    target_compile_definitions(px_platform PUBLIC "PX_PLATFORM_USE_X11")
    target_include_directories(px_platform PRIVATE "${X11_INCLUDE_DIR}")
  endif()

#--------------------------------------------------------------------------------------------------#
# Microsoft Windows Operating System ###############################################################

  if(IS_PLATFORM_WINDOWS)
    # target_sources(px_platform PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Windows/platform.c")
  endif()

#--------------------------------------------------------------------------------------------------#
# GNU Compiler Collection (GCC) ####################################################################

  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(IS_PLATFORM_WINDOWS)
      target_link_options(px_platform PUBLIC -static)
      #target_link_options(px_platform PUBLIC -defterm)
      #target_link_options(px_platform PUBLIC -mwindows)
    endif()
  endif()

#--------------------------------------------------------------------------------------------------#
# Microsoft Visual C++ Compiler (MSVC) #############################################################

  if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  endif()

#--------------------------------------------------------------------------------------------------#