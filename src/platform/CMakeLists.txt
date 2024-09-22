#--------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
#--------------------------------------------------------------------------------------------------#
project(pxit_platform)
add_library(pxit_platform)
target_include_directories(pxit_platform PUBLIC "${CMAKE_SOURCE_DIR}/include")
#--------------------------------------------------------------------------------------------------#
find_package(X11)
if (${X11_FOUND}) # using X Windowing System (X11)
  target_sources(pxit_platform PRIVATE "${CMAKE_CURRENT_LIST_DIR}/X11/library.c")
  target_compile_definitions(pxit_platform PUBLIC "PX_PLATFORM_USE_X11")
  target_include_directories(pxit_platform PRIVATE "${X11_INCLUDE_DIR}")
endif()
#--------------------------------------------------------------------------------------------------#
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU") # using GNU C/C++ Compiler (GCC)
  # target_link_options(pxit_platform PUBLIC -static)
  # target_link_options(pxit_platform PUBLIC -static-libgcc)
endif()
#--------------------------------------------------------------------------------------------------#
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") # using Visual Studio C/C++ Compiler (MSVC)
  
endif()
#--------------------------------------------------------------------------------------------------#