#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>

const uint8_t rowsCount = 5;
const uint8_t rows[rowsCount] = {39, 38, 37, 36, 35};

const uint8_t columnsCount = 15;
const uint8_t columns[columnsCount] = {34,33,32,31,30,29,28,27,26,25,13,14,15,16,17};
                                    // c0 c1 c2 c3 c4 c5 c6 c7 c8 c9 10 11 12 13 14 
struct Key {
  uint8_t row;
  uint8_t column;
  boolean pressed;
};

const uint16_t LAYER_1                       = 1 | 0xA000;
const uint16_t LAYER_2                       = 2 | 0xA000;
const uint16_t LAYER_3                       = 3 | 0xA000;
const uint16_t LAYER_4                       = 4 | 0xA000;
const uint16_t LAYER_5                       = 5 | 0xA000;
const uint16_t LAYER_0CAPS                   = 6 | 0xA000;
const uint16_t LAYER_MIRROR                  = 7 | 0xA000;
const uint16_t LAYER_GAME                    = 8 | 0xA000;
//const uint16_t                             = 9 | 0xA000;

const uint16_t KEY_RELEASE                   = 14 | 0xA000;
const uint16_t KEY_SET0                      = 15 | 0xA000;
const uint16_t KEY_NULL                      = 16 | 0xA000;

const uint16_t KEY_EXCLAMATION               = 17 | 0xA000; // !
const uint16_t KEY_AT                        = 18 | 0xA000; // @
const uint16_t KEY_HASH                      = 19 | 0xA000; // #
const uint16_t KEY_DOLLAR                    = 20 | 0xA000; // $
const uint16_t KEY_PERCENT                   = 21 | 0xA000; // %
const uint16_t KEY_CARAT                     = 22 | 0xA000; // ^
const uint16_t KEY_AMPERSAND                 = 23 | 0xA000; // &
const uint16_t KEY_ASTERISK                  = 24 | 0xA000; // *
const uint16_t KEY_LEFT_PARENTHESIS          = 25 | 0xA000; // (
const uint16_t KEY_RIGHT_PARENTHESIS         = 26 | 0xA000; // )
const uint16_t KEY_UNDERSCORE                = 27 | 0xA000; // _
const uint16_t KEY_PIPE                      = 28 | 0xA000; // |
const uint16_t KEY_LEFT_CHEVRON              = 29 | 0xA000; // <
const uint16_t KEY_RIGHT_CHEVRON             = 30 | 0xA000; // >
const uint16_t KEY_QUESTION_MARK             = 31 | 0xA000; // ?
const uint16_t KEY_COLON                     = 32 | 0xA000; // :
const uint16_t KEY_DBLQUOTE                  = 33 | 0xA000; // "
const uint16_t KEY_SYMBOL_LEFT_BRACE         = 34 | 0xA000; // {
const uint16_t KEY_SYMBOL_RIGHT_BRACE        = 35 | 0xA000; // }
const uint16_t KEY_SYMBOL_TILDE              = 36 | 0xA000; // ~
const uint16_t KEY_PLUS                      = 37 | 0xA000; // +
const uint16_t KEY_DEGREES                   = 39 | 0xA000; // °
const uint16_t KEY_VOL_UP_5                  = 40 | 0xA000;
const uint16_t KEY_VOL_DOWN_5                = 41 | 0xA000;
const uint16_t KEY_MUTE                      = 42 | 0xA000;
const uint16_t TRILL_MODE1                   = 43 | 0xA000;
const uint16_t TRILL_MODE2                   = 44 | 0xA000;
const uint16_t TRILL_MODE3                   = 45 | 0xA000;
const uint16_t KEY_ALT_TAB                   = 46 | 0xA000;
const uint16_t KEY_PREV                      = 47 | 0xA000;
const uint16_t KEY_NEXT                      = 48 | 0xA000;
const uint16_t KEY_RW                        = 49 | 0xA000;
const uint16_t KEY_FF                        = 50 | 0xA000;
const uint16_t KEY_REC                       = 51 | 0xA000;
const uint16_t KEY_REBOOT                    = 52 | 0xA000;
const uint16_t KEY_ALTx                      = 53 | 0xA000;
const uint16_t KEY_ALTy                      = 54 | 0xA000;
const uint16_t KEY_GM0                       = 55 | 0xA000;
const uint16_t KEY_GM1                       = 56 | 0xA000;
const uint16_t MOUSE_LCLICK                  = 57 | 0xA000;
const uint16_t KEY_PLAY_PAUSE                = 58 | 0xA000;
const uint16_t KEY_VOL_UP                    = 59 | 0xA000;
const uint16_t KEY_VOL_DOWN                  = 60 | 0xA000;


const uint16_t KEY_LEFT_BRACKET              = KEY_LEFT_BRACE;
const uint16_t KEY_RIGHT_BRACKET             = KEY_RIGHT_BRACE;

struct LayoutKey {
  uint16_t code;
};

#endif
