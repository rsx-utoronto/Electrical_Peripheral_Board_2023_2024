# SPDX-FileCopyrightText: 2018 Kattni Rembor for Adafruit Industries
#
import time
import board
from rainbowio import colorwheel
import neopixel
import pwmio
import usb_cdc

serial = usb_cdc.data

RBright = pwmio.PWMOut(board.GP9, frequency = 5000, duty_cycle = 0)
BBright = pwmio.PWMOut(board.GP10, frequency = 5000, duty_cycle = 0)
GBright = pwmio.PWMOut(board.GP11, frequency = 5000, duty_cycle = 0)

R = pwmio.PWMOut(board.GP0, frequency = 5000, duty_cycle = 0)
G = pwmio.PWMOut(board.GP1, frequency = 5000, duty_cycle = 0)
B = pwmio.PWMOut(board.GP2, frequency = 5000, duty_cycle = 0)

pixel_pin = board.GP22
num_strip = 50

fan_pin = board.GP27
num_fan = 6

strip = neopixel.NeoPixel(pixel_pin, num_strip, brightness=0.3, auto_write=False)
fan = neopixel.NeoPixel(fan_pin, num_fan, brightness=0.3, auto_write=False)


def color_chase(color, wait):
    for i in range(num_fan):
        fan[i] = color
        time.sleep(wait)
        fan.show()
    time.sleep(0.5)


def rainbow_cycle(wait):
    for j in range(255):
        for i in range(num_fan):
            rc_index = (i * 256 // num_fan) + j
            fan[i] = colorwheel(rc_index & 255)
        fan.show()
        time.sleep(wait)
        
def colorFill(color):
    fan.fill(color)
    fan.show()
    strip_colour = (color[0], color[2], color[1])
    strip.fill(strip_colour)
    strip.show()
    bright_fill(color)
    
def bright_fill(colour):
    RBright.duty_cycle = int(65535 * ((colour[0] / 255)))
    GBright.duty_cycle = int(65535 * ((colour[1] / 255)))
    BBright.duty_cycle = int(65535 * ((colour[2] / 255)))

def rainbow_cycle(wait):
    for j in range(255):
        for i in range(num_pixels):
            rc_index = (i * 256 // num_pixels) + j
            pixels[i] = colorwheel(rc_index & 255)
        pixels.show()
        time.sleep(wait)

def blink(color, wait):
    pixels.fill(BLACK)
    pixels.show()
    time.sleep(wait)
    
    pixels.fill(color)
    pixels.show()
    time.sleep(wait)

RED = (255, 0, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)
BLACK = (0, 0, 0)

#     for i in range(5):
#         blink(GREEN, 0.5)
# 
#     rainbow_cycle(0)  # Increase the number to slow down the rainbow
byte = 0
while True:
    if True:
        byte = serial.read(1)
        string = byte.decode('utf-8')
        print(string)
        if (byte == b'r' or byte == b'R'):
            R.duty_cycle = 2 ** 15
            G.duty_cycle = 0
            B.duty_cycle = 0
        elif (byte == b'g' or byte == b'G'):
            R.duty_cycle = 0
            G.duty_cycle = 2 ** 15
            B.duty_cycle = 0
        elif (byte == b'b' or byte == b'B'):
            R.duty_cycle = 0
            G.duty_cycle = 0
            B.duty_cycle = 2 ** 15
        else:
            R.duty_cycle = 0
            G.duty_cycle = 0
            B.duty_cycle = 0
    #         if byte == b'\r':
    #             log(in_data.decode("utf-8"))
    #             out_data = in_data
    #             out_data += b'  '
    #             in_data = bytearray()
    #             out_index = 0
    #         else:
    #             in_data = byte
    #             if len(in_data) == 129:
    #                 in_data = in_data[128] + in_data[0:127]
    time.sleep(0.1)
    
