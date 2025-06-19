all: kernel.bin

kernel.bin: loader.o kernel.o
	ld -m elf_i386 -T linker.ld -o kernel.elf loader.o kernel.o
	grub-file --is-x86-multiboot kernel.elf
	mkdir -p isodir/boot/grub
	cp kernel.elf isodir/boot/kernel.elf
	echo 'set timeout=0' > isodir/boot/grub/grub.cfg
	echo 'set default=0' >> isodir/boot/grub/grub.cfg
	echo 'menuentry "My OS" {' >> isodir/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.elf' >> isodir/boot/grub/grub.cfg
	echo '}' >> isodir/boot/grub/grub.cfg
	grub-mkrescue -o kernel.iso isodir

loader.o: loader.s
	as --32 loader.s -o loader.o

kernel.o: kernel.cpp
	g++ -m32 -ffreestanding -c kernel.cpp -o kernel.o

clean:
	rm -rf *.o *.iso *.elf isodir
