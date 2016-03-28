@echo off

del "kernel.bin" 2>NUL 1>NUL

echo Assembling...
nasm -f elf32 -o boot.o ./kernel/boot.asm
echo Assembling complete.

echo Compiling...
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o kernel.o ./kernel/kernel.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o string.o ./kernel/string.c
i686-elf-gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -ffreestanding -std=gnu99 -I./kernel -c -o system.o ./kernel/system.c
echo Compiling complete.

echo Linking...
i686-elf-ld -T ./build/linker.ld -o ./bin/kernel_image.bin boot.o kernel.o string.o system.o
i686-elf-gcc -T ./build/linker.ld -o ./bin/kernel_image.bin -ffreestanding -nostdlib boot.o kernel.o string.o system.o
echo Linking complete.

del *.o

pause

