@echo off

REM Set the path variables
set BUILD_DIR=out
set EXECUTABLE="cpplogger.exe"
set GPP="g++.exe"
set CMAKE="cmake.exe"
set MAKE="mingw32-make.exe"
set GENERATOR="MinGW Makefiles"

REM Remove old cache folders
if exist %BUILD_DIR% rmdir /s /q %BUILD_DIR%

REM Create the directory
mkdir %BUILD_DIR%

REM Change directory to build directory
cd %BUILD_DIR%

REM Compile the project with CMake gcc and g++ compilers
%CMAKE% -G %GENERATOR% -DCMAKE_CXX_COMPILER=%GPP% -DCMAKE_MAKE_PROGRAM=%MAKE% ..

REM Build the Makefile
REM %CMAKE% --build .
%MAKE%

REM Execute the final binary
%EXECUTABLE%

REM Remove the final binary once executed
cd ..

REM Print the final success message for little nerd happiness after hours of grinding :)
echo "You did it nerd.. Congrats!! Now go and have a break buddy :)"
