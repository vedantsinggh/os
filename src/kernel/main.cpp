#include "../../include/tty.h"
#include "../../include/idt.h"

extern "C" void kernelMain() {
    terminal_initialize();
    terminal_write("Installing IDT...\n");

    idt_install();

    terminal_write("Triggering interrupt...\n");

    // Trigger INT 0 (divide by zero exception)
    asm volatile ("int $0");

    terminal_write("Still running!\n");
}
