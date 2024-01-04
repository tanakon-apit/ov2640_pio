#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "camera_interface.pio.h"
#include "ov2640.h"
#include "image_process.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"

void camera_interface_isr_handler(uint gpio, uint32_t events);
bool uart_write_nonblocking(uart_inst_t *uart, const uint8_t *src, size_t len, int8_t offset);

bool led_status = 0;
bool uart_status = 0;
bool status = 0;
uint64_t time = 0;
uint64_t dt = 0;
uint8_t frame_index = 0;

OV2640_Config cam_config;

Image_Convert image_buffer[88 * 72 * 4];
uint8_t process_buffer[88 * 72];

Linear_Constant B;
Process_Status detect_status;

int main() {
    
    stdio_init_all();
    uart_set_baudrate(uart0, 1000000);
	gpio_set_function(0, GPIO_FUNC_UART);
	gpio_set_function(1, GPIO_FUNC_UART);

    cam_config.pin_siod = 2;
    cam_config.pin_sioc = 3;
    cam_config.pin_resetb = 4;
    cam_config.pin_y0_pio_base = 5;
    cam_config.pin_vsync = 15;

    cam_config.sccb = i2c1;
    cam_config.pio = pio0;
    cam_config.pio_sm_base = 0;
    cam_config.dma_channel = dma_claim_unused_channel(true);

    cam_config.image_buf = &(image_buffer->u8[0]);
    cam_config.image_height = 72;
    cam_config.image_width = 88;
    cam_config.max_buf = 4;

    if (cyw43_arch_init()) while (true) sleep_ms(1000);

    OV2640_init(&cam_config);
    sleep_ms(10000);

    gpio_set_irq_enabled_with_callback(cam_config.pin_vsync, GPIO_IRQ_EDGE_RISE, true, &camera_interface_isr_handler);

    while (true) {

        if (detect_status == Busy)
        {
            RGB565_to_Binary_nonblocking(
                process_buffer,
                image_buffer,
                88 * 72,
                frame_index,
                2,
                64
            );
            detect_status = Line_Detection_nonblocking(
                process_buffer,
                &B,
                72,
                88
            );
            if (uart_status) {
                uart_status = uart_write_nonblocking(
                    uart0, 
                    process_buffer, 
                    88 * 72,
                    0);
                if (!uart_status) dt = time_us_64() - time;
            }
        }

        if (status) {
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_status);
            led_status = !led_status;
            status = !status;
        }
    }
    return 0;
}

void camera_interface_isr_handler(uint gpio, uint32_t events)
{
    static uint8_t count = 0;
    OV2640_Capture(&cam_config);
    if (detect_status == Done || detect_status == Error) {
        count = (count + 1) % 2;
        if (count) {
            time = time_us_64();
            uart_status = true;
        } 
        frame_index = (cam_config.callback_counter - 1 + cam_config.max_buf) % cam_config.max_buf;
        detect_status = Busy;
    }
    status = true;
}

bool uart_write_nonblocking(uart_inst_t *uart, const uint8_t *src, size_t len, int8_t offset)
{
    static size_t counter = 0;
    if (counter < len)
    {
        if (uart_is_writable(uart))
        {
            uart_get_hw(uart)->dr = *(src + ((counter + offset) % len));
            counter++;
        }
        return 1;
    } else {
        counter = 0;
        return 0;
    }
}