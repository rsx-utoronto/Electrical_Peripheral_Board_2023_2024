from machine import Pin, PWM, UART
import machine, neopixel
import time
from time import sleep

pwmR = PWM(Pin(9))
pwmG = PWM(Pin(10))
pwmB = PWM(Pin(11))
pwmR.freq(100)
pwmB.freq(100)
pwmG.freq(100)

strip = neopixel.NeoPixel(machine.Pin(22), 6)

p4 = Pin(4, Pin.IN)

high = 65535
low = 0

pwmR.duty_u16(low)
pwmG.duty_u16(low)
pwmB.duty_u16(low)

def blink(colour, time):
    for duty in range(low, high, 1):	# slowly increase colour brightness
        colour.duty_u16(duty)
    sleep(time)
    for duty in range(high, low, -1):		# slowly decrease colour brightness
        colour.duty_u16(duty)
    sleep(time)
    
def demo(np):
    n = np.n
    
    for i in range(n):
        np[i] = (255, 0, 0)
        np.write()
            

    # cycle
#     for i in range(4 * n):
#         for j in range(n):
#             np[j] = (0, 0, 0)
#         np[i % n] = (255, 255, 255)
#         np.write()
#         time.sleep_ms(25)

    # bounce
#     for i in range(4 * n):
#         for j in range(n):
#             np[j] = (0, 0, 128)
#         if (i // n) % 2 == 0:
#             np[i % n] = (0, 0, 0)
#         else:
#             np[n - 1 - (i % n)] = (0, 0, 0)
#         np.write()
#         time.sleep_ms(60)

    # fade in/out
#     for i in range(0, 4 * 256, 8):
#         for j in range(n):
#             if (i // 256) % 2 == 0:
#                 val = i & 0xff
#             else:
#                 val = 255 - (i & 0xff)
#             np[j] = (val, 0, 0)
#         np.write()

    # clear
#     for i in range(n):
#         np[i] = (0, 0, 0)
#     np.write()


while True:
    #white
#     for duty in range(65025):
#         pwmR.duty_u16(duty)
#         pwmB.duty_u16(duty)
#         pwmG.duty_u16(duty)
#         sleep(0.0001)
#     blink(pwmR, 1)
#     blink(pwmG, 1)
#     blink(pwmB, 1)
#         
#     if (p4.value()):
#         pwmR.duty_u16(high)
#         pwmG.duty_u16(low)
#         pwmB.duty_u16(low)
#     else:
#         pwmR.duty_u16(low)
#         pwmG.duty_u16(low)
#         pwmB.duty_u16(low)
    strip[0] = (255, 0, 0)
    strip.write()