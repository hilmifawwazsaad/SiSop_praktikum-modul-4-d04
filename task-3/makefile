prepare:
	mkdir -p bin
	dd if=/dev/zero of=bin/floppy.img bs=512 count=2880

bootloader: 
	nasm -f bin src/bootloader.asm -o bin/bootloader.bin
	dd if=bin/bootloader.bin of=bin/floppy.img bs=512 count=1 conv=notrunc

stdlib:
	bcc -ansi -c -Iinclude src/std_lib.c -o bin/std_lib.o

kernel: 
	nasm -f as86 src/kernel.asm -o bin/kernel_asm.o
	bcc -ansi -c -Iinclude src/kernel.c -o bin/kernel.o
	ld86 -o bin/kernel -d bin/kernel.o bin/kernel_asm.o	

link:
	dd if=bin/bootloader.bin of=bin/floppy.img bs=512 count=1 conv=notrunc
	dd if=bin/kernel.o of=bin/floppy.img bs=512 seek=1 conv=notrunc
	dd if=bin/kernel_asm.o of=bin/floppy.img bs=512 seek=10 conv=notrunc
	dd if=bin/std_lib.o of=bin/floppy.img bs=512 seek=20 conv=notrunc

build: prepare bootloader stdlib kernel link

run:
	bochs -f bochsrc.txt 

clean:
	rm -f bin/*.o bin/*.bin bin/*.img

.PHONY: prepare bootloader stdlib kernel link build run clean
