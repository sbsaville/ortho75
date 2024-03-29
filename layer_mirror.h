#ifndef LAYER_MIRROR_H
#define LAYER_MIRROR_H

#include "main.h"

LayoutKey layoutMirror[rowsCount][columnsCount] = {
  {{KEY_0},         {KEY_9},       {KEY_8},       {KEY_7},   {KEY_6},         {KEY_5},    {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_P},         {KEY_O},       {KEY_I},       {KEY_U},   {KEY_Y},         {KEY_T},    {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{LAYER_MIRROR},  {KEY_L},       {KEY_K},       {KEY_J},   {KEY_H},         {KEY_G},    {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_LEFT_SHIFT},{KEY_PERIOD},  {KEY_COMMA},   {KEY_M},   {KEY_N},         {KEY_B},    {KEY_NULL},     {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_LEFT_CTRL}, {KEY_LEFT_GUI},{KEY_LEFT_ALT},{KEY_NULL},{KEY_LEFT_SHIFT},{KEY_SPACE},{KEY_BACKSPACE},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}}
};

#endif

/*
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL}},
*/
