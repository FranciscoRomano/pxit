$Env:CMAKE_GENERATOR = "Ninja"
if (-not(Test-Path "$PSScriptRoot/build" -PathType Container))
{ cmake -S "$PSScriptRoot" -B "$PSScriptRoot/build" }
cmake --build ./build