
// see http://playground.arduino.cc/Main/LedControl#Source
#include <LedControl.h>

// Connections to MAX7219
const int LC_CLK   = 2;
const int LC_LOAD  = 3;
const int LC_DATA  = 4;

const int DELAY = 500; // delay in ms between blinks

// connect to max7219
LedControl lc=LedControl(LC_DATA, LC_CLK, LC_LOAD, 1); 

void setup() {

  // setup pins
  pinMode (LC_CLK, OUTPUT);
  pinMode (LC_LOAD, OUTPUT);
  pinMode (LC_DATA, OUTPUT);

  // turn on LED controller
  lc.shutdown(0,false);
  
  // set intensity to medium 0..15)
  lc.setIntensity(0,8);
}

void loop(){
  // test individual
  blinkIndividualLeds();
  
  // test row and column grouping
  blinkRowsAndColumns();
}

void blinkIndividualLeds(){  
  
  // top left
  lc.setLed(0,0,0,true);
  delay(DELAY);
  lc.clearDisplay(0);
  
  // top right
  lc.setLed(0,0,1,true);
  delay(DELAY);
  lc.clearDisplay(0);
  
  // bottom left
  lc.setLed(0,1,0,true);
  delay(DELAY);
  lc.clearDisplay(0);
  
  // bottom right
  lc.setLed(0,1,1,true);
  delay(DELAY);
  lc.clearDisplay(0);
}

void blinkRowsAndColumns(){
  // first two leds of first row
  lc.setRow(0,0,B11000000);
  delay(DELAY);
  lc.clearDisplay(0);
  // first two leds of second row
  lc.setRow(0,1,B11000000);
  delay(DELAY);
  lc.clearDisplay(0);
  // first two leds of first column
  lc.setColumn(0,0,B11000000);
  delay(DELAY);
  lc.clearDisplay(0);
  // first two leds of second column
  lc.setColumn(0,1,B11000000);
  delay(DELAY);
  lc.clearDisplay(0);
}