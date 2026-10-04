ENTRY(_start)

MEMORY
{
    HDR  (r)   : ORIGIN = 0x402F03F8, LENGTH = 8
    SRAM (rwx) : ORIGIN = 0x402F0400, LENGTH = 64K
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

_irq_undefined_addr       = 0x4030CE24;
_irq_swi_addr             = 0x4030CE28;
_irq_pre_fetch_abort_addr = 0x4030CE2C;
_irq_data_abort_addr      = 0x4030CE30;
_irq_unused_addr          = 0x4030CE34;
_irq_irq_addr             = 0x4030CE38;
_irq_fiq_addr             = 0x4030CE3C;

ASSERT(_start == 0x402F0400, "ensure that _start starts from the base of the on-chip memory")
