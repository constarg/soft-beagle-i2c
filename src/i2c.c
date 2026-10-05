/**
 * File: i2c.c
 *
 ***********************************************************************
 * Copyright (C) 2026  Constantinos Argyriou
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Email: constarg@pm.me
 ***********************************************************************
 */
#include "i2c.h"

#include <stdint.h>

#include "am335x_registers.h"

#define SCL_PIN (6)
#define SDA_PIN (7)

void
i2c_start(void)
{
    // First set the SDL HIGH.
    g_gpio1_registers->gpio_cleardataout = (1U << SDA_PIN);
    // Then, set the SCL HIGH.
    g_gpio1_registers->gpio_cleardataout = (1U << SCL_PIN);
}

void
i2c_stop(void)
{
    // First set the SCL LOW.
    g_gpio1_registers->gpio_setdataout = (1U << SCL_PIN);
    // Then, set the SDL LOW.
    g_gpio1_registers->gpio_setdataout = (1U << SDA_PIN);
}

void
i2c_init(void)
{
    g_cm_per_registers->cm_per_gpio1_clkctrl &= ~(0x3U << 0);
    g_cm_per_registers->cm_per_gpio1_clkctrl |= (0x2 << 0);

    while ((g_cm_per_registers->cm_per_gpio1_clkctrl >> 16) & 0x3U) {}

    g_gpio1_registers->gpio_ctrl &= ~(1U << 0);
    g_gpio1_registers->gpio_oe &= ~(1U << SCL_PIN);
    g_gpio1_registers->gpio_oe &= ~(1U << SDA_PIN);

    i2c_stop();
}

static void
send_byte(uint8_t src)
{
    for (int bit = 0; bit < 8; bit++) {
        if (((src >> bit) & 0x1U) == 0x1) {
            g_gpio1_registers->gpio_setdataout = (1U << SDA_PIN);
            g_gpio1_registers->gpio_setdataout = (1U << SCL_PIN);

            g_gpio1_registers->gpio_cleardataout = (1U << SDA_PIN);
            g_gpio1_registers->gpio_cleardataout = (1U << SCL_PIN);
        } else {
            g_gpio1_registers->gpio_setdataout   = 1U << SCL_PIN;
            g_gpio1_registers->gpio_cleardataout = 1U << SCL_PIN;
        }
    }
}

void
i2c_send_data(uint8_t src)
{ send_byte(src); }

void
i2c_send_address(uint8_t addr, addr_mode_t mode)
{ send_byte((addr & 0xEF) | (mode << 7)); }

ack_response_t
i2c_ack(void)
{
    uint8_t sampled_sda; /* The sample of the SDA after setting
                            the SCL high. */

    /* Switch the SDA to input, so that the
       master can recieve the ack bit.*/
    g_gpio1_registers->gpio_oe |= (1U << SDA_PIN);
    /* Set the SCL high, to make the target emit the
       ack bit. */
    g_gpio1_registers->gpio_setdataout = (1U << SCL_PIN);

    /* Take a sample of the SDA. */
    sampled_sda = (g_gpio1_registers->gpio_datain >> SDA_PIN) & 0x1;

    /* Drop the SCL down again, which completes a clock cycle. */
    g_gpio1_registers->gpio_cleardataout = (1U << SCL_PIN);

    /* If the device didn't respond, the line should be HIGH. */
    if (0x1U == sampled_sda) {
        /* Restore the SDA. */
        g_gpio1_registers->gpio_oe &= ~(1U << SDA_PIN);
        g_gpio1_registers->gpio_cleardataout = (1U << SDA_PIN);
        return NACK;
    }

    /* Restore the SDA. */
    g_gpio1_registers->gpio_oe &= ~(1U << SDA_PIN);
    g_gpio1_registers->gpio_cleardataout = (1U << SDA_PIN);

    return ACK;
}
