#ifndef MASTER_H
#define MASTER_H
#include <Arduino.h>
#include <SPI.h>  //Library for SPI

void SPI_Reset();
int16_t SPI_Read(byte address, int DataSize);
byte SPI_ReadRXBuffer(int n, int m);
void SPI_LoadTXBuffer(int a, int b, int c, byte dataIn);
void SPI_RTS(int T2, int T1, int T0);
void SPI_bitModify(byte address, byte mask, byte data);
byte SPI_readStatus();
byte SPI_rxStatus();

#endif
