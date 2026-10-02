#ifndef __AM335X_PERIF_PRM_REGISTERS__H__
#define __AM335X_PERIF_PRM_REGISTERS__H__

#include <stdint.h>

#include "am335x_address.h"
#include "common.h"

typedef struct
{
    __IO uint32_t pm_per_rstctrl;
    RESERVED(0x4, 0x8);
    __IO uint32_t pm_per_pwrstst;
    __IO uint32_t pm_per_pwrstctrl;
} power_perif_regs_t;

#define PRM_PER_REGS ((power_perif_regs_t *)PRM_PER_BASE)

#endif  // __AM335X_PERIF_PRM_REGISTERS__H__
