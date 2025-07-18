#include "../../include/idt.h"

IDTEntry idt[256];
IDTPointer idtp;

extern "C" void idt_flush(uint32_t);  

void idt_set_gate(int n, uint32_t handler) {
    idt[n].base_low = handler & 0xFFFF;
    idt[n].base_high = (handler >> 16) & 0xFFFF;
    idt[n].selector = 0x08;     
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;       
}

void idt_install() {
    idtp.limit = sizeof(IDTEntry) * 256 - 1;
    idtp.base = (uint32_t)&idt;
    idt_flush((uint32_t)&idtp);
}
