#!/bin/bash
# ---------------------------------------------------------------------------------------------------------------------------- #
# 1) get the full directory name of the script
# https://stackoverflow.com/questions/59895/how-do-i-get-the-directory-where-a-bash-script-is-located-from-within-the-script
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
# ---------------------------------------------------------------------------------------------------------------------------- #
# 2) check for too many arguments passed to script
if [[ "$#" -ne 0 ]]; then
  #if [[ "$#" -ne 0 || "$0" -ne "$SCRIPT_DIR/cmake.build.sh" || "$1" -ne "" ]]; then
    echo "Error: Too many parameters" 1>&2
    exit 1
  #fi
fi
# ---------------------------------------------------------------------------------------------------------------------------- #
# 3) search for "CMakeLists.txt" in script or work directory
WORKSPACE_DIR=$(pwd)
if [[ ! -f "${WORKSPACE_DIR}/CMakeLists.txt" ]]; then
  WORKSPACE_DIR=$(dirname "${SCRIPT_DIR}")
  if [[ ! -f "${WORKSPACE_DIR}/CMakeLists.txt" ]]; then
    echo "Error: Failed to find CMakeLists.txt" 1>&2
    exit 1
  fi
fi
# ---------------------------------------------------------------------------------------------------------------------------- #
# 4) configure CMake if "build" folder does not exist in work directory
if [[ ! -d "${WORKSPACE_DIR}/build" ]]; then
  if cmake -S "${WORKSPACE_DIR}" -B "${WORKSPACE_DIR}/build"; then
    :
  else
    echo "Error: Failed to configure CMake project" 1>&2
    exit 1
  fi
fi
# ---------------------------------------------------------------------------------------------------------------------------- #
# 5) finally, build all CMake projects in "build" folder
if cmake --build "${WORKSPACE_DIR}/build"; then
  :
else
  echo "Error: Failed to build CMake project" 1>&2
  exit 1
fi
# ---------------------------------------------------------------------------------------------------------------------------- #