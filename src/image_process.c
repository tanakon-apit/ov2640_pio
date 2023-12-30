#include "image_process.h"

void RGB565_to_Grey_blocking(uint8_t *grey_img, Image_Convert *img_buff, size_t len, uint8_t frame_num, int8_t pixel_offset)
{
    size_t frame_index = frame_num * len;
    for (int i =0; i < len; i++) {
        size_t img_index = frame_index + ((i + pixel_offset) % len);
        uint8_t r = ((img_buff[img_index].u16 >> 11) & 0x1f) << 3;
        uint8_t g = ((img_buff[img_index].u16 >> 5) & 0x3f) << 2;
        uint8_t b = (img_buff[img_index].u16 & 0x1f) << 3;
        grey_img[i] = (0.299 * r) + (0.587 * g) + (0.114 * b);
    }
}

void RGB565_to_Grey_nonblocking(uint8_t *grey_img, Image_Convert *img_buff, size_t len, uint8_t frame_num, int8_t pixel_offset)
{
    static size_t i = 0;
    size_t frame_index = frame_num * len;
    if (i < len)
    {
        size_t img_index = frame_index + ((i + pixel_offset) % len);
        uint8_t r = ((img_buff[img_index].u16 >> 11) & 0x1f) << 3;
        uint8_t g = ((img_buff[img_index].u16 >> 5) & 0x3f) << 2;
        uint8_t b = (img_buff[img_index].u16 & 0x1f) << 3;
        grey_img[i] = (0.299 * r) + (0.587 * g) + (0.114 * b);
        i++;
    } else {
        i = 0;
    }
}