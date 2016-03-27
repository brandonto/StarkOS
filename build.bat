echo Assembling...
nasm -f elf -o start.o start.asm
echo Assembling complete.

echo Compiling...
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel -c -o kernel.o ./kernel/kernel.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel -c -o string.o ./kernel/string.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel -c -o system.o ./kernel/system.c
echo Compiling complete.

echo Linking...
i686-elf-ld -T link.ld -o kernel.bin start.o kernel.o string.o system.o
echo Linking complete.

pause

