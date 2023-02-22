from machine import Pin, PWM, UART
import machine, neopixel
import time
from time import sleep

fan = neopixel.NeoPixel(machine.Pin(0), 6)

while True:
    fan[0] = (255, 255, 0)
    fan.write()