/**
 * File: am335x_gpio_registers.h
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
#ifndef __AM335X_GPIO_REGISTERS__H__
#define __AM335X_GPIO_REGISTERS__H__

#include <stdint.h>

#include "common.h"

typedef struct
{
    __IO uint32_t gpio_revision;
    RESERVED(0x4, 0x10);
    __IO uint32_t gpio_sysconfig;
    RESERVED(0x14, 0x20);
    __IO uint32_t gpio_eoi;
    __IO uint32_t gpio_irqstatus_raw_0;
    __IO uint32_t gpio_irqstatus_raw_1;
    __IO uint32_t gpio_irqstatus_0;
    __IO uint32_t gpio_irqstatus_1;
    __IO uint32_t gpio_irqstatus_set_0;
    __IO uint32_t gpio_irqstatus_set_1;
    __IO uint32_t gpio_irqstatus_clr_0;
    __IO uint32_t gpio_irqstatus_clr_1;
    __IO uint32_t gpio_irqwaken_0;
    __IO uint32_t gpio_irqwaken_1;
    RESERVED(0x4c, 0x114);
    __IO uint32_t gpio_sysstatus;
    RESERVED(0x118, 0x130);
    __IO uint32_t gpio_ctrl;
    __IO uint32_t gpio_oe;
    __IO uint32_t gpio_datain;
    __IO uint32_t gpio_dataout;
    __IO uint32_t gpio_leveldetect0;
    __IO uint32_t gpio_leveldetect1;
    __IO uint32_t gpio_risingdetect;
    __IO uint32_t gpio_fallingdetect;
    __IO uint32_t gpio_debouncenable;
    __IO uint32_t gpio_debouncingtime;
    RESERVED(0x158, 0x190);
    __IO uint32_t gpio_cleardataout;
    __IO uint32_t gpio_setdataout;
} gpio_regs_t;

#endif  // __AM335X_GPIO_REGISTERS__H__
