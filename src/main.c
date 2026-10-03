#include "am335x_cm_registers.h"
#include "am335x_gpio_registers.h"
#include "am335x_registers.h"

#define SCL_PIN (6)
#define SDL_PIN (7)

void
i2c_start(void)
{
    g_gpio1_registers->gpio_dataout &= ~(1U << SDL_PIN);
    g_gpio1_registers->gpio_dataout &= ~(1U << SCL_PIN);
}

void
i2c_end(void)
{
    g_gpio1_registers->gpio_dataout |= (1U << SCL_PIN);
    g_gpio1_registers->gpio_dataout |= (1U << SDL_PIN);
}

void
i2c_init(void)
{
    g_cm_per_registers->cm_per_gpio1_clkctrl &= ~(0x3U << 0);
    g_cm_per_registers->cm_per_gpio1_clkctrl |= (0x2 << 0);

    while ((g_cm_per_registers->cm_per_gpio1_clkctrl >> 16) & 0x3U) {}

    g_gpio1_registers->gpio_ctrl &= ~(1U << 0);
    g_gpio1_registers->gpio_oe &= ~(1U << SCL_PIN);
    g_gpio1_registers->gpio_oe &= ~(1U << SDL_PIN);

    i2c_end();
}

int
main(void)
{
    i2c_init();

    while (1) {
        i2c_start();

        for (volatile int i = 0; i < 1000; i++) {}

        i2c_end();

        for (volatile int i = 0; i < 1000; i++) {}
    }

    return 0;
}
