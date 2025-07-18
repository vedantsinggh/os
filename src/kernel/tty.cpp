#include "../../include/tty.h"
#include <stdint.h>

static uint16_t* video = (uint16_t*)0xb8000;
static int row = 0;
static int col = 0;

void terminal_initialize() {
    for (int i = 0; i < 80 * 25; ++i) {
        video[i] = (0x07 << 8) | ' ';
    }
    row = 0;
    col = 0;
}

void terminal_putchar(char c) {
    if (c == '\n') {
        row++;
        col = 0;
        return;
    }

    int pos = row * 80 + col;
    video[pos] = (0x0F << 8) | c;

    if (++col >= 80) {
        col = 0;
        ++row;
    }
}

void terminal_write(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        terminal_putchar(str[i]);
    }
}
