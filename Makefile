ASMC=nasm
ASM_FLAG=-f bin
CC=i386-elf-gcc
LD=i386-elf-ld
CC_FLAG=-ffreestanding -c -Wall -Wextra -O3 -nostdlib
BUILD=build
SRC=src
MAIN=main.img

all: promise bootloader entry vga kernel link finish

entry:
	$(ASMC) -f elf32 $(SRC)/kernel/kernel_entry.asm -o $(BUILD)/kernel/kernel_entry.o

vga:
	$(CC) $(CC_FLAG) $(SRC)/kernel/vga/screen.c -o $(BUILD)/kernel/vga/screen.o

link:
	$(LD) -o $(BUILD)/kernel/kernel.bin -Ttext 0x1000 $(BUILD)/kernel/kernel_entry.o $(BUILD)/kernel/kernel.o $(BUILD)/kernel/vga/screen.o --oformat binary

kernel:
	$(CC) $(CC_FLAG) $(SRC)/kernel/kernel.c -o $(BUILD)/kernel/kernel.o

finish:
	dd if=/dev/zero of=$(BUILD)/$(MAIN) bs=512 count=2880
	dd if=$(BUILD)/boot/bootloader.bin of=$(BUILD)/$(MAIN) conv=notrunc
	dd if=$(BUILD)/kernel/kernel.bin of=$(BUILD)/$(MAIN) conv=notrunc seek=1 bs=512

bootloader:
	$(ASMC) $(ASM_FLAG) $(SRC)/boot/bootloader.asm -o $(BUILD)/boot/bootloader.bin

promise:
	mkdir -p $(BUILD)/{boot,kernel}
	mkdir -p $(BUILD)/kernel/vga

run:
	qemu-system-i386 -fda $(BUILD)/$(MAIN)

clean:
	rm -rf $(BUILD)