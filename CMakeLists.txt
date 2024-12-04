#------------------------------------------------------------------------------------------------------------------------------#
# https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-To-Write-Platform-Checks
# https://cmake.org/cmake/help/latest/variable/CMAKE_SYSTEM_NAME.html
# https://gitlab.kitware.com/cmake/cmake
#------------------------------------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project(pxit)
#------------------------------------------------------------------------------------------------------------------------------#
# Platform #####################################################################################################################

# GNU/Linux Operating System
set(IS_PLATFORM_LINUX OFF)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(IS_PLATFORM_LINUX ON)
endif()

# Microsoft Windows Operating System
set(IS_PLATFORM_WINDOWS OFF)
if(MINGW)
  set(IS_PLATFORM_WINDOWS ON)
elseif(CMAKE_SYSTEM_NAME STREQUAL "MSYS" OR MSYS)
  set(IS_PLATFORM_WINDOWS ON)
elseif(CMAKE_SYSTEM_NAME STREQUAL "CYGWIN")
  set(IS_PLATFORM_WINDOWS ON)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows" OR WIN32)
  set(IS_PLATFORM_WINDOWS ON)
endif()

#------------------------------------------------------------------------------------------------------------------------------#
# C/C++ Compilers ##############################################################################################################

# GNU Compiler Collection (GCC)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
endif()

# Microsoft Visual C++ Compiler (MSVC)
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
endif()

#------------------------------------------------------------------------------------------------------------------------------#
# Project Configuration ########################################################################################################

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/src/core")
add_executable(pxit "${CMAKE_CURRENT_LIST_DIR}/src/main.c")
target_link_libraries(pxit PUBLIC core)

if(IS_PLATFORM_LINUX)
  target_compile_definitions(pxit PRIVATE "IS_PLATFORM_LINUX")
endif()

if(IS_PLATFORM_WINDOWS)
  #target_link_options(pxit PRIVATE -static -mwindows)
  target_compile_definitions(pxit PRIVATE "IS_PLATFORM_WINDOWS")
endif()

#------------------------------------------------------------------------------------------------------------------------------#