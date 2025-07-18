#pragma once
#include <stdint.h>

struct IDTEntry {
    uint16_t base_low;
    uint16_t selector;
    uint8_t always0;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));

struct IDTPointer {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

void idt_set_gate(int n, uint32_t handler);
void idt_install();
