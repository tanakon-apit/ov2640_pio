#include "sccb.h"

void SCCB_reg_write(i2c_inst_t *sccb, uint8_t addr, uint8_t reg, uint8_t val) 
{
    uint8_t data[] = {reg, val};
    i2c_write_blocking(sccb, addr, data, sizeof(data), false);
}

uint8_t SCCB_reg_read(i2c_inst_t *sccb, uint8_t addr, uint8_t reg)
{
    i2c_write_blocking(sccb, addr, &reg, 1, false);
    uint8_t val;
    i2c_read_blocking(sccb, addr, &val, 1, false);
    return val;
}

void SCCB_reg_list_write(i2c_inst_t *sccb, uint8_t addr, const uint8_t (*reg_list)[2])
{

    while (1) {
        uint8_t reg = (*reg_list)[0];
        uint8_t val = (*reg_list)[1];

		if (reg == 0x00 && val == 0x00) {
			break;
		}

		SCCB_reg_write(sccb, addr, reg, val);

		reg_list++;
	}
}