/**
 * File: i2c.h
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
#ifndef __I2C__H__
#define __I2C__H__

#include <stdbool.h>
#include <stdint.h>

/**
 * Select address mode. The I2C protocol
 * supports either READ, which is represented
 * as a "1" at the position of the 8th bit, or
 * a WRITE, which is represented as a "0" at
 * the position of the 8th bit.
 */
typedef enum
{
    READ  = 1,
    WRITE = 0
} addr_mode_t;

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
 * i2c_send_address Sends the @addr with which the master
 * has to communicate with.
 */
extern void i2c_send_address(uint8_t addr, addr_mode_t mode);

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
