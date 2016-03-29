;
; start.asm
;
; Entry point for Kernel. Taken from Bran's Kernel Development.
;

[BITS 32]

global start

; Set up stack pointer
start:
    mov esp, _sys_stack
    jmp stublet

; This part MUST be 4byte aligned, so we solve that issue using 'ALIGN 4'
ALIGN 4
mboot:
    ; Multiboot macros to make a few lines later more readable
    MULTIBOOT_PAGE_ALIGN    equ 1<<0
    MULTIBOOT_MEMORY_INFO   equ 1<<1
    MULTIBOOT_AOUT_KLUDGE   equ 1<<16
    MULTIBOOT_HEADER_MAGIC  equ 0x1BADB002
    MULTIBOOT_HEADER_FLAGS  equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE
    MULTIBOOT_CHECKSUM      equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
    EXTERN code, bss, end

    ; This is the GRUB Multiboot header. A boot signature
    dd MULTIBOOT_HEADER_MAGIC
    dd MULTIBOOT_HEADER_FLAGS
    dd MULTIBOOT_CHECKSUM

    ; AOUT kludge - must be physical addresses.
    dd mboot
    dd code
    dd bss
    dd end
    dd start

; Call main and sit in infinite loop.
stublet:
    extern main
    call main
    jmp $

; Load the GDT
global gdt_flush
extern gdtptr
gdt_flush:
    lgdt [gdtptr]   ; Load GDT
    mov ax, 0x10    ; 0x10 is the offset to data segment
    mov ds, ax      ; Loads every data segment with offset
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; Far jump sets code segment
    jmp 0x08:flush2 ; 0x08 is the offset to code segment
flush2:
    ret

; Load the IDT
global idt_load
extern idtptr
idt_load:
    lidt [idtptr]   ; Load IDT
    ret

; In just a few pages in this tutorial, we will add our Interrupt
; Service Routines (ISRs) right here!



; Stores the stack at the end of the BSS section
SECTION .bss
    resb 8192               ; This reserves 8KBytes of memory here
_sys_stack:

