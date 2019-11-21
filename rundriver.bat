@echo off
set arg1=%1
set var=
setlocal enabledelayedexpansion
FOR /R "src/adt/" %%g IN (*.c) DO ( 
   (Echo "%%g" | FIND /I "driver.c" 1>NUL) || (
        set var=!var!  %%g
   )
)
set var=!var! src/adt/%arg1%/driver.c
cls && echo Compiling driver for %arg1%... && gcc -Wall !var! -o bin/%arg1%_driver && echo Compilation done! && pause && cls && bin\%arg1%_driver
endlocal