#include "am335x_cm_registers.h"
#include "am335x_gpio_registers.h"

int
main(void)
{
    CM_PER_REGS->cm_per_gpio1_clkctrl &= ~(0x3U << 0);
    CM_PER_REGS->cm_per_gpio1_clkctrl |= (0x2 << 0);

    while ((CM_PER_REGS->cm_per_gpio1_clkctrl >> 16) & 0x3U) {}

    GPIO1_REGS->gpio_ctrl &= ~(1U << 0);
    GPIO1_REGS->gpio_oe &= ~(1U << 21);
    GPIO1_REGS->gpio_oe &= ~(1U << 22);
    GPIO1_REGS->gpio_oe &= ~(1U << 23);
    GPIO1_REGS->gpio_oe &= ~(1U << 24);

    while (1) {
        GPIO1_REGS->gpio_setdataout = (1U << 21);
        for (volatile int i = 0; i < 1000000; i++) {}

        GPIO1_REGS->gpio_setdataout = (1U << 22);
        for (volatile int i = 0; i < 1000000; i++) {}

        GPIO1_REGS->gpio_setdataout = (1U << 23);
        for (volatile int i = 0; i < 1000000; i++) {}

        GPIO1_REGS->gpio_setdataout = (1U << 24);
        for (volatile int i = 0; i < 1000000; i++) {}

        GPIO1_REGS->gpio_cleardataout = (1U << 21);
        for (volatile int i = 0; i < 1000000; i++) {}

        GPIO1_REGS->gpio_cleardataout = (1U << 22);
        for (volatile int i = 0; i < 1000000; i++) {}

        GPIO1_REGS->gpio_cleardataout = (1U << 23);
        for (volatile int i = 0; i < 1000000; i++) {}

        GPIO1_REGS->gpio_cleardataout = (1U << 24);
        for (volatile int i = 0; i < 1000000; i++) {}
    }

    return 0;
}
