//code from https://www.electroniclinic.com/serial-communication-between-two-arduino-boards/#:~:text=in%20this%20way!-,How%20to%20serially%20connect%20two%20Arduino%20Boards%3F,of%20the%20other%20Arduino%20board.
char Mymessage[1] = "b"; //String data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write(Mymessage,1); //Write the serial data
  Serial.write('\n');
 
  delay(1000);
}
