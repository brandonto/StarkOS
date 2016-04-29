/*
 * linker.ld
 *
 * Linker script for the kernel. Taken from:
 * http://wiki.osdev.org/Bare_Bones#Linking_the_Kernel
 *
 */

/* The bootloader will look at this image and start execution at the symbol
designated as the entry point. */
ENTRY(_start)

/* Tell where the various sections of the object files will be put in the final
kernel image. */
SECTIONS
{
    /* Begin putting sections at 1MB. */
    . = 0x00100000;

    /* Physical kernel starting memory location is at 1MB */
    kernel_physical_start = .;

    /* First put the multiboot header, as it is required to be put very early
       early in the image or the bootloader won't recognize the file format.
       Next we'll put the .text section. */
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
            *(.text)
    }

    /* Read-only data. */
    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    /* Read-write data (initialized) */
    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    /* Read-write data (uninitialized) and stack */
    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
            *(.bss)
            *(.bootstrap_stack)
    }

    /* The compiler may produce other sections, by default it will put them in
       a segment with the same name. Simply add stuff here as needed. */

    /* Physical kernel ending memory location */
    kernel_physical_end = .;
}

