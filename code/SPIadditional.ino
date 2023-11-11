#include <SPIadditional.h>

void SPI_Reset() {
  digitalWrite(SS, LOW);
  byte reset = 0;
  SPI.transfer(&reset, 1);
  digitalWrite(SS, HIGH);
}

int16_t SPI_Read(byte address, int DataSize) {  // datasize in bytes <=2
  digitalWrite(SS, LOW);
  byte instruction = 3;  // b00000011
  int16_t buffer = (instruction << 8) | (address);
  SPI.transfer(&buffer, 2);
  int16_t dataRecieved;
  if (DataSize == 1) {
    byte dataReceive1 = SPI.transfer(&buffer);
    dataRecieved = dataReceive1;
  } else if (DataSize == 2) {
    dataRecieved = SPI.transfer16(&buffer);
  } else {
    Serial.println("SPI_Read DataSize is too big");
  }
  digitalWrite(SS, HIGH);
  return dataRecieved;
}

byte SPI_ReadRXBuffer(int n, int m) {
  byte instruction = 10010000 | (n << 2) | (m << 1);
  // read data sheet
  digitalWrite(SS, LOW);
  int16_t buffer = (instruction << 8);
  int16_t recieved = SPI.transfer(&buffer);
  byte dataRecieved = (recieved << 8);
  digitalWrite(SS, HIGH);
  Serial.println(recieved);
  return dataRecieved;
}

void SPI_Write(byte address, byte data) {  // for 1 byte of data
  digitalWrite(SS, LOW);
  byte instruction = 2;  // b00000010
  long buffer = (instruction << 24) | (address << 16) | (data << 8);
  SPI.transfer(&buffer, 3);
  digitalWrite(SS, HIGH);
}

void SPI_LoadTXBuffer(int a, int b, int c, byte dataIn) {
  digitalWrite(SS, LOW);
  byte instruction = 01000000 | (a << 2) | (b << 1) | c;
  int buffer = (instruction << 8) | (dataIn);
  SPI.transfer(&buffer, 2);
  digitalWrite(SS, HIGH);
}

void SPI_RTS(int T2, int T1, int T0) {
  digitalWrite(SS, LOW);
  byte buffer = (10000000 | (T2 << 2) | (T1 << 1) | (T0));
  digitalWrite(SS, HIGH);
}
void SPI_bitModify(byte address, byte mask, byte data) {
  digitalWrite(SS, LOW);
  byte instruction = 5;  // 0000101?
  long buffer;           // 32 bit (4bytes)
  buffer = (instruction << 24) | (address << 16) | (mask << 8) | (data);
  SPI.transfer(&buffer, 4);
  digitalWrite(SS, HIGH);
}

byte SPI_readStatus() {
  digitalWrite(SS, LOW);
  byte instruction = 160;  // 10100000
  SPI.transfer(&instruction, 1);
  int16_t received = SPI.transfer16(&instruction);  // don't care about sending
  byte dataOut = received;
  digitalWrite(SS, HIGH);
  return dataOut;
}

byte SPI_rxStatus() {
  digitalWrite(SS, LOW);
  byte instruction = 176;  // 10110000
  SPI.transfer(&instruction, 1);
  int16_t received = SPI.transfer16(&instruction);  // don't care about sending
  byte dataOut = received;
  digitalWrite(SS, HIGH);
  return dataOut;
}
