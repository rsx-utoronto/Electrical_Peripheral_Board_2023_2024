from machine import Pin, PWM, UART
import neopixel
import time
from time import sleep

strip = neopixel.NeoPixel(Pin(22), 50)
fan = neopixel.NeoPixel(Pin(28), 6)

# RED = (255, 0, 0)
# YELLOW_STRIP = (255, 150, 0)
# GREEN_STRIP = (0, 0, 255)
# CYAN_STRIP = (0, 255, 255)
# BLUE_STRIP = (0, 255, 0)
# PURPLE = (180, 255, 0)
# 
# YELLOW = (255, 150, 0)
# GREEN = (0, 255, 0)
# CYAN = (0, 255, 255)
# BLUE = (0, 0, 255)
# PURPLE = (180, 0, 255)
BLACK = (0, 0, 0)

# Clear the devices
fan.fill(BLACK)
strip.fill(BLACK)
strip.write()
fan.write()

# Configure the RGB pins for Ultra Bright LEDs
pwmR = PWM(Pin(9))
pwmG = PWM(Pin(10))
pwmB = PWM(Pin(11))
pwmR.freq(100)
pwmB.freq(100)
pwmG.freq(100)

p4 = Pin(4, Pin.IN)

high = 65535
low = 0

# Define colours
class Green:
    fan = (0, 255, 0)
    strip = (0, 0, 255)
    colour = pwmG
    
class Red:
    fan = (255, 0, 0)
    strip = (255, 0, 0)
    colour = pwmR
    
class Blue:
    fan = (0, 0, 255)
    strip = (0, 255, 0)
    colour = pwmB
    
class Yellow:
    fan = (180, 255, 0)
    strip = (180, 0, 255)
    colour = pwmB
    
# Clear output light devices
fan.fill(BLACK)
strip.fill(BLACK)
strip.write()
fan.write()
pwmR.duty_u16(low)
pwmG.duty_u16(low)
pwmB.duty_u16(low)

def diming(colour, time):
    for duty in range(low, high, 1):    # slowly increase colour brightness
        colour.duty_u16(duty)
    sleep(time)
    for duty in range(high, low, -1):       # slowly decrease colour brightness
        colour.duty_u16(duty)
    sleep(time)
    
def blink(colour, wait):
    colour.colour.duty_u16(low)
    fan.fill(BLACK)
    strip.fill(BLACK)
    strip.write()
    fan.write()
    
    colour.colour.duty_u16(high)
    fan.fill(colour.fan)
    strip.fill(colour.strip)
    fan.write()
    strip.write()
    sleep(wait)
    
    colour.colour.duty_u16(low)
    fan.fill(BLACK)
    strip.fill(BLACK)
    strip.write()
    fan.write()
    sleep(wait)

    
while True:
#     for i in range(5):
#         blink(pwmG, 1)
#     diming(pwmR, 1)
#     diming(pwmB, 1)
#     diming(pwmG, 1)

    blink(Red, 1)
    blink(Green, 1)
    blink(Blue, 1)
    blink(Yellow, 1)
