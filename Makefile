ASMC=nasm
ASM_FLAG=-f bin
CC=i386-elf-gcc
LD=i386-elf-ld
CC_FLAG=-ffreestanding -c -Wall -Wextra -O3 -nostdlib -fno-builtin -fno-builtin-functions
BUILD=build
SRC=src
MAIN=main.img

all: promise $(BUILD)/boot/bootloader.bin entry vga io_c $(BUILD)/kernel/kernel.o link finish

io_c:
	$(CC) $(CC_FLAG) $(SRC)/kernel/io_port/io.c -o $(BUILD)/kernel/io_port/ioc.o

entry:
	$(ASMC) -f elf32 $(SRC)/kernel/kernel_entry.asm -o $(BUILD)/kernel/kernel_entry.o

vga:
	$(CC) $(CC_FLAG) $(SRC)/kernel/vga/screen.c -o $(BUILD)/kernel/vga/screen.o

link:
	$(LD) -o $(BUILD)/kernel/kernel.bin -Ttext 0x1000 $(BUILD)/kernel/kernel_entry.o $(BUILD)/kernel/io_port/ioc.o $(BUILD)/kernel/kernel.o $(BUILD)/kernel/vga/screen.o --oformat binary

$(BUILD)/kernel/kernel.o: $(SRC)/kernel/kernel.c
	$(CC) $(CC_FLAG) $< -o $@

finish:
	dd if=/dev/zero of=$(BUILD)/$(MAIN) bs=512 count=2880
	dd if=$(BUILD)/boot/bootloader.bin of=$(BUILD)/$(MAIN) conv=notrunc
	dd if=$(BUILD)/kernel/kernel.bin of=$(BUILD)/$(MAIN) conv=notrunc seek=1 bs=512

$(BUILD)/boot/bootloader.bin: $(SRC)/boot/bootloader.asm
	$(ASMC) $(ASM_FLAG) $< -o $@

promise:
	mkdir -p $(BUILD)/{boot,kernel}
	mkdir -p $(BUILD)/kernel/{vga,io_port}

run:
	qemu-system-i386 -fda $(BUILD)/$(MAIN)

clean:
	rm -rf $(BUILD)