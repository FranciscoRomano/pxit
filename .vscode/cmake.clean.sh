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
# 4) remove any CMake generated/configuration files in "build" folder
if [[ -d "${WORKSPACE_DIR}/build" ]]; then
  rm -rf "${WORKSPACE_DIR}/build"
fi
# ---------------------------------------------------------------------------------------------------------------------------- #
# 5) remove any ".gitignore" file, directory or any untracked changes from git
if [[ -d "${WORKSPACE_DIR}/.git" ]]; then
  git clean -dfX
fi
# ---------------------------------------------------------------------------------------------------------------------------- #