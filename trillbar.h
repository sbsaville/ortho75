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
float holdCounter2 = 0;
float pressCounter = 0;
int trillDual = 0;
int s = 0;

int val1 = 0;
int prev1;
int diff1;
int valD = 0;
int prevD;
int diffD;
int val2 = 0;
int prev2;
int diff2;
int val3 = 0;
int prev3;
int diff3;

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
  diff1 = val1 - prev1;
  prevD = valD;
  valD = trillDual;
  diffD = valD - prevD;
  prev2 = val2;
  val2 = trillAdjusted2;
  diff2 = val2 - prev2;
  prev3 = val3;
  val3 = trillAdjusted3;
  diff3 = val3 - prev3;

  if(trillSensor.getNumTouches() > 0) {                               
    
      for(int t = 0; t < trillSensor.getNumTouches(); t++) {
        trillNumTouches = trillSensor.getNumTouches();
        trillLocation = trillSensor.touchLocation(t);
        trillAdjusted2 = trillLocation / trillSens2;
        trillAdjusted3 = trillLocation / trillSens3;
        trillSize = trillSensor.touchSize(s);
        trillSizeAdjusted = trillSize / trillSizeSens;
        
                                          // single touch section

        if(trillNumTouches == 1) {
          trillAdjusted = trillLocation / trillSens;
          if(trillMode == 1) {
            if (trillSizeAdjusted > 8 && trillSizeAdjusted <= 30) {
//              Serial.println(diff1);
              holdCounter2 = 0;
              holdCounter = holdCounter + 1;                           // starts a counter to be used to prevent initial touches from triggering an operation
              if (holdCounter > 2) {
                if (val1 > prev1 && val1 <= prev1 + 1) {
                  for (int i=0; i<abs(diff1); i++) {
                    Serial.println("left");
                    Keyboard.press(KEY_LEFT);
                    Keyboard.release(KEY_LEFT);
                  } 
                }
                else if (val1 > prev1 + 1 && val1 <= prev1 +2) {
                  for (int i=0; i<abs(diff1); i++) {
                    Serial.println("double left");
                    Keyboard.press(KEY_LEFT);
                    Keyboard.release(KEY_LEFT);
                    Keyboard.press(KEY_LEFT);
                    Keyboard.release(KEY_LEFT);
                  }
                }
                else if (val1 > prev1 + 2) {
                  for (int i=0; i<abs(diff1); i++) {
                    Serial.println("triple left");
                    Keyboard.press(KEY_LEFT);
                    Keyboard.release(KEY_LEFT);
                    Keyboard.press(KEY_LEFT);
                    Keyboard.release(KEY_LEFT);
                    Keyboard.press(KEY_LEFT);
                    Keyboard.release(KEY_LEFT);
                  }
                }
                else if (val1 < prev1 && val1 >= prev1 - 1) {
                  for (int i=0; i<abs(diff1); i++) {
                    Serial.println("right");
                    Keyboard.press(KEY_RIGHT);
                    Keyboard.release(KEY_RIGHT);
                  }
                }
                else if (val1 < prev1 - 1 && val1 >= prev1 -2) {
                  for (int i=0; i<abs(diff1); i++) {
                    Serial.println("double right");
                    Keyboard.press(KEY_RIGHT);
                    Keyboard.release(KEY_RIGHT);
                    Keyboard.press(KEY_RIGHT);
                    Keyboard.release(KEY_RIGHT);
                  }
                }
                else if (val1 < prev1 - 2) {
                  for (int i=0; i<abs(diff1); i++) {
                    Serial.println("triple right");
                    Keyboard.press(KEY_RIGHT);
                    Keyboard.release(KEY_RIGHT);
                    Keyboard.press(KEY_RIGHT);
                    Keyboard.release(KEY_RIGHT);
                    Keyboard.press(KEY_RIGHT);
                    Keyboard.release(KEY_RIGHT);
                  }
                }
              }
            }
          }
          else if(trillMode == 2) {
            if (trillSizeAdjusted > 8) {
              holdCounter = holdCounter + 1;
              if (holdCounter > 2) {
                if (val2 > prev2) {
                  for (int i=0; i<abs(diff2); i++) {
                    Serial.println("volume down");
                    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
                    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
                  }
                }
                else if (val2 < prev2) {
                  for (int i=0; i<abs(diff2); i++) {
                    Serial.println("volume up");
                    Keyboard.press(KEY_MEDIA_VOLUME_INC);
                    Keyboard.release(KEY_MEDIA_VOLUME_INC);
                  }
                }
              }
            }
          }
          else if (trillMode == 3) {
            if (trillSizeAdjusted > 8) {
              holdCounter = holdCounter + 1;
              if (holdCounter > 2) {
                if (val3 > prev3 && val3 <= prev3 + 1) {
                  for (int i=0; i<abs(diff3); i++) {
                    Serial.println("scroll down");
                    Mouse.scroll(-1);
                  }
                }
                else if (val3 > prev3 + 1 && val3 <= prev3 + 2) {
                  for (int i=0; i<abs(diff3); i++) {
                    Serial.println("scroll down");
                    Mouse.scroll(-2);
                  }
                }
                else if (val3 > prev3 + 2) {
                  for (int i=0; i<abs(diff3); i++) {
                    Serial.println("scroll down");
                    Mouse.scroll(-3);
                  }
                }
                else if (val3 < prev3 && val3 >= prev3 - 1) {
                  for (int i=0; i<abs(diff3); i++) {
                    Serial.println("scroll up");
                    Mouse.scroll(+1);
                  }
                }
                else if (val3 < prev3 - 1 && val3 >= prev3 - 2) {
                  for (int i=0; i<abs(diff3); i++) {
                    Serial.println("scroll up");
                    Mouse.scroll(+2);
                  }
                }
                else if (val3 < prev3 - 2) {
                  for (int i=0; i<abs(diff3); i++) {
                    Serial.println("scroll up");
                    Mouse.scroll(+3);
                  }
                }
              }
            }
          }
        }
                                             // dual touch volume adjustment

        else if(trillNumTouches == 2 && trillSizeAdjusted > 8 || trillNumTouches == 1 && trillSizeAdjusted > 30 && trillSizeAdjusted <= 50 ) {
          trillDual = ((trillSensor.touchLocation(0) + trillSensor.touchLocation(1)) / 2) / trillSens2;
          holdCounter = 0;
          holdCounter2 = holdCounter2 + 1;
          if (holdCounter2 > 4) {
            if (valD > prevD) {
              for (int d=0; d<abs(diffD); d++) {
                Serial.println("volume down");
                Keyboard.press(KEY_MEDIA_VOLUME_DEC);
                Keyboard.release(KEY_MEDIA_VOLUME_DEC);
              }
            }
            else if (valD < prevD) {
              for (int d=0; d<abs(diffD); d++) {
                Serial.println("volume up");
                Keyboard.press(KEY_MEDIA_VOLUME_INC);
                Keyboard.release(KEY_MEDIA_VOLUME_INC);
              }
            }
          }
        }
        else if(trillNumTouches == 3 || trillSizeAdjusted >= 50) {
          pressCounter = pressCounter + 1;
          Serial.println(pressCounter);
        }
      
      }
      touchActive = true;
      delay(1);                                   // sets polling rate of trill
  }
  else if(touchActive) {
//    Serial.println("0 0");
    touchActive = false;
    holdCounter = 0;
    holdCounter2 = 0;
    if (pressCounter > 1 && pressCounter < 35) {
      Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
      Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
    }
    pressCounter = 0;
  }
}

#endif
