#include "am335x_registers.h"
#include "i2c.h"

int
main(void)
{
    i2c_init();

    g_gpio1_registers->gpio_oe &= ~(1U << 21);
    g_gpio1_registers->gpio_oe &= ~(1U << 22);

    while (1) {
        i2c_start();

        for (int i = 0; i < 100; i++);

        i2c_send_address(0x3, READ);

        if (i2c_ack() == ACK) {
            g_gpio1_registers->gpio_setdataout   = (1U << 21);
            g_gpio1_registers->gpio_cleardataout = (1U << 22);
        } else {
            g_gpio1_registers->gpio_cleardataout = (1U << 21);
            g_gpio1_registers->gpio_setdataout   = (1U << 22);

            i2c_stop();
            continue;
        }

        i2c_send_data(0xF);

        if (i2c_ack() == ACK) {
            g_gpio1_registers->gpio_setdataout   = (1U << 21);
            g_gpio1_registers->gpio_cleardataout = (1U << 22);
        } else {
            g_gpio1_registers->gpio_cleardataout = (1U << 21);
            g_gpio1_registers->gpio_setdataout   = (1U << 22);

            i2c_stop();
            continue;
        }

        for (int i = 0; i < 100; i++);
        i2c_stop();

        for (int i = 0; i < 100; i++);
    }

    return 0;
}
