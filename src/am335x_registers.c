#include "am335x_address.h"
#include "am335x_cm_registers.h"
#include "am335x_gpio_registers.h"
#include "am335x_perif_prm_registers.h"

clk_module_regs_t  *g_cm_per_registers = (clk_module_regs_t *)CM_PER_BASE;
gpio_regs_t        *g_gpio1_registers  = (gpio_regs_t *)GPIO1_BASE;
power_perif_regs_t *g_pm_pef_registers = (power_perif_regs_t *)PRM_PER_BASE;
