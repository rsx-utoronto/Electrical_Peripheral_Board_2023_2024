void setup() {
  pinMode(1, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  //Serial.print(45); // send a byte with the value 45 (-)
  int bytesSent = Serial.print("E");  //send the string "red" and return the length of the string.
  delay(1000);


}
