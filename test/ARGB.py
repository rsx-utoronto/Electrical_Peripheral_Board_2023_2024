from machine import Pin, PWM, UART
import neopixel
import time
from time import sleep

strip = neopixel.NeoPixel(Pin(22), 50)
fan = neopixel.NeoPixel(Pin(28), 6)

RED = (255, 0, 0)
YELLOW_STRIP = (255, 150, 0)
GREEN_STRIP = (0, 0, 255)
CYAN_STRIP = (0, 255, 255)
BLUE_STRIP = (0, 255, 0)
PURPLE = (180, 255, 0)

YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)
BLACK = (0, 0, 0)

fan.fill(BLACK)
strip.fill(BLACK)
strip.write()
fan.write()

# cycle
def blink(color_strip, color, wait):
    fan.fill(color)
    strip.fill(color_strip)
    fan.write()
    strip.write()
    sleep(wait)
    
    fan.fill(BLACK)
    strip.fill(BLACK)
    strip.write()
    fan.write()
    sleep(wait)

while True:
    for i in range(2):
        blink(GREEN_STRIP, GREEN, 1)
    
    for i in range(255):
        fan.fill((0, 0, i))
        strip.fill((0, i, 0))
        strip.write()
        fan.write()
        sleep(0.01)

    for i in range(255, 0, -1):
        fan.fill((0, 0, i))
        strip.fill((0, i, 0))
        strip.write()
        fan.write()
        sleep(0.01)
    
    for i in range(255):
        fan.fill((i, 0, 0))
        strip.fill((i, 0, 0))
        strip.write()
        fan.write()
        sleep(0.01)
    
    for i in range(255, 0, -1):
        fan.fill((i, 0, 0))
        strip.fill((i, 0, 0))
        strip.write()
        fan.write()
        sleep(0.01)
        
    