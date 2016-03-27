echo Assembling...
nasm -f aout -o start.o start.asm
echo Assembling complete.

echo Compiling...
rem Remember this spot here: We will add 'gcc' commands here to compile C sources

echo Compiling complete.

echo Linking...
rem This links all your files. Remember that as you add *.o files, you need to
rem add them after start.o. If you don't add them at all, they won't be in your kernel!
ld -T link.ld -o kernel.bin start.o
echo Linking complete.

pause

