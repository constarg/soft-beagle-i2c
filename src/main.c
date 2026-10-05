#include "i2c.h"

int
main(void)
{
    i2c_init();

    while (1) {
        i2c_start();

        for (int i = 0; i < 100; i++);

        i2c_send_address(0x3, READ);

        i2c_send_data(0xF);

        i2c_ack();

        for (int i = 0; i < 100; i++);
        i2c_stop();

        for (int i = 0; i < 100; i++);
    }

    return 0;
}
