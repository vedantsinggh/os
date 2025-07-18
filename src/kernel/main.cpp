#include "../../include/tty.h"

extern "C" void kernelMain() {
    terminal_initialize();
    terminal_write("Hello from my new OS!\n");
}
