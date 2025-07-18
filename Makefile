all: kernel.iso

CXX = g++
AS = as
LD = ld

CXXFLAGS = -m32 -ffreestanding -O0 -Wall -Wextra -fno-exceptions -fno-rtti
LDFLAGS = -m elf_i386 -T linker.ld

SRC = src/kernel/main.cpp src/kernel/tty.cpp src/kernel/idt.cpp
OBJ = $(SRC:.cpp=.o) boot/loader.o
DEPS = $(OBJ:.o=.d)

kernel.elf: $(OBJ) boot/loader.o boot/idt_flush.o
	$(LD) $(LDFLAGS) -o $@ $^

kernel.iso: kernel.elf
	mkdir -p isodir/boot/grub
	cp $< isodir/boot/kernel.elf
	echo 'set timeout=0' > isodir/boot/grub/grub.cfg
	echo 'set default=0' >> isodir/boot/grub/grub.cfg
	echo 'menuentry "My OS" {' >> isodir/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.elf' >> isodir/boot/grub/grub.cfg
	echo '}' >> isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

boot/loader.o: boot/loader.s
	$(AS) --32 $< -o $@

boot/idt_flush.o: boot/idt_flush.s
	as --32 $< -o $@

clean:
	rm -rf *.o *.elf *.iso isodir
	find . -name "*.o" -delete
