@echo off
echo Starting debugger...
 
start st-util
 
arm-none-eabi-gdb -ex "target extended-remote :4242" .\builds\LinApp.elf
 
taskkill /im st-util.exe /f
 
echo Debugger closed...
 