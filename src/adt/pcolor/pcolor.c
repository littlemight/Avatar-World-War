#include "pcolor.h"

void red() {
    printf("%s", RED);
}

void green() {
    printf("%s", GREEN);
}

void yellow() {
    printf("%s", YELLOW);
}

void blue() {
    printf("%s", BLUE);
}

void magenta() {
    printf("%s", MAGENTA);
}

void cyan() {
    printf("%s", CYAN);
}

void normal() {
    printf("%s", NORMAL);
}

void reverse() {
    printf("%s", REVERSE);
}

void red_bg() {
    printf("%s", REDBG);
}

void blue_bg() {
    printf("%s", BLUEBG);
}

void print_red(char c) {
    printf("%s%c", RED, c);
    printf("%s", NORMAL);
}

void print_green(char c) {
    printf("%s%c", GREEN, c);
    printf("%s", NORMAL);
}

void print_yellow(char c) {
    printf("%s%c", YELLOW, c);
    printf("%s", NORMAL);
}

void print_blue(char c) {
    printf("%s%c", BLUE, c);
    printf("%s", NORMAL);
}

void print_magenta(char c) {
    printf("%s%c", MAGENTA, c);
    printf("%s", NORMAL);
}

void print_cyan(char c) {
    printf("%s%c", CYAN, c);
    printf("%s", NORMAL);
}
