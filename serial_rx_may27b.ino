char Mymessage[1]; //Initialized variable to store recieved data
  
  void setup() {
    // Begin the Serial at 115200 Baud
    Serial.begin(115200);
  }
  
  void loop() {
    byte n = Serial.available();
    if(n != 0)  {
      byte m = Serial.readBytes(Mymessage, 1);
      Mymessage[m] = '\0'; //inserting null-charcater
      Serial.println(Mymessage);
      Serial.print("");
    }
  }
