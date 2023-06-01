import serial
import rospy

# Location: scripts/utils/sensors
# Need to talk to Cat to run node
ser = serial.Serial('/dev/ttyTHS0', baudrate=9600)  
print(ser.name)        
while True:
    ser.write(b'R')     
ser.close()   
