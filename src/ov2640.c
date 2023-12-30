
#include "ov2640.h"

void OV2640_init(OV2640_Config *config)
{
    gpio_set_function(config->pin_sioc, GPIO_FUNC_I2C);
    gpio_set_function(config->pin_siod, GPIO_FUNC_I2C);
    i2c_init(config->sccb, 100000);

    gpio_init(config->pin_resetb);
    gpio_set_dir(config->pin_resetb, GPIO_OUT);

    gpio_put(config->pin_resetb, 0);
    sleep_ms(100);
    gpio_put(config->pin_resetb, 1);
    sleep_ms(100);

    SCCB_reg_list_write(config->sccb, OV2640_ADDR, OV2640_UXGA_RGB565);
    SCCB_reg_list_write(config->sccb, OV2640_ADDR, OV2640_UXGA_88x72_15fps);

    SCCB_reg_write(config->sccb, OV2640_ADDR, 0xff, 0x00);
    SCCB_reg_write(config->sccb, OV2640_ADDR, 0xda, (SCCB_reg_read(config->sccb, OV2640_ADDR, 0xda) & 0x0c) | 0x08); // | 0x08

    uint offset = pio_add_program(config->pio, &camera_read_program);
    camera_read_init(config->pio, config->pio_sm_base, offset, config->pin_y0_pio_base);

    config->callback_counter = 0;

    dma_channel_config c = dma_channel_get_default_config(config->dma_channel);
    channel_config_set_read_increment(&c, false);
	channel_config_set_write_increment(&c, true);
	channel_config_set_dreq(&c, pio_get_dreq(config->pio, config->pio_sm_base, false));
	channel_config_set_transfer_data_size(&c, DMA_SIZE_8);

    dma_channel_configure(
        config->dma_channel,
        &c,
        &config->image_buf,
        &config->pio->rxf[config->pio_sm_base],
        config->image_height * config->image_width * 2,
        false
    );
}

void OV2640_Capture(OV2640_Config *config)
{
    dma_channel_set_write_addr(config->dma_channel, config->image_buf + (config->callback_counter * config->image_height * config->image_width * 2), true);
    config->callback_counter = (config->callback_counter + 1) % config->max_buf;
}