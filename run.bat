cls && echo Compiling... && gcc -Wall src/adt/*/*.c src/*/*.c src/*.c -o bin\game && echo Compilation done! && pause && bin\game
@echo off
set var=
setlocal enabledelayedexpansion
FOR /R "src/" %%g IN (*.c) DO ( 
   (Echo "%%g" | FIND /I "driver.c" 1>NUL) || (
        set var=!var!  %%g
   )
)
cls && echo Compiling main... && gcc -Wall !var! -o bin/game && echo Compilation done! && pause && cls && bin\game
endlocal