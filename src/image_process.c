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

void RGB565_to_Binary_nonblocking(uint8_t *bin_img, Image_Convert *img_buff, size_t len, uint8_t frame_num, int8_t pixel_offset, uint8_t threshold)
{
    static size_t i = 0;
    size_t frame_index = frame_num * len;
    if (i < len)
    {
        size_t img_index = frame_index + ((i + pixel_offset) % len);
        uint8_t r = ((img_buff[img_index].u16 >> 11) & 0x1f) << 3;
        uint8_t g = ((img_buff[img_index].u16 >> 5) & 0x3f) << 2;
        uint8_t b = (img_buff[img_index].u16 & 0x1f) << 3;
        uint8_t grey_pixel = (0.299 * r) + (0.587 * g) + (0.114 * b);
        if (grey_pixel < threshold) bin_img[i] = 255;
        else bin_img[i] = 0;
        i++;
    } else {
        i = 0;
    }
}

Process_Status Line_Detection_nonblocking(uint8_t *bin_img, Linear_Constant *c, size_t row, size_t col)
{
    static int32_t n = 0;
    static int32_t sum_xy = 0;
    static int32_t sum_x = 0;
    static int32_t sum_y = 0;
    static int32_t sum_x2 = 0;
    static int8_t h = 0;
    static int8_t w = 0;

    if (h < row) {
        uint32_t index = (h * col) + w;
        if (bin_img[index] == 255) {
            n++;
            sum_x += h;
            sum_y += w;
            sum_xy += h * w;
            sum_x2 += h * h;
        }
        w = (w + 1) % col;
        if (w == 0) h++;
    } else {
        float den = (n * sum_x2) - (sum_x * sum_x);
        if (!den) {
            n = 0;
            sum_xy = 0;
            sum_x = 0;
            sum_y =0;
            sum_x2 = 0;
            h = 0;
            w = 0;
            return Error;
        }
        c->slope = ((n * sum_xy) - (sum_x * sum_y)) / den;
        c->intercept = (sum_y - (c->slope * sum_x)) / n;

        n = 0;
        sum_xy = 0;
        sum_x = 0;
        sum_y =0;
        sum_x2 = 0;
        h = 0;
        w = 0;
        return Done;
    }

    return Busy;
}