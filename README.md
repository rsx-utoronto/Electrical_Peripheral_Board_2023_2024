# Electrical_Peripheral_Board_2022_2023

To check the BNC cable input: 
1. If you need to check which device : ./rover_ws/src/rsx-rover/scripts/utils/gen/find_usb.sh
2. Get the input: screen /dev/ttyUSBX <baudrate> where X is the usb port and baud rate is usually 115200
   - screen /dev/ttyUSB1 115200
3. To kill the session:
   - ctrl-a + k and enter y
