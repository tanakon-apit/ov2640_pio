import atexit
from PIL import Image
import serial
import numpy as np

filename = "pic.png"
counter = 0

ser = serial.Serial('COM6', 1000000)
atexit.register(lambda: ser.close())
while 1:
    ser.reset_input_buffer()
    raw = ser.read(88*72)
    print(raw[0])
    
    grey_val = np.frombuffer(raw, dtype=np.uint8).reshape(72, 88)
    img = Image.fromarray(grey_val, 'L')

    img.save(filename)