from machine import Pin, PWM
from time import sleep

pwmR = PWM(Pin(0))
#pwmG = PWM(Pin(1))
#pwmB = PWM(Pin(2))

pwmR.freq(100)
#pwmB.freq(100)
#pwmG.freq(500)

while True:
    #white
#     for duty in range(65025):
#         pwmR.duty_u16(duty)
#         pwmB.duty_u16(duty)
#         #pwmG.duty_u16(duty)
#         sleep(0.0001)
    #blinking
    for duty in range(65535, 0, -1):
        pwmR.duty_u16(duty)
        #pwmB.duty_u16(duty)
        #pwmG.duty_u16(duty)
        sleep(0.0001)