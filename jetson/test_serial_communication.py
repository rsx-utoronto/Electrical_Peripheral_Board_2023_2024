import rospy 
import serial 

# Port may be different (0 or 1)
ser = serial.Serial('/dev/ttyACM1')
ser.baudrate = 115200

print(ser.name)

while True: 
    ser.write(b'b')
ser.close()
