/**
 * File: am335_registers.c
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
#include "am335x_address.h"
#include "am335x_cm_registers.h"
#include "am335x_gpio_registers.h"
#include "am335x_perif_prm_registers.h"

clk_module_regs_t  *g_cm_per_registers = (clk_module_regs_t *)CM_PER_BASE;
gpio_regs_t        *g_gpio1_registers  = (gpio_regs_t *)GPIO1_BASE;
power_perif_regs_t *g_pm_pef_registers = (power_perif_regs_t *)PRM_PER_BASE;
