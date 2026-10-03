#ifndef __I2C__H__
#define __I2C__H__

#include <stdint.h>

/**
 * i2c_init Initializes all the registers & modules required
 * for this implementation of i2c to work.
 */
extern void i2c_init(void);

/**
 * i2c_start Initiates a new transaction to a target device.
 */
extern void i2c_start(void);

/**
 * i2c_send_data Sends the next byte to the connected target
 * device.
 */
extern void i2c_send_data(uint8_t src);

/**
 * i2c_ack Sends the ACK bit, required to make sure that
 * the target device was listening while sending data.
 */
extern void i2c_ack(void);

/**
 * i2c_stop Terminates the communication with the target
 * device.
 */
extern void i2c_stop(void);

#endif  // __I2C__H__
