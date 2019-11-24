/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

/**
Details

print_xxx(c) will print c with xxx color. Import this header to use the declared functions.
We only provide 8 colors. Feel free to modify/add colors if you want to.
**/

#ifndef PCOLOR_H
#define PCOLOR_H

#include <stdio.h>

#define NORMAL "\x1B[0m"
#define RED "\x1B[1;31m"
#define GREEN "\x1B[1;32m"
#define YELLOW "\x1B[1;33m"
#define BLUE "\x1B[1;34m"
#define MAGENTA "\x1B[1;35m"
#define CYAN "\x1B[1;36m"
#define REVERSE "\x1B[7m"
#define REDBG "\x1B[1;41m"
#define BLUEBG "\x1B[1;44m"

void red();
void green();
void yellow();
void blue();
void magenta();
void cyan();
void normal();
void reverse();
void red_bg();
void blue_bg();

void print_red(char c);

void print_green(char c);

void print_yellow(char c);

void print_blue(char c);

void print_magenta(char c);

void print_cyan(char c);

#endif
