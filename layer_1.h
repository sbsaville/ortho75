#ifndef LAYER_1_H
#define LAYER_1_H

#include "main.h"

LayoutKey layout1[rowsCount][columnsCount] = {
  {{KEY_SYMBOL_TILDE},{KEY_F13}, {KEY_F14},      {KEY_F15},     {KEY_F16},  {KEY_F17},  {KEY_F18},      {KEY_F19}, {KEY_F20}, {KEY_F21}, {KEY_F22}, {KEY_F23},      {KEY_F24},  {KEY_NULL},{KEY_NULL}},
  {{KEYPAD_7},        {KEYPAD_8},{KEYPAD_9},     {KEY_QUOTE},   {KEY_NULL}, {KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEYPAD_7},{KEYPAD_8},{KEYPAD_9},     {KEY_NULL}, {KEY_NULL},{KEY_NULL}},
  {{KEYPAD_4},        {KEYPAD_5},{KEYPAD_6},     {KEY_DBLQUOTE},{KEY_ENTER},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEYPAD_4},{KEYPAD_5},{KEYPAD_6},     {KEY_ENTER},{KEY_NULL},{KEY_NULL}},
  {{KEYPAD_1},        {KEYPAD_2},{KEYPAD_3},     {KEY_PLUS},    {KEY_MINUS},{KEY_NULL}, {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEYPAD_1},{KEYPAD_2},{KEYPAD_3},     {KEY_NULL}, {KEY_NULL},{KEY_NULL}},
  {{KEYPAD_0},        {KEYPAD_0},{KEYPAD_PERIOD},{LAYER_1},     {KEY_NULL}, {KEY_SPACE},{KEY_BACKSPACE},{KEY_NULL},{KEY_NULL},{KEYPAD_0},{KEYPAD_0},{KEYPAD_PERIOD},{KEY_NULL}, {KEY_NULL},{KEY_NULL}}
};

#endif
