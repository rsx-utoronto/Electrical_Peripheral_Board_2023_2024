// Master Arduino Code:
#include <SPI.h>  //Library for SPI
#define green 0
#define red 2
#define blue 3

void SPI_Reset();
int16_t SPI_Read(byte address, int DataSize);
byte SPI_ReadRXBuffer(int n, int m);
void SPI_LoadTXBuffer(int a, int b, int c, byte dataIn);
void SPI_RTS(int T2, int T1, int T0);
void SPI_bitModify(byte address, byte mask, byte data);
byte SPI_readStatus();
byte SPI_rxStatus();

void setup(void) {
  Serial.begin(115200);      // Starts Serial Communication at Baud Rate 115200
  SPI.begin();               // Begins the SPI commnuication
  SPI.setBitOrder(MSBFIRST);
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
  byte Mastereceive;
  
  while (true) {
    Mastereceive = SPI_ReadRXBuffer(0,0);

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
      Serial.println("Coco messed up /n");

    delay(1000);
  } 
}

void SPI_Reset(){
  digitalWrite(SS, LOW);
  byte reset = 0xC0;
  SPI.transfer(&reset, 1);
  digitalWrite(SS, HIGH);
}

int16_t SPI_Read(byte address, int DataSize){ //datasize in bytes <=2
  digitalWrite(SS, LOW);
  byte instruction = 3; //b00000011
  int16_t buffer = (instruction<<8)|(address);
  SPI.transfer(&buffer, 2);
  int16_t dataRecieved;
  if(DataSize == 1){
    byte dataReceive1 = SPI.transfer(&buffer);
    dataRecieved = dataReceive1;
  }
  else if(DataSize == 2){
    dataRecieved = SPI.transfer16(&buffer); 
  }
  else{
    Serial.println("SPI_Read DataSize is too big");
  }
  digitalWrite(SS, HIGH);
  return dataRecieved;
}

byte SPI_ReadRXBuffer(int n, int m){
 byte instruction = 10010000|(n<<1)| m; 
 //read data sheet
 digitalWrite(SS, LOW);
 int16_t buffer = (instruction<<8);
 int16_t recieved= SPI.transfer(&buffer);
 byte dataRecieved = (recieved<<8);
 digitalWrite(SS, HIGH);
 Serial.println(recieved);
 return dataRecieved;
}

void SPI_Write(byte address, byte data){ //for 1 byte of data
  digitalWrite(SS, LOW);
  byte instruction = 2; //b00000010
  long buffer = (instruction<<24)|(address<<16)|(data<<8);
  SPI.transfer(&buffer, 3);
  digitalWrite(SS, HIGH);
  
}

void SPI_LoadTXBuffer(int a, int b, int c, byte dataIn){
  digitalWrite(SS, LOW);
  byte instruction = 01000000 | (a<<2) | (b<<1) | c;
  int buffer = (instruction<<8)|(dataIn);
  SPI.transfer(&buffer, 2);
  digitalWrite(SS, HIGH);
}

void SPI_RTS(int T2, int T1, int T0){
  digitalWrite(SS, LOW);
  byte buffer = (10000000 | (T2<<2)|(T1<<1)|(T0));
  digitalWrite(SS, HIGH);
}
void SPI_bitModify(byte address, byte mask, byte data){
  digitalWrite(SS, LOW);
  byte instruction = 5; //0000101?
  long buffer;//32 bit (4bytes)
  buffer = (instruction << 24)|(address << 16)|(mask << 8)|(data);
  SPI.transfer(&buffer, 4);
  digitalWrite(SS, HIGH);
  }

byte SPI_readStatus(){
  digitalWrite(SS, LOW);
  byte instruction = 160; //10100000
  SPI.transfer(&instruction, 1);
  int16_t received = SPI.transfer16(&instruction); //don't care about sending
  byte dataOut = received;
  digitalWrite(SS, HIGH);
  return dataOut;
}

byte SPI_rxStatus(){
  digitalWrite(SS, LOW);
  byte instruction = 176; //10110000
  SPI.transfer(&instruction, 1);
  int16_t received = SPI.transfer16(&instruction); //don't care about sending
  byte dataOut = received;
  digitalWrite(SS, HIGH);
  return dataOut;
}
