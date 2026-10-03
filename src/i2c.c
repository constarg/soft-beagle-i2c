
#include "i2c.h"

#include <stdint.h>

#include "am335x_registers.h"

#define SCL_PIN (6)
#define SDL_PIN (7)

void
i2c_start(void)
{
    // First set the SDL HIGH.
    g_gpio1_registers->gpio_dataout &= ~(1U << SDL_PIN);
    // Then, set the SCL HIGH.
    g_gpio1_registers->gpio_dataout &= ~(1U << SCL_PIN);
}

void
i2c_stop(void)
{
    // First set the SCL LOW.
    g_gpio1_registers->gpio_dataout |= (1U << SCL_PIN);
    // Then, set the SDL LOW.
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

    i2c_stop();
}

void
i2c_send_data(uint8_t src)
{
    for (int bit = 0; bit < 8; bit++) {
        if (((src >> bit) & 0x1U) == 0x1) {
            g_gpio1_registers->gpio_setdataout   = (1U << SDL_PIN)
                                                   | (1U << SCL_PIN);
            g_gpio1_registers->gpio_cleardataout = (1U << SDL_PIN)
                                                   | (1U << SCL_PIN);
        } else {
            g_gpio1_registers->gpio_setdataout   = 1U << SCL_PIN;
            g_gpio1_registers->gpio_cleardataout = 1U << SCL_PIN;
        }
    }
}

void
i2c_ack(void)
{
    // TODO: Make the ACK.
}
