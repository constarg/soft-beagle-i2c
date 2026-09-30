.section .gp_header, "a"
.word __image_size
.word _start

.section .text.boot, "ax"
.arm

.global _start
_start:
    msr     cpsr_c, #0xD3          

    ldr     sp, =_stack_top

    ldr     r0, =__bss_start
    ldr     r1, =__bss_end
    mov     r2, #0
init:  cmp     r0, r1
    strlo   r2, [r0], #4
    blo     init

    bl      main
