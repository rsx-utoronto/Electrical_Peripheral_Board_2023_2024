// Master Arduino Code:
// stuff happen at falling edge of SCK
#include <SPI.h>  //Library for SPI
#include <Arduino.h>
#include "SPIadditional.h"

#define green 1
#define blue 2
#define red 3

int BLUE = 6;
  int RED = 4;
  int GREEN = 2;

void setup(void) {
  Serial.begin(115200);      // Starts Serial Communication at Baud Rate 115200
  SPI.begin();               // Begins the SPI commnuication
  //SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);  // Sets clock for SPI communication at 16 (16/16=1Mhz)
  digitalWrite(SS, HIGH);  // Setting SlaveSelect as HIGH (So master doesnt
                           // connnect with slave)
  
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  SPI.beginTransaction( SPISettings(1000000, MSBFIRST, SPI_MODE0));
  //SPI sends by bytes. The LSB/MSBFIRST value only applies to each byte. 
  //If you want to send the bytes in reverse order you will need to send them one at a time.
}

void loop(void){
  int16_t received = SPI_Read( 0b01111000, 1);
  Serial.println(received);
  delay(2000);
}



//void loop(void) {
//
//  byte Mastereceive = 0;
//  byte color;
//  bool recieved = false;
//  //SPI_Reset();
//  //SPI_Read( 0b01111000, 1);
//  //SPI_ReadRXBuffer(0, 0);
//  //SPI_Write(0b10101010, 0b11110001);
//  //SPI_LoadTXBuffer(1, 1, 1, 0b11110001);
//  //SPI_RTS(1, 1, 1);
//  //SPI_bitModify(0b11110001, 0b01110001, 0b11100111);
//  //SPI_readStatus();
//  SPI_rxStatus();
//  
//  //Mastereceive = SPI_ReadRXBuffer(0,0);
//  if(Mastereceive != 0){recieved = true;}
//  Serial.println(Mastereceive);
//  while (Mastereceive) {
//  //Serial.print(color);
//  
//
//    if (Mastereceive == green) {  // Logic for setting the LED output depending
//                                  // upon value received from slave
//      digitalWrite(RED, LOW);
//      digitalWrite(BLUE, LOW);
//
//      if ((int)(millis() / 250) % 2 == 0) {
//        digitalWrite(GREEN, HIGH);
//
//      } else {
//        digitalWrite(GREEN, LOW);
//      }
//      Serial.println("green");
//    }
//
//    else if (Mastereceive == blue) {
//      digitalWrite(RED, LOW);
//      digitalWrite(BLUE, HIGH);
//      digitalWrite(GREEN, LOW);
//      Serial.println("blue");
//    }
//
//    else if (Mastereceive == red) {
//      digitalWrite(RED, HIGH);
//      digitalWrite(BLUE, LOW);
//      digitalWrite(GREEN, LOW);
//      Serial.println("red");
//    }
//
//    else
//      Serial.println("Coco messed up /n");
//
//    
//  } 
//  recieved = false;
//  delay(1000);
//}
