# Minimal x86 Operating System (unnamed yet)

This is a simple 32-bit x86 operating system built from scratch. It includes a basic bootloader written in assembly, a kernel written in C++, and a linker script to define the memory layout. The final output is a bootable ISO image which can be run using QEMU or other emulators.

## Reference Article

This OS is being created by following tutorials and concepts from the following sources:

- [James Molloy's Kernel Development Tutorial](http://www.jamesmolloy.co.uk/tutorial_html/)
- [cfenollosa/os-tutorial](https://github.com/cfenollosa/os-tutorial)
- [OSDev.org Wiki](https://wiki.osdev.org/Main_Page)


### Usage

Build everything:

```sh
make
```

```sh
qemu-system-i386 -cdrom kernel.iso
```

## Notes

- You must have `grub-mkrescue`, `xorriso`, `qemu-system-i386`, and `gcc` toolchain installed.
- This is a learning project — contributions and suggestions are welcome.
