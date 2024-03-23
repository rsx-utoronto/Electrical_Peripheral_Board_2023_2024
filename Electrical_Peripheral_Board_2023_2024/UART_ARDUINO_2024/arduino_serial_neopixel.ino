//!!!!!! IMPORTANT: DOENS'T WORK FOR NEOPIXEL FAN //////////////////////////////////////////////////////

#include <Adafruit_NeoPixel.h>

#define DATA_PIN_STRIP 22
#define NUM_LEDS_STRIP 50

#define DATA_PIN_FAN 13
#define NUM_LEDS_FAN 6

#define RBRIGHT_PIN 9
#define GBRIGHT_PIN 10
#define BBRIGHT_PIN 11

#define LED_BRIGHTNESS 64

#define RED 0xFF0000
#define YELLOW 0xFFA500
#define GREEN 0x00FF00
#define CYAN 0x00FFFF
#define BLUE 0x0000FF
#define PURPLE 0xB03060
#define BLACK 0x000000

#define WAIT 0
#define AUTO 1
#define MAN 2
#define GOAL 3

int state = WAIT;
char incomingByte = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS_STRIP, DATA_PIN_STRIP, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel fan = Adafruit_NeoPixel(NUM_LEDS_FAN, DATA_PIN_FAN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(LED_BRIGHTNESS);
  strip.show(); // Initialize all pixels to 'off'
  
  fan.begin();
  fan.setBrightness(LED_BRIGHTNESS);
  fan.show();
  
  pinMode(RBRIGHT_PIN, OUTPUT);
  pinMode(GBRIGHT_PIN, OUTPUT);
  pinMode(BBRIGHT_PIN, OUTPUT);
}

void loop() {
  colorFill(RED);
  delay(1000);

  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    
    switch (state) {
      case WAIT:
        if (incomingByte == 'a' || incomingByte == 'A') {
          state = AUTO;
          colorFill(RED);
        } else if (incomingByte == 'g' || incomingByte == 'G') {
          state = GOAL;
        } else if (incomingByte == 'm' || incomingByte == 'M') {
          state = MAN;
          colorFill(BLUE);
        } else {
          state = WAIT;
        }
        break;
      case AUTO:
        if (incomingByte == 'a' || incomingByte == 'A') {
          state = AUTO;
          colorFill(RED);
        } else if (incomingByte == 'g' || incomingByte == 'G') {
          state = GOAL;
        } else if (incomingByte == 'm' || incomingByte == 'M') {
          state = MAN;
          colorFill(BLUE);
        } else {
          state = WAIT;
        }
        break;
      case MAN:
        if (incomingByte == 'a' || incomingByte == 'A') {
          state = AUTO;
          colorFill(RED);
        } else if (incomingByte == 'm' || incomingByte == 'M') {
          state = MAN;
          colorFill(BLUE);
        } else if (incomingByte == 'g' || incomingByte == 'G') {
          state = GOAL;
        } else {
          state = WAIT;
        }
        break;
      case GOAL:
        blink(GREEN, 500);
        if (incomingByte == 'a' || incomingByte == 'A') {
          state = AUTO;
          colorFill(RED);
        } else if (incomingByte == 'm' || incomingByte == 'M') {
          state = MAN;
          colorFill(BLUE);
        } else if (incomingByte == 'g' || incomingByte == 'G') {
          state = GOAL;
        } else {
          state = WAIT;
        }
        break;
    }
  }

  delay(100);
  Serial.println(state);
  //
}

//void colorFill(uint32_t color) {
//  for (int i = 0; i < NUM_LEDS_FAN; i++) {
//    fan.setPixelColor(i, color);
//  }
//  fan.show();
//  
//  for (int i = 0; i < NUM_LEDS_STRIP; i++) {
//    strip.setPixelColor(i, color);
//  }
//  strip.show();
//  
//  brightFill(color);
//}

void colorFill(uint32_t color) {
  for(int i=0; i<NUM_LEDS_FAN; i++) { // For each pixel in strip...
    fan.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    fan.show();                          //  Update strip to match
    delay(100);                           //  Pause for a moment
  }
}




void brightFill(uint32_t color) {
  analogWrite(RBRIGHT_PIN, (color >> 16) & 0xFF);
  analogWrite(GBRIGHT_PIN, (color >> 8) & 0xFF);
  analogWrite(BBRIGHT_PIN, color & 0xFF);
}

void blink(uint32_t color, int wait) {
  colorFill(BLACK);
  delay(wait);
  colorFill(color);
  delay(wait);
}
