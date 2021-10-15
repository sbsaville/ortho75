#ifndef TRILLBAR_H
#define TRILLBAR_H

#include "main.h"

Trill trillSensor;
boolean touchActive = false;

int trillMode = 1;            // trill mode is 1 on boot
const int trillSens = 75;          // smaller numbers are more sensitive,
const int trillSens2 = 50;          // larger numbers less
const int trillSens3 = 25;
const int trillSizeSens = 200; 
int trillAdjusted = 0;
int trillLocation = 0;
int trillAdjusted2 = 0;
int trillAdjusted3 = 0;
int trillNumTouches = 0;
int trillSize = 0;
int trillSizeAdjusted = 0;
float holdCounter = 0;
float pressCounter = 0;
int trillDual = 0;

int val1 = 0;
int prev1;
int valD = 0;
int prevD;
int val2 = 0;
int prev2;
int val3 = 0;
int prev3;

class trillbar {
public:
    static void setup();
    static void loop();
};

void trillbar::setup() {
  int ret = trillSensor.setup(Trill::TRILL_BAR);
  if(ret != 0) {
    Serial.println("failed to initialise trillSensor");
    Serial.print("Error code: ");
    Serial.println(ret);
  }
}

void trillbar::loop() {

  trillSensor.read();                         // initializes trill
  
  prev1 = val1;                               // saves previous values to compare them to current ones
  val1 = trillAdjusted;
  prevD = valD;
  valD = trillDual;
  prev2 = val2;
  val2 = trillAdjusted2;
  prev3 = val3;
  val3 = trillAdjusted3;

  if(trillSensor.getNumTouches() > 0) {                               // must contain all trill operatons
    holdCounter = holdCounter + 1;                                    // starts a counter to be used to prevent initial touches from triggering an operation
      for(int i = 0; i < trillSensor.getNumTouches(); i++) {
        Serial.print(pressCounter);
        Serial.print(" ");
        Serial.print(holdCounter);
        Serial.print(" ");
        Serial.print(trillSensor.getNumTouches());
        Serial.print(" ");
        Serial.print(trillSensor.touchLocation(i));
        Serial.print(" ");
        Serial.print(trillSensor.touchSize(i));
        Serial.print(" ");
        trillNumTouches = trillSensor.getNumTouches();
        trillLocation = trillSensor.touchLocation(i);
        trillAdjusted = trillLocation / trillSens;
        trillAdjusted2 = trillLocation / trillSens2;
        trillAdjusted3 = trillLocation / trillSens3;
        trillSize = trillSensor.touchSize(i);
        Serial.print(trillAdjusted);
        Serial.print(" ");
        trillSizeAdjusted = trillSize / trillSizeSens;
        Serial.print(trillSizeAdjusted);
        Serial.print(" ");
        trillDual = ((trillSensor.touchLocation(0) + trillSensor.touchLocation(1)) / 2) / trillSens2;

        if(trillNumTouches == 1) {
          if(trillMode == 1) {
            if (trillSizeAdjusted > 10 && trillSizeAdjusted <= 30) {
              if (holdCounter > 2) {
                if (val1 > prev1) {
                  Serial.println("left");
                  Keyboard.press(KEY_LEFT);
                  Keyboard.release(KEY_LEFT);
                } 
                else if (val1 < prev1) {
                  Serial.println("right");
                  Keyboard.press(KEY_RIGHT);
                  Keyboard.release(KEY_RIGHT);
                }
              }
            }
            if (trillSizeAdjusted > 30 && trillSizeAdjusted <= 50) {
              if (holdCounter > 2) {
                if (val2 > prev2) {
                  Serial.println("volume down");
                  Keyboard.press(KEY_MEDIA_VOLUME_DEC);
                  Keyboard.release(KEY_MEDIA_VOLUME_DEC);
                } 
                else if (val2 < prev2) {
                  Serial.println("volume up");
                  Keyboard.press(KEY_MEDIA_VOLUME_INC);
                  Keyboard.release(KEY_MEDIA_VOLUME_INC);
                }
              }
            }
          }
          else if(trillMode == 2) {
            if (trillSizeAdjusted > 10) {
              if (holdCounter > 2) {
                if (val1 != prev1) {
                  Serial.println("space");
                  Keyboard.press(KEY_SPACE);
                  Keyboard.release(KEY_SPACE);
                }
              }
            }
          }
          else if (trillMode == 3) {
            if (trillSizeAdjusted > 10) {
              if (holdCounter > 2) {
                if (val3 > prev3) {
                  Serial.println("scroll down");
                  Mouse.scroll(-3);
                } 
                else if (val3 < prev3) {
                  Serial.println("scroll up");
                  Mouse.scroll(+3);
                }
              }
            }
          }
        }
          
        else if(trillNumTouches == 2) {
          if (trillSizeAdjusted > 10) {
            if (holdCounter > 2) {
              if (valD > prevD) {
                Serial.println("volume down");
                Keyboard.press(KEY_MEDIA_VOLUME_DEC);
                Keyboard.release(KEY_MEDIA_VOLUME_DEC);
              } 
              else if (valD < prevD) {
                Serial.println("volume up");
                Keyboard.press(KEY_MEDIA_VOLUME_INC);
                Keyboard.release(KEY_MEDIA_VOLUME_INC);
             }
            }
          }
        }
        else if(trillNumTouches == 3) {
          pressCounter = pressCounter + 1;
        }
        
    }
    Serial.println("");
    touchActive = true;
   delay(5);                                   // sets polling rate of trill
  }
  else if(touchActive) {
    Serial.println("0 0");
    touchActive = false;
    holdCounter = 0;
    if (pressCounter > 1 && pressCounter < 35) {
      Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
      Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
    }
    pressCounter = 0;
  }
}

#endif
