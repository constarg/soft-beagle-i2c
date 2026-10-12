/**
 * File: am335x_cm_registers.h
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
#ifndef __AM335X_CM_REGISTERS__H__
#define __AM335X_CM_REGISTERS__H__

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "common.h"

typedef struct
{
    __IO uint32_t cm_per_l4ls_clkstctrl; /* CM_PER_L4LS_CLKSTCTRL[0:4] */
    __IO uint32_t cm_per_l3s_clkstctrl;  /* CM_PER_L3S_CLKSTCTRL[4:8] */
    RESERVED(0x8, 0xC);
    __IO uint32_t cm_per_l3_clkstctrl;
    RESERVED(0x10, 0x14);
    __IO uint32_t cm_per_cpgmac0_clkctrl;
    __IO uint32_t cm_per_lcdc_clkctrl;
    __IO uint32_t cm_per_usb0_clkctrl;
    RESERVED(0x20, 0x24);
    __IO uint32_t cm_per_tptc0_clkctrl;
    __IO uint32_t cm_per_emif_clkctrl;
    __IO uint32_t cm_per_ocmcram_clkctrl;
    __IO uint32_t cm_per_gpmc_clkctrl;
    __IO uint32_t cm_per_mcasp0_clkctrl;
    __IO uint32_t cm_per_uart5_clkctrl;
    __IO uint32_t cm_per_mmc0_clkctrl;
    __IO uint32_t cm_per_elm_clkctrl;
    __IO uint32_t cm_per_i2c2_clkctrl;
    __IO uint32_t cm_per_i2c1_clkctrl;
    __IO uint32_t cm_per_spi0_clkctrl;
    __IO uint32_t cm_per_spi1_clkctrl;
    RESERVED(0x54, 0x60);
    __IO uint32_t cm_per_l4ls_clkctrl;
    RESERVED(0x64, 0x68);
    __IO uint32_t cm_per_mcasp1_clkctrl;
    __IO uint32_t cm_per_uart1_clkctrl;
    __IO uint32_t cm_per_uart2_clkctrl;
    __IO uint32_t cm_per_uart3_clkctrl;
    __IO uint32_t cm_per_uart4_clkctrl;
    __IO uint32_t cm_per_timer7_clkctrl;
    __IO uint32_t cm_per_timer2_clkctrl;
    __IO uint32_t cm_per_timer3_clkctrl;
    __IO uint32_t cm_per_timer4_clkctrl;
    RESERVED(0x8C, 0xAC);
    __IO uint32_t cm_per_gpio1_clkctrl;
    __IO uint32_t cm_per_gpio2_clkctrl;
    __IO uint32_t cm_per_gpio3_clkctrl;
    RESERVED(0xB8, 0xBC);
    __IO uint32_t cm_per_tpcc_clkctrl;
    __IO uint32_t cm_per_dcan0_clkctrl;
    __IO uint32_t cm_per_dcan1_clkctrl;
    RESERVED(0xC8, 0xCC);
    __IO uint32_t cm_per_epwmss1_clkctrl;
    __IO uint32_t cm_per_emif_fw_clkctrl;
    __IO uint32_t cm_per_epwmss0_clkctrl;
    __IO uint32_t cm_per_epwmss2_clkctrl;
    __IO uint32_t cm_per_l3_instr_clkctrl;
    __IO uint32_t cm_per_l3_clkctrl;
    __IO uint32_t cm_per_ieee5000_clkctrl;
    __IO uint32_t cm_per_pru_icss_clkctrl;
    __IO uint32_t cm_per_timer5_clkctrl;
    __IO uint32_t cm_per_timer6_clkctrl;
    __IO uint32_t cm_per_mmc1_clkctrl;
    __IO uint32_t cm_per_mmc2_clkctrl;
    __IO uint32_t cm_per_tptc1_clkctrl;
    __IO uint32_t cm_per_tptc2_clkctrl;
    RESERVED(0x104, 0x10C);
    __IO uint32_t cm_per_spinlock_clkctrl;
    __IO uint32_t cm_per_mailbox0_clkctrl;
    RESERVED(0x114, 0x11C);
    __IO uint32_t cm_per_l4hs_clkstctrl;
    __IO uint32_t cm_per_l4hs_clkctrl;
    RESERVED(0x124, 0x12C);
    __IO uint32_t cm_per_ocpwp_l3_clkstctrl;
    __IO uint32_t cm_per_ocpwp_clkctrl;
    RESERVED(0x134, 0x140);
    __IO uint32_t cm_per_pru_icss_clkstctrl;
    __IO uint32_t cm_per_cpsw_clkstctrl;
    __IO uint32_t cm_per_lcdc_clkstctrl;
    __IO uint32_t cm_per_clkdiv32k_clkctrl;
    __IO uint32_t cm_per_clk_24mhz_clkstctrl;
} clk_module_regs_t;

assert_offset(clk_module_regs_t, cm_per_l4ls_clkstctrl, 0x0);
assert_offset(clk_module_regs_t, cm_per_l3s_clkstctrl, 0x4);
assert_offset(clk_module_regs_t, cm_per_l3_clkstctrl, 0xC);
assert_offset(clk_module_regs_t, cm_per_cpgmac0_clkctrl, 0x14);
assert_offset(clk_module_regs_t, cm_per_lcdc_clkctrl, 0x18);
assert_offset(clk_module_regs_t, cm_per_usb0_clkctrl, 0x1C);
assert_offset(clk_module_regs_t, cm_per_tptc0_clkctrl, 0x24);
assert_offset(clk_module_regs_t, cm_per_emif_clkctrl, 0x28);
assert_offset(clk_module_regs_t, cm_per_ocmcram_clkctrl, 0x2C);
assert_offset(clk_module_regs_t, cm_per_gpmc_clkctrl, 0x30);
assert_offset(clk_module_regs_t, cm_per_mcasp0_clkctrl, 0x34);
assert_offset(clk_module_regs_t, cm_per_uart5_clkctrl, 0x38);
assert_offset(clk_module_regs_t, cm_per_mmc0_clkctrl, 0x3C);
assert_offset(clk_module_regs_t, cm_per_elm_clkctrl, 0x40);
assert_offset(clk_module_regs_t, cm_per_i2c2_clkctrl, 0x44);
assert_offset(clk_module_regs_t, cm_per_i2c1_clkctrl, 0x48);
assert_offset(clk_module_regs_t, cm_per_spi0_clkctrl, 0x4C);
assert_offset(clk_module_regs_t, cm_per_spi1_clkctrl, 0x50);
assert_offset(clk_module_regs_t, cm_per_l4ls_clkctrl, 0x60);
assert_offset(clk_module_regs_t, cm_per_mcasp1_clkctrl, 0x68);
assert_offset(clk_module_regs_t, cm_per_uart1_clkctrl, 0x6C);
assert_offset(clk_module_regs_t, cm_per_uart2_clkctrl, 0x70);
assert_offset(clk_module_regs_t, cm_per_uart3_clkctrl, 0x74);
assert_offset(clk_module_regs_t, cm_per_uart4_clkctrl, 0x78);
assert_offset(clk_module_regs_t, cm_per_timer7_clkctrl, 0x7C);
assert_offset(clk_module_regs_t, cm_per_timer2_clkctrl, 0x80);
assert_offset(clk_module_regs_t, cm_per_timer3_clkctrl, 0x84);
assert_offset(clk_module_regs_t, cm_per_timer4_clkctrl, 0x88);
assert_offset(clk_module_regs_t, cm_per_gpio1_clkctrl, 0xAC);
assert_offset(clk_module_regs_t, cm_per_gpio2_clkctrl, 0xB0);
assert_offset(clk_module_regs_t, cm_per_gpio3_clkctrl, 0xB4);
assert_offset(clk_module_regs_t, cm_per_tpcc_clkctrl, 0xBC);
assert_offset(clk_module_regs_t, cm_per_dcan0_clkctrl, 0xC0);
assert_offset(clk_module_regs_t, cm_per_dcan1_clkctrl, 0xC4);
assert_offset(clk_module_regs_t, cm_per_epwmss1_clkctrl, 0xCC);
assert_offset(clk_module_regs_t, cm_per_epwmss0_clkctrl, 0xD4);
assert_offset(clk_module_regs_t, cm_per_epwmss2_clkctrl, 0xD8);
assert_offset(clk_module_regs_t, cm_per_l3_instr_clkctrl, 0xDC);
assert_offset(clk_module_regs_t, cm_per_l3_clkctrl, 0xE0);
assert_offset(clk_module_regs_t, cm_per_ieee5000_clkctrl, 0xE4);
assert_offset(clk_module_regs_t, cm_per_pru_icss_clkctrl, 0xE8);
assert_offset(clk_module_regs_t, cm_per_timer5_clkctrl, 0xEC);
assert_offset(clk_module_regs_t, cm_per_timer6_clkctrl, 0xF0);
assert_offset(clk_module_regs_t, cm_per_mmc1_clkctrl, 0xF4);
assert_offset(clk_module_regs_t, cm_per_mmc2_clkctrl, 0xF8);
assert_offset(clk_module_regs_t, cm_per_tptc1_clkctrl, 0xFC);
assert_offset(clk_module_regs_t, cm_per_tptc2_clkctrl, 0x100);
assert_offset(clk_module_regs_t, cm_per_spinlock_clkctrl, 0x10C);
assert_offset(clk_module_regs_t, cm_per_mailbox0_clkctrl, 0x110);
assert_offset(clk_module_regs_t, cm_per_l4hs_clkstctrl, 0x11C);
assert_offset(clk_module_regs_t, cm_per_l4hs_clkctrl, 0x120);
assert_offset(clk_module_regs_t, cm_per_ocpwp_l3_clkstctrl, 0x12C);
assert_offset(clk_module_regs_t, cm_per_ocpwp_clkctrl, 0x130);
assert_offset(clk_module_regs_t, cm_per_pru_icss_clkstctrl, 0x140);
assert_offset(clk_module_regs_t, cm_per_cpsw_clkstctrl, 0x144);
assert_offset(clk_module_regs_t, cm_per_lcdc_clkstctrl, 0x148);
assert_offset(clk_module_regs_t, cm_per_clkdiv32k_clkctrl, 0x14C);
assert_offset(clk_module_regs_t, cm_per_clk_24mhz_clkstctrl, 0x150);

#endif  // __AM335X_CM_REGISTERS__H__
