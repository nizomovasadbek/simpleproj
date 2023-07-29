ASMC=nasm
ASM_FLAG=-f bin
CC=i386-elf-gcc
LD=i386-elf-ld
LD_FLAG=-Map=output.map -g
CC_FLAG=-I$(SRC)/kernel/std -I$(SRC)/kernel/vga -I$(SRC)/kernel/io_port \
-I$(SRC)/kernel/mem -I$(SRC)/kernel/keyboard \
-Ttext 0x1000 -ffreestanding -Wall -Wextra -O3 -nostdlib -fno-builtin -fno-builtin-functions -g
BUILD=build
SRC=src
MAIN=main.img

C_SOURCES=$(wildcard $(SRC)/kernel/*.c $(SRC)/kernel/io_port/*.c $(SRC)/kernel/keyboard/*.c \
	$(SRC)/kernel/std/*.c $(SRC)/kernel/vga/*.c $(SRC)/kernel/mem/*.c)
ASM_SOURCES=$(SRC)/kernel/kernel_entry.asm
ASM_OBJS=$(patsubst $(SRC)/%.asm,$(BUILD)/%.o,$(ASM_SOURCES))
C_OBJS=$(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(C_SOURCES))
KERNEL=$(BUILD)/kernel/kernel.elf

all: promise bootloader $(ASM_OBJS) $(KERNEL) finish

finish:
	$(LD) $(LD_FLAG) $(KERNEL) -o $(BUILD)/kernel/kernel.bin --oformat binary
	dd if=/dev/zero of=$(BUILD)/$(MAIN) bs=512 count=2880
	dd if=$(BUILD)/boot/bootloader.bin of=$(BUILD)/$(MAIN) conv=notrunc
	dd if=$(BUILD)/kernel/kernel.bin of=$(BUILD)/$(MAIN) conv=notrunc seek=1 bs=512

$(KERNEL): $(ASM_OBJS) $(C_SOURCES)
	$(CC) $(CC_FLAG) $^ -o $@

$(ASM_OBJS): $(ASM_SOURCES)
	$(ASMC) -f elf32 $< -o $@ -g

bootloader:
	$(ASMC) $(ASM_FLAG) $(SRC)/boot/bootloader.asm -o $(BUILD)/boot/bootloader.bin

promise:
	mkdir -p $(BUILD)/{boot,kernel}
	mkdir -p $(BUILD)/kernel/{vga,io_port,std,keyboard}

run:
	qemu-system-i386 -fda $(BUILD)/$(MAIN)

clean:
	rm -rf $(BUILD)

debug:
	qemu-system-i386 -fda $(BUILD)/$(MAIN) -s -S
