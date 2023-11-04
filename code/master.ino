// Master Arduino Code:
// SPI MASTER (ARDUINO)
// SPI COMMUNICATION BETWEEN TWO ARDUINO
// CIRCUIT DIGEST
#include <SPI.h>  //Library for SPI
#define LED 7
#define ipbutton 2
#define green 0
#define red 2
#define blue 3

byte SPI_ReadRXBuffer();
int buttonvalue;
int x;
void setup(void) {
  Serial.begin(115200);      // Starts Serial Communication at Baud Rate 115200
  pinMode(ipbutton, INPUT);  // Sets pin 2 as input
  pinMode(LED, OUTPUT);      // Sets pin 7 as Output
  SPI.begin();               // Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV16);  // Sets clock for SPI communication at 16 (16/16=1Mhz)
  digitalWrite(SS, HIGH);  // Setting SlaveSelect as HIGH (So master doesnt
                           // connnect with slave)

  int BLUE = 6;
  int RED = 4;
  int GREEN = 2;

  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
}
void loop(void) {
  

  int BLUE = 6;
  int RED = 4;
  int GREEN = 2;

  //byte Mastersend, Mastereceive, Holder1, Holder2;
  //Holder1 = 0;
  //Holder2 = 1;  // dont care

  while (true) {
    byte Mastereceive = SPI_ReadRXBuffer();
    //digitalWrite(SS, LOW);  // Starts communication with Slave connected to master
    //Mastersend = 1;
    // Holder1 = SPI.transfer(Mastersend);  // Send the mastersend value to slave
    //                                      // also receives value from slave
    // Mastereceive = SPI.transfer(Holder2);
    // digitalWrite(SS, HIGH);

    if (Mastereceive == green) {  // Logic for setting the LED output depending
                                  // upon value received from slave
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, LOW);

      if ((int)(millis() / 250) % 2 == 0) {
        digitalWrite(GREEN, HIGH);

      } else {
        digitalWrite(GREEN, LOW);
      }
      Serial.println("green");
    }

    else if (Mastereceive == blue) {
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, HIGH);
      digitalWrite(GREEN, LOW);
      Serial.println("blue");
    }

    else if (Mastereceive == red) {
      digitalWrite(RED, HIGH);
      digitalWrite(BLUE, LOW);
      digitalWrite(GREEN, LOW);
      Serial.println("red");
    }

    else
      Serial.println("Coco fucked up /n");

    delay(1000);
  } 
}

void SPI_Reset(){
  digitalWrite(SS, LOW);
  byte reset = 0xC0;
  SPI.transfer(&reset, 1);
  delay(0.008);
  digitalWrite(SS, LOW);
}
 
void SPI_bitModify(byte address, byte mask, byte data){
  digitalWrite(SS, LOW);
  byte instruction = 5; //0000101?
  long buffer;//32 bit (4bytes)
  buffer = (instruction << 24)|(address << 16)|(mask << 8)|(data);
  SPI.transfer(&buffer, 4);
  delay(0.008*4);
  digitalWrite(SS, HIGH);
  }

void SPI_Write(byte address, byte data){
  digitalWrite(SS, LOW);
  byte instruction = 2; //b00000010
  long buffer = (instruction<<24)|(address<<16)|(data<<8);
  SPI.transfer(&buffer, 3);
  delay(0.008*3);
  digitalWrite(SS, HIGH);
  
}
void SPI_LoadTXBuffer(byte instruction, byte address){
  int buffer = (instruction<<8)|(address); //2 bytes
  SPI.transfer(&buffer, 2);
}

byte SPI_Read(byte address, int DataSize){ //datasize in bytes <=2
  digitalWrite(SS, LOW);
  byte instruction = 3; //b00000011
  int32_t buffer = (instruction<<24)|(address<<16);
  int32_t recieved = SPI.transfer16(&buffer); 
  int16_t dataRecieved = (recieved<<16);
  delay(0.008*4);
  digitalWrite(SS, HIGH);
  return dataRecieved;
}

byte SPI_ReadRXBuffer(){
 byte instruction = 10010000; //n = 0, m = 0, Receive Buffer 0, Start at RXB0SIDH, address 0x61
 //read data sheet
 digitalWrite(SS, LOW);
 int16_t buffer = (instruction<<8);
 int16_t recieved= SPI.transfer(&buffer);
 byte dataRecieved = (recieved<<8);
 //delay(0.008*(2));
 digitalWrite(SS, HIGH);
 Serial.println(recieved);
 return dataRecieved;
}
