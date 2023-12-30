#ifndef __IMAGE_PROCESS__H__
#define __IMAGE_PROCESS__H__

#include <stdint.h>
#include "ov2640.h"

void RGB565_to_Grey_blocking(uint8_t *grey_img, Image_Convert *img_buff, size_t len, uint8_t frame_num, int8_t pixel_offset);

void RGB565_to_Grey_nonblocking(uint8_t *grey_img, Image_Convert *img_buff, size_t len, uint8_t frame_num, int8_t pixel_offset);

#endif