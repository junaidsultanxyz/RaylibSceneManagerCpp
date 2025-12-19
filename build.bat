@echo off
echo Building Raylib Scene Management Project for Windows...
echo.

REM Check if build directory exists
if not exist build (
    echo Creating build directory...
    mkdir build
)

cd build

REM Configure and build
echo Configuring CMake...
cmake --preset default ..
if %errorlevel% neq 0 (
    echo CMake configuration failed!
    cd ..
    exit /b %errorlevel%
)

echo.
echo Building project...
cmake --build . --config Debug
if %errorlevel% neq 0 (
    echo Build failed!
    cd ..
    exit /b %errorlevel%
)

echo.
echo Build completed successfully!
echo Executable location: build\src\Game\Game.exe
cd ..

set /p toRun="Would you like to launch the game? (y/n): "
if /i "%toRun%"=="y" goto run
if /i "%toRun%"=="yes" goto run
echo Game not launched. You can run it later with: build\src\Game\Game.exe
goto end

:run
echo Launching game...
start "" "%CD%\build\src\Game\Game.exe"

:end
