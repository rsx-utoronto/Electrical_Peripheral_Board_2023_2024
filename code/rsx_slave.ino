#include <SPI.h>

byte m_send = 0;
bool received;
byte Slavereceived, Slavesend;

ISR (SPI_STC_vect)                        
{
  Slavereceived = SPDR; 
  received = true;                        
}

void setup() {
  // put your setup code here, to run once:
  // settings = SPISettings()
  //SPI.begin();
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);    
  SPCR |= _BV(SPE);                  
  received = false;

  SPI.attachInterrupt(); //takes a function handler. i guess it implicitly picks ISR???          

  //only need to begin transaction if there may be multiple interactions going on at once (multiple masters)

}

void loop() {
  // put your main code here, to run repeatedly:
    // m_receive=SPI.transfer(m_send); 
    Serial.println(Slavereceived);
    Slavesend=m_send;                             
    SPDR = Slavesend;                       
    delay(1000);



}
