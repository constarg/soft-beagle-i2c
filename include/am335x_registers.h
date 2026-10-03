#ifndef __AM335X_REGISTERS__H__
#define __AM335X_REGISTERS__H__

#include "am335x_cm_registers.h"
#include "am335x_gpio_registers.h"
#include "am335x_perif_prm_registers.h"

extern clk_module_regs_t  *g_cm_per_registers;
extern power_perif_regs_t *g_pm_per_registers;
extern gpio_regs_t        *g_gpio1_registers;

#endif
