#define green 1
#define red 2
#define blue 3

  int BLUE = 6;
  int RED = 4;
  int GREEN = 2;
  int alphabet;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.setTimeout(102
  );
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Input the LED you want on:");

  // while(Serial.available() == 0 ){


  // }
  int input = Serial.parseInt();
  if (input != 0) {
    alphabet = input;
  }
  Serial.print(alphabet);
  
  if(alphabet == green ){

    digitalWrite(RED, LOW);
    digitalWrite(BLUE, LOW);
   

    if((int)(millis()/250) %2 == 0) {
      digitalWrite(GREEN, HIGH);
    } else {
      digitalWrite(GREEN, LOW);
    }


  }else if(alphabet == red){

    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    //delay(500);

  }else if(alphabet == blue){

    digitalWrite(RED, LOW);
    digitalWrite(BLUE, HIGH);
    digitalWrite(GREEN, LOW);
    //delay(500);

  }/*else{

    digitalWrite(RED, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(GREEN, LOW);
    //delay(2000);

  }*/
  

}
