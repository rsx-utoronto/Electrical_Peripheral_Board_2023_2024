import time
import board
from rainbowio import colorwheel
import neopixel
import usb_cdc
import USB

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


RED = (255, 0, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)


while True:
#     print(USB.read_data(1))
#     USB.send_data("Helooo!")
#     time.sleep(1)
    fan.fill(RED)
    fan.show()
#     # Increase or decrease to change the speed of the solid color change.
#     time.sleep(1)
#     fan.fill(GREEN)
#     fan.show()
#     time.sleep(1)
#     fan.fill(BLUE)
#     fan.show()
#     time.sleep(1)
# 
#     color_chase(RED, 0.1)  # Increase the number to slow down the color chase
#     color_chase(YELLOW, 0.1)
#     color_chase(GREEN, 0.1)
#     color_chase(CYAN, 0.1)
#     color_chase(BLUE, 0.1)
#     color_chase(PURPLE, 0.1)
# 
#     rainbow_cycle(0)  # Increase the number to slow down the rainbow
