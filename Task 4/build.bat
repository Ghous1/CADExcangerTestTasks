@echo off

set project_name=%1
set path=%~2

cd %path%

mkdir build

echo cmake_minimum_required(VERSION 3.25) > CMakeLists.txt
echo project(%project_name%) >> CMakeLists.txt

for %%i in (*.cpp) do (
	if %%~i==main.cpp (echo set^(SOURCE_EXE %%~i^) >> CMakeLists.txt) else (echo set^(SOURCE_LIB %%~i^) >>CMakeLists.txt )
)

for %%i in (*.h) do echo add_library(%%~ni SHARED ${SOURCE_LIB}) >> CMakeLists.txt

echo add_executable(main ${SOURCE_EXE}) >> CMakeLists.txt
echo target_link_libraries(main triangle_area)	>> CMakeLists.txt

set strTemp=target_link_libraries^(main 
for %%i in (*.h) do (set strTemp= strTemp %%~ni)
set strTemp=strTemp^) >> CMakeLists.txt 

cd build

C:\Program^ Files\CMake\bin\cmake.exe ..
start "" "C:\Program Files\CMake\bin\cmake.exe" --build .