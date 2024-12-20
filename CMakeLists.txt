#------------------------------------------------------------------------------------------------------------------------------#
# https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-To-Write-Platform-Checks
# https://cmake.org/cmake/help/latest/variable/CMAKE_SYSTEM_NAME.html
# https://gitlab.kitware.com/cmake/cmake
#------------------------------------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project(pxit)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#------------------------------------------------------------------------------------------------------------------------------#
# Platform #####################################################################################################################

# GNU/Linux Operating System
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(IS_PLATFORM_LINUX ON)
  add_compile_definitions("IS_PLATFORM_LINUX=1")
else()
  set(IS_PLATFORM_LINUX OFF)
  add_compile_definitions("IS_PLATFORM_LINUX=0")
endif()

# Microsoft Windows Operating System
if(MINGW)
  set(IS_PLATFORM_WINDOWS ON)
  add_compile_definitions("IS_PLATFORM_WINDOWS=1")
elseif(CMAKE_SYSTEM_NAME STREQUAL "MSYS" OR MSYS)
  set(IS_PLATFORM_WINDOWS ON)
  add_compile_definitions("IS_PLATFORM_WINDOWS=1")
elseif(CMAKE_SYSTEM_NAME STREQUAL "CYGWIN")
  set(IS_PLATFORM_WINDOWS ON)
  add_compile_definitions("IS_PLATFORM_WINDOWS=1")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows" OR WIN32)
  set(IS_PLATFORM_WINDOWS ON)
  add_compile_definitions("IS_PLATFORM_WINDOWS=1")
else()
  set(IS_PLATFORM_WINDOWS OFF)
  add_compile_definitions("IS_PLATFORM_WINDOWS=0")
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
target_link_libraries(pxit PUBLIC -lm)

if(IS_PLATFORM_LINUX)
  target_compile_definitions(pxit PRIVATE "IS_PLATFORM_LINUX")
endif()

if(IS_PLATFORM_WINDOWS)
  target_link_options(pxit PRIVATE -static)
  #target_link_options(pxit PRIVATE -mwindows)
  target_compile_definitions(pxit PRIVATE "IS_PLATFORM_WINDOWS")
endif()

#------------------------------------------------------------------------------------------------------------------------------#