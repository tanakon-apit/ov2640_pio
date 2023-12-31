#ifndef __IMAGE_PROCESS__H__
#define __IMAGE_PROCESS__H__

#include <stdint.h>
#include "ov2640.h"

typedef struct {
    float slope;
    uint8_t intercept;
} Linear_Constant;

typedef enum {
    Done,
    Busy,
    Error
} Process_Status;

void RGB565_to_Grey_blocking(uint8_t *grey_img, Image_Convert *img_buff, size_t len, uint8_t frame_num, int8_t pixel_offset);

void RGB565_to_Grey_nonblocking(uint8_t *grey_img, Image_Convert *img_buff, size_t len, uint8_t frame_num, int8_t pixel_offset);

void RGB565_to_Binary_nonblocking(uint8_t *bin_img, Image_Convert *img_buff, size_t len, uint8_t frame_num, int8_t pixel_offset, uint8_t threshold);

Process_Status Line_Detection_nonblocking(uint8_t *bin_img, Linear_Constant *c, size_t row, size_t col);

#endif