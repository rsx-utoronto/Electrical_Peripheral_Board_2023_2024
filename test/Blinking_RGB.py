from machine import Pin, PWM
from time import sleep

pwmR = PWM(Pin(0))
pwmG = PWM(Pin(1))
pwmB = PWM(Pin(2))

pwmR.freq(100)
pwmB.freq(100)
pwmG.freq(500)

while True:
    #white
#     for duty in range(65025):
#         pwmR.duty_u16(duty)
#         pwmB.duty_u16(duty)
#         pwmG.duty_u16(duty)
#         sleep(0.0001)

    #blinking (Active LOW)
    for duty in range(65535, 0, -1):	# slowly increase green brightness
        pwmG.duty_u16(duty)
    sleep(1)
    for duty in range(0, 65535, 1):		# slowly decrease green brightness
        pwmG.duty_u16(duty)
    sleep(1)
    for duty in range(65535, 0, -1):	# slowly increase red brightness
        pwmR.duty_u16(duty)
    sleep(1)
    for duty in range(0, 65535, 1):		# slowly decrease red brightness
        pwmR.duty_u16(duty)
    sleep(1)
    for duty in range(65535, 0, -1):	# slowly increase blue brightness
        pwmB.duty_u16(duty)
    sleep(1)
    for duty in range(0, 65535, 1):		# slowly decrease blue brightness
        pwmB.duty_u16(duty)
    sleep(1)
        