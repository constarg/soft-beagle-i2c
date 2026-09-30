ENTRY(_start)

MEMORY
{
    HDR  (r)   : ORIGIN = 0x402F03F8, LENGTH = 8
    SRAM (rwx) : ORIGIN = 0x402F0400, LENGTH = 0x1B400
}

SECTIONS
{
    .gp_header : { 
        KEEP(*(.gp_header))
    } > HDR

    .text : {
        *(.text.boot)
        *(.text*)
        *(.rodata*)
    } > SRAM

    .data : {
        *(.data*)
    } > SRAM
    __image_end = .; 

    .bss (NOLOAD) : {
        . = ALIGN(4);
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end = .;
    } > SRAM
}

__image_size = __image_end - _start;
_stack_top = 0x4030FF00;
ASSERT(_start == 0x402F0400, "ensure that _start starts from the base of the on-chip memory")
