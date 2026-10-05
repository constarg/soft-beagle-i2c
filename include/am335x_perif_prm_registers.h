/**
 * File: am335x_perif_prm_registers.h
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
#ifndef __AM335X_PERIF_PRM_REGISTERS__H__
#define __AM335X_PERIF_PRM_REGISTERS__H__

#include <stdint.h>

#include "common.h"

typedef struct
{
    __IO uint32_t pm_per_rstctrl;
    RESERVED(0x4, 0x8);
    __IO uint32_t pm_per_pwrstst;
    __IO uint32_t pm_per_pwrstctrl;
} power_perif_regs_t;

#endif  // __AM335X_PERIF_PRM_REGISTERS__H__
