#include <Bounce.h>
#include <Trill.h>
#include <Mouse.h>


#include "main.h"
#include "layer_0.h"
#include "layer_1.h"
#include "layer_2.h"
#include "layer_2_3.h"
#include "layer_3.h"
#include "layer_4.h"
#include "layer_5.h"
#include "trillbar.h"
#include "layer_mirror.h"

bool debug = false;
bool debugLedOn = false; 
bool L_1 = 0;
bool L_2 = 0;
bool L_3 = 0;
bool L_4 = 0;
bool L_5 = 0;
bool L_0CAPS = 0;
bool L_MIRROR = 0;
bool L_GAME = 0;

LayoutKey (*currentLayout)[columnsCount] = layout0;

Key keys[rowsCount][columnsCount] = {
 {{0, 0, false},{0, 1, false},{0, 2, false},{0, 3, false},{0, 4, false},{0, 5, false},{0, 6, false},{0, 7, false},{0, 8, false},{0, 9, false},{0, 10, false},{0, 11, false},{0, 12, false},{0, 13, false},{0, 14, false}},
 {{1, 0, false},{1, 1, false},{1, 2, false},{1, 3, false},{1, 4, false},{1, 5, false},{1, 6, false},{1, 7, false},{1, 8, false},{1, 9, false},{1, 10, false},{1, 11, false},{1, 12, false},{1, 13, false},{1, 14, false}},
 {{2, 0, false},{2, 1, false},{2, 2, false},{2, 3, false},{2, 4, false},{2, 5, false},{2, 6, false},{2, 7, false},{2, 8, false},{2, 9, false},{2, 10, false},{2, 11, false},{2, 12, false},{2, 13, false},{2, 14, false}},
 {{3, 0, false},{3, 1, false},{3, 2, false},{3, 3, false},{3, 4, false},{3, 5, false},{3, 6, false},{3, 7, false},{3, 8, false},{3, 9, false},{3, 10, false},{3, 11, false},{3, 12, false},{3, 13, false},{3, 14, false}},
 {{4, 0, false},{4, 1, false},{4, 2, false},{4, 3, false},{4, 4, false},{4, 5, false},{4, 6, false},{4, 7, false},{4, 8, false},{4, 9, false},{4, 10, false},{4, 11, false},{4, 12, false},{4, 13, false},{4, 14, false}}
};

Key* getKey(uint8_t row, uint8_t column) {
  return &keys[row][column];
}

LayoutKey* getLayoutKey(uint8_t row, uint8_t column) {
  return &currentLayout[row][column];
}

void sendKeys() {
  if (!debug) {
    Keyboard.send_now();
  }
}

void L_check() {
  Serial.print("L_1=");      Serial.print(L_1);      Serial.print(" "); 
  Serial.print("L_2=");      Serial.print(L_2);      Serial.print(" ");
  Serial.print("L_3=");      Serial.print(L_3);      Serial.print(" "); 
  Serial.print("L_4=");      Serial.print(L_4);      Serial.print(" "); 
  Serial.print("L_5=");      Serial.print(L_5);      Serial.print(" "); 
  Serial.print("L_0CAPS=");  Serial.print(L_0CAPS);  Serial.print(" "); 
  Serial.print("L_MIRROR="); Serial.print(L_MIRROR); Serial.print(" "); 
  Serial.print("L_GAME=");   Serial.print(L_GAME);   Serial.println("");
}

void setup() {

  Serial.begin(115200);
  
  if (debug) {                               // Setup debug.
    debugLedOn = false;
    pinMode(LED_BUILTIN, OUTPUT);
  }

  for (uint8_t i=0; i<columnsCount; i++) {            // Setup keys.
    pinMode(columns[i], INPUT_PULLUP);                 
  }

  for (uint8_t i=0; i<rowsCount; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], HIGH);
  }

  trillbar::setup();

  Keyboard.begin();
  Mouse.begin();
}

void loop() {

  for (uint8_t i=0; i<rowsCount; i++) {
    digitalWrite(rows[i], LOW);

    for (uint8_t j=0; j<columnsCount; j++) {
      Key* key = getKey(i, j);

      boolean current = !digitalRead(columns[j]);
      boolean previous = key->pressed;
      key->pressed = current;

      LayoutKey* layout = getLayoutKey(key->row, key->column);

      if (current && !previous) {
        keyPressed(key, layout);
      } else if (!current && previous) {
        keyReleased(key, layout);
      }
    }

    digitalWrite(rows[i], HIGH);
    delayMicroseconds(5000);                  // sets polling rate to 200hz
  }

  trillbar::loop();

                                           // active layer management

  if (L_1 == 0 && L_2 == 0 && L_3 == 0 && L_4 == 0 && L_5 == 0 && L_0CAPS == 0 && L_MIRROR == 0 && L_GAME == 0) {
    currentLayout = layout0;
    trillMode = 1;
  }
  else if (L_1 == 0 && L_2 == 0 && L_3 == 0 && L_4 == 0 && L_5 == 0 && L_0CAPS == 1 && L_MIRROR == 0 && L_GAME == 0) {
    currentLayout = layout0caps;
    trillMode = 1;
  }
  else if (L_1 == 0 && L_2 == 0 && L_3 == 0 && L_4 == 0 && L_5 == 0 && L_0CAPS == 0 && L_MIRROR == 0 && L_GAME == 1) {
    currentLayout = layout0game;
    trillMode = 1;
  }
  else if (L_MIRROR == 1) {
    currentLayout = layoutMirror;
  }
  else if (L_1 == 1) {
    currentLayout = layout1;
    trillMode = 3;
  }
  else if (L_2 == 1 && L_3 == 0) {
    currentLayout = layout2;
    trillMode = 2;
  }
  else if (L_2 == 1 && L_3 == 1) {
    currentLayout = layout2_3;
  }
  else if (L_3 == 1 && L_2 == 0) {
    currentLayout = layout3;
  }
  else if (L_4 == 1) {
    currentLayout = layout4;
  }
  else if (L_5 == 1) {
    currentLayout = layout5;
  }
}
                                                         // All of the operations to be performed on key press
void keyPressed(Key* key, LayoutKey* layout) {
  if (layout->code == KEY_NULL) {
  }
  else if (layout->code == TRILL_MODE1) {
    trillMode = 1;
  }
  else if (layout->code == TRILL_MODE2) {
    trillMode = 2;
  }
  else if (layout->code == TRILL_MODE3) {
    trillMode = 3;
  }
  else if (layout->code == MOUSE_LCLICK) {
    Mouse.press(MOUSE_LEFT);
  }
  else if (layout->code == KEY_RELEASE) {
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    Keyboard.releaseAll();
    touchActive = false;
  }
  else if (layout->code == KEY_ALT_TAB) {
    Keyboard.set_modifier(KEY_LEFT_ALT);
    Keyboard.send_now();
    Keyboard.set_key1(KEY_TAB);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    Keyboard.send_now();
  }
  else if (layout->code == KEY_PLAY_PAUSE) {
    Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
    Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
  }
  else if (layout->code == KEY_MUTE) {
    Keyboard.press(KEY_MEDIA_MUTE);
    Keyboard.release(KEY_MEDIA_MUTE);
  }
  else if (layout->code == KEY_VOL_UP) {
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
  }
  else if (layout->code == KEY_VOL_DOWN) {
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
  }
  else if (layout->code == KEY_VOL_UP_5) {
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
    Keyboard.press(KEY_MEDIA_VOLUME_INC);
    Keyboard.release(KEY_MEDIA_VOLUME_INC);
  }
  else if (layout->code == KEY_VOL_DOWN_5) {
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
    Keyboard.press(KEY_MEDIA_VOLUME_DEC);
    Keyboard.release(KEY_MEDIA_VOLUME_DEC);
  }
  else if (layout->code == KEY_NEXT) {
    Keyboard.press(KEY_MEDIA_NEXT_TRACK);
    Keyboard.release(KEY_MEDIA_NEXT_TRACK);
  }
  else if (layout->code == KEY_PREV) {
    Keyboard.press(KEY_MEDIA_PREV_TRACK);
    Keyboard.release(KEY_MEDIA_PREV_TRACK);
  }
  else if (layout->code == KEY_RW) {
    Keyboard.press(KEY_MEDIA_REWIND);
    Keyboard.release(KEY_MEDIA_REWIND);
  }
  else if (layout->code == KEY_FF) {
    Keyboard.press(KEY_MEDIA_FAST_FORWARD);
    Keyboard.release(KEY_MEDIA_FAST_FORWARD);
  }
  else if (layout->code == KEY_REC) {
    Keyboard.press(KEY_MEDIA_RECORD);
    Keyboard.release(KEY_MEDIA_RECORD);
  }
  else if (layout->code == KEY_DEGREES) {
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press(KEYPAD_0);
    Keyboard.release(KEYPAD_0);
    Keyboard.press(KEYPAD_1);
    Keyboard.release(KEYPAD_1);
    Keyboard.press(KEYPAD_7);
    Keyboard.release(KEYPAD_7);
    Keyboard.press(KEYPAD_6);
    Keyboard.release(KEYPAD_6);
    Keyboard.release(KEY_RIGHT_ALT);
  }
  else if (layout->code == KEY_EXCLAMATION) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_1);
    Keyboard.release(KEY_1);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_AT) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_2);
    Keyboard.release(KEY_2);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEY_HASH) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_3);
    Keyboard.release(KEY_3);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEY_DOLLAR) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_4);
    Keyboard.release(KEY_4);
    Keyboard.release(KEY_LEFT_SHIFT);
  }
  else if (layout->code == KEY_PERCENT) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_5);
    Keyboard.release(KEY_5);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_CARAT) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_6);
    Keyboard.release(KEY_6);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_AMPERSAND) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_7);
    Keyboard.release(KEY_7);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_ASTERISK) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_8);
    Keyboard.release(KEY_8);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_LEFT_PARENTHESIS) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_9);
    Keyboard.release(KEY_9);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_RIGHT_PARENTHESIS) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_0);
    Keyboard.release(KEY_0);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_UNDERSCORE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_MINUS);
    Keyboard.release(KEY_MINUS);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_PIPE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_BACKSLASH);
    Keyboard.release(KEY_BACKSLASH);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_DBLQUOTE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_QUOTE);
    Keyboard.release(KEY_QUOTE);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_LEFT_CHEVRON) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_COMMA);
    Keyboard.release(KEY_COMMA);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_RIGHT_CHEVRON) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_PERIOD);
    Keyboard.release(KEY_PERIOD);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_QUESTION_MARK) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_SLASH);
    Keyboard.release(KEY_SLASH);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_COLON) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_SEMICOLON);
    Keyboard.release(KEY_SEMICOLON);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_SYMBOL_LEFT_BRACE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_BRACE);
    Keyboard.release(KEY_LEFT_BRACE);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_SYMBOL_RIGHT_BRACE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_RIGHT_BRACE);
    Keyboard.release(KEY_RIGHT_BRACE);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_SYMBOL_TILDE) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_TILDE);
    Keyboard.release(KEY_TILDE);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_PLUS) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_EQUAL);
    Keyboard.release(KEY_EQUAL);
    Keyboard.release(KEY_LEFT_SHIFT);
  } 
  else if (layout->code == KEY_REBOOT) {
    _reboot_Teensyduino_();
  } 
/*
  else if (layout->code == KEY_ALTx) {
    if (L_GAME == 0) {
      Keyboard.press(KEY_LEFT_ALT);
    }
    else if (L_GAME == 1) {
      L_2 = 1;
    }
  }
  else if (layout->code == KEY_ALTy) {
    if (L_GAME == 0) {
      L_2 = 1;
    }
    else if (L_GAME == 1) {
      Keyboard.press(KEY_LEFT_ALT);
    }
  } 
*/
  else if (layout->code == KEY_SET0) {
    L_1 = 0;
    L_2 = 0;
    L_3 = 0;
    L_4 = 0;
    L_5 = 0;
    L_0CAPS = 0;
    L_MIRROR = 0;
    L_GAME = 0;
  }
  else if (layout->code == LAYER_1) {
    L_1 = 1;
    L_check();
  }
  else if (layout->code == LAYER_2) {
    L_2 = 1;
    L_check();
  }
  else if (layout->code == LAYER_3) {
    L_3 = 1;
    L_check();
  }
  else if (layout->code == LAYER_4) {
    L_4 = 1;
    L_check();
  }
  else if (layout->code == LAYER_5) {
    L_5 = 1;
    L_check();
  }
  else if (layout->code == LAYER_MIRROR) {
    L_MIRROR = 1;
    L_check();
  }
  else if (layout->code == LAYER_0CAPS) {
    L_0CAPS = !L_0CAPS;
    L_check();  
  }
  else if (layout->code == LAYER_GAME) {
    L_GAME = !L_GAME;
    L_check();  
  }
  else {
    Keyboard.press(layout->code);
  }
}
                                                         // All of the operations to be performed on key release
void keyReleased(Key* key, LayoutKey* layout) {
  if (layout->code == KEY_NULL) {
  }
  else if (layout->code == KEY_SET0) {
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_1) {
    L_1 = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_2) {
    L_2 = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_3) {
    L_3 = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_4) {
    L_4 = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_5) {
    L_5 = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_MIRROR) {
    L_MIRROR = 0;
    L_check();
    Keyboard.releaseAll();
  }
  else if (layout->code == LAYER_0CAPS) {
    L_check();
  }
  else if (layout->code == LAYER_GAME) {
    L_check();
  }
/*
  else if (layout->code == KEY_ALTx) {
    if (L_GAME == 0) {
      Keyboard.release(KEY_LEFT_ALT);
    }
    else if (L_GAME == 1) {
      L_2 = 0;
      Keyboard.releaseAll();
      trillMode = 1;
    }
  }
  else if (layout->code == KEY_ALTy) {
    if (L_GAME == 0) {
      L_2 = 0;
      Keyboard.releaseAll();
      trillMode = 1;
    }
    else if (L_GAME == 1) {
      Keyboard.release(KEY_LEFT_ALT);
    }
  }
*/
  else if (layout->code == MOUSE_LCLICK) {
    Mouse.release(MOUSE_LEFT);
  }
  else {
    Keyboard.release(layout->code);
  }


}
