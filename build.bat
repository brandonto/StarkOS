@echo off

if not exist "./bin" mkdir "./bin"
del ./bin/stark_os.bin 2>NUL 1>NUL

echo Assembling...
nasm -f elf32 -o boot.o ./kernel/boot.asm
echo Assembling complete.

echo Compiling...
rem i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -S -o kernel.s ./kernel/kernel.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o kernel.o ./kernel/kernel.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o string.o ./kernel/string.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o system.o ./kernel/system.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o vga.o ./kernel/vga.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o gdt.o ./kernel/gdt.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o idt.o ./kernel/idt.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o isr.o ./kernel/isr.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o irq.o ./kernel/irq.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o pic.o ./kernel/pic.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o pit.o ./kernel/pit.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o ps2_kb.o ./kernel/ps2_kb.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o stdlib.o ./kernel/stdlib.c
echo Compiling complete.

echo Linking...
i686-elf-ld -T ./build/linker.ld -o ./bin/stark_os.bin boot.o kernel.o string.o system.o vga.o gdt.o idt.o isr.o irq.o pic.o pit.o ps2_kb.o stdlib.o
echo Linking complete.

del *.o

pause

