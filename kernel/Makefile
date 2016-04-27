PROJROOT = ..
BDIR = $(PROJROOT)/bin

AS = nasm
CC = ~/opt/i386-elf-4.9.1-Linux-x86_64/bin/i386-elf-gcc
LD = ~/opt/i386-elf-4.9.1-Linux-x86_64/bin/i386-elf-ld
AFLAGS = -f elf32
CFLAGS = -I . -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdlib -nostdinc -fno-builtin -ffreestanding -std=gnu99
LDFLAGS = -I . -T $(PROJROOT)/build/linker.ld

ASMOBJS = boot.o
COBJS = kernel.o string.o system.o vga.o gdt.o idt.o isr.o irq.o pic.o pit.o ps2_kb.o stdlib.o
OBJS = $(ASMOBJS) $(COBJS)

KERNELIMAGE = $(BDIR)/stark_os.bin

.PHONY: all clean

%.o: %.asm
	$(AS) $(AFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(OBJS)
	$(LD) $(LDFLAGS) -o $(KERNELIMAGE) $^
	rm -f *.o

clean:
	rm -f $(KERNELIMAGE)
	rm -f *.o
