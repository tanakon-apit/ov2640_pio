#ifndef SCCB_H
#define SCCB_H

#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

void SCCB_reg_write(i2c_inst_t *sccb, uint8_t addr, uint8_t reg, uint8_t val);

uint8_t SCCB_reg_read(i2c_inst_t *sccb, uint8_t addr, uint8_t reg);

void SCCB_reg_list_write(i2c_inst_t *sccb, uint8_t addr, const uint8_t (*reg_list)[2]);

#endif