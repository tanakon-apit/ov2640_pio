import atexit
import math
from PIL import Image
import serial
import struct
import sys
import time
import numpy as np

filename = "pic.png"

ser = serial.Serial('COM6', 1000000)
atexit.register(lambda: ser.close())

while 1:
    ser.reset_input_buffer()
    raw = ser.read(88*72)
    print(raw[0])
    
    # rgb565_com = np.frombuffer(raw, dtype=np.uint16).reshape(72, 88)
    # r = ((rgb565_com >> 11) & 0x1f) << 3
    # g = ((rgb565_com >> 5) & 0x3f) << 2
    # b = (rgb565_com & 0x1F) << 3

    # grey_val = ((0.299 * r) + (0.587 * g) + (0.114 * b)).astype(np.uint8)
    grey_val = np.frombuffer(raw, dtype=np.uint8).reshape(72, 88)
    img = Image.fromarray(grey_val, 'L')
    # img = Image.new('RGB', (88, 72))
    # width, height = img.size
    # data = img.load()

    # for y in range(height):
    #     for x in range(width):
    #         idx = y * width + x
    #         v = struct.unpack('<H', raw[2*idx:2*(idx+1)])[0]

    #         r, g, b = v >> (5 + 6), (v >> 5) & 0b111111, v & 0b11111 

    #         r = math.floor(r / 0x1f * 0xff)
    #         g = math.floor(g / 0x3f * 0xff)
    #         b = math.floor(b / 0x1f * 0xff)
    #         data[x, y] = (r, g, b)

    img.save(filename)