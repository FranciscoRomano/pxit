#--------------------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
#--------------------------------------------------------------------------------------------------#
project(pxit)
add_executable(pxit
  "${CMAKE_CURRENT_LIST_DIR}/src/OpenGL/GLES20.c"
  "${CMAKE_CURRENT_LIST_DIR}/src/OpenGL/GLES30.c"
  "${CMAKE_CURRENT_LIST_DIR}/src/OpenGL/GLES31.c"
  "${CMAKE_CURRENT_LIST_DIR}/src/OpenGL/GLES32.c"
  "${CMAKE_CURRENT_LIST_DIR}/src/OpenGL/OpenGL_WGL.c"
  "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp"
)
target_include_directories(pxit PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
target_include_directories(pxit PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/OpenGL")
target_link_options(pxit PRIVATE -static)
target_link_options(pxit PRIVATE -mwindows)
#--------------------------------------------------------------------------------------------------#