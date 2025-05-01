@echo off
setlocal

rem Define directory paths
set SSC_DIR=ssc
set SRC_DIR=%SSC_DIR%\src
set INC_DIR=%SSC_DIR%\inc
set BUILDS_DIR=builds
set OUT_DIR=%BUILDS_DIR%\out
set PLATFORM_DIR=platform

rem Create BUILDS_DIR and OUT_DIR if they do not exist
if not exist "%BUILDS_DIR%" mkdir "%BUILDS_DIR%"
if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"

rem Define compiler and flags
set CC=arm-none-eabi-gcc
set MACH=cortex-m3
set CFLAGS=-c -mcpu=%MACH% -mthumb -std=gnu11 -Wall -O0 -I%INC_DIR%
set LDFLAGS=-nostdlib -T %PLATFORM_DIR%\linker.ld -Wl,-Map=%BUILDS_DIR%\LinApp.map

rem Compile crt.c files in platform directory
for %%f in (%PLATFORM_DIR%\*.c) do (
    %CC% %CFLAGS% -g %%f -o %OUT_DIR%\%%~nf.o
)

rem Compile all source files in src directory
for %%f in (%SRC_DIR%\*.c) do (
    %CC% %CFLAGS% -g %%f -o %OUT_DIR%\%%~nf.o
)

rem Link all object files into LinApp.elf
%CC% %LDFLAGS% -g -o %BUILDS_DIR%\LinApp.elf %OUT_DIR%\*.o

rem Generate LinApp.hex file
arm-none-eabi-objcopy -O ihex %BUILDS_DIR%\LinApp.elf %BUILDS_DIR%\LinApp.hex

echo Build completed.

endlocal
