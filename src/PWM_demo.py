#  Pulse Width Modulation (PWM) demo to cycle brightness of an LED

import RPi.GPIO as GPIO   # Import the GPIO library.
import time               # Import time library

GPIO.setmode(GPIO.BOARD)  # Set Pi to use pin number when referencing GPIO pins.
                          # Can use GPIO.setmode(GPIO.BCM) instead to use 
                          # Broadcom SOC channel names.

GPIO.setup(1, GPIO.OUT)  # Set GPIO pin 12 to output mode.
GPIO.setup(5, GPIO.OUT)
GPIO.setup(12, GPIO.OUT)
RED = GPIO.PWM(1, 100) #red
GREEN = GPIO.PWM(5, 100) #green
BLUE = GPIO.PWM(12, 100) #blue     Initialize PWM on pwmPin 100Hz frequency

# main loop of program
print("\nPress Ctl C to quit \n")  # Print blank line before and after message.
dc=0                               # set dc variable to 0 for 0%
pwm.start(dc)                      # Start PWM with 0% duty cycle

try:
    while True:
    #red
        RED.start(100)
        GREEN.start(1)
        BLUE.start(1)
        time.sleep(10)
    #green
        RED.ChangeDutyCycle(1)
        GREEN.ChangeDutyCycle(100)
        BLUE.ChangeDutyCycle(1)
        time.sleep(10)
    #blue
        RED.ChangeDutyCycle(1)
        GREEN.ChangeDutyCycle(1)
        BLUE.ChangeDutyCycle(100)
        time.sleep(10)
    #white?
        RED.ChangeDutyCycle(50)
        GREEN.ChangeDutyCycle(50)
        BLUE.ChangeDutyCycle(50)
        time.sleep(10)
    
    
    
  #while True:                      # Loop until Ctl C is pressed to stop.
    #for dc in range(0, 101, 10):    # Loop 0 to 100 stepping dc by 5 each loop
      #pwm.ChangeDutyCycle(dc)
     # time.sleep(10)             # wait .05 seconds at current LED brightness
      #print(dc)
   # for dc in range(95, 0, -10):    # Loop 95 to 5 stepping dc down by 5 each loop
     # pwm.ChangeDutyCycle(dc)
     # time.sleep(10)             # wait .05 seconds at current LED brightness
     # print(dc)
      
      
except KeyboardInterrupt:
  print("Ctl C pressed - ending program")

pwm.stop()                         # stop PWM
GPIO.cleanup()                     # resets GPIO ports used back to input mode