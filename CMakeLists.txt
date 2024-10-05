#--------------------------------------------------------------------------------------------------#
# https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-To-Write-Platform-Checks
# https://cmake.org/cmake/help/latest/variable/CMAKE_SYSTEM_NAME.html
# https://gitlab.kitware.com/cmake/cmake
#--------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project(pxit)

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

#--------------------------------------------------------------------------------------------------#
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/src/platform")
#--------------------------------------------------------------------------------------------------#
add_executable(pxit
  "${CMAKE_CURRENT_LIST_DIR}/src/main.c"
  "${CMAKE_CURRENT_LIST_DIR}/src/core/display.c"
)
target_link_libraries(pxit PUBLIC px_platform)
#--------------------------------------------------------------------------------------------------#