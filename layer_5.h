#ifndef LAYER_5_H
#define LAYER_5_H

#include "main.h"

LayoutKey layer5Layout[rowsCount][columnsCount] = {
  {{KEY_NULL},   {KEY_NULL},   {KEY_NULL},   {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},      {KEY_NULL},{KEY_PRINTSCREEN},{KEY_NUM_LOCK}},
  {{KEY_NULL},   {KEY_NULL},   {KEY_NULL},   {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},      {KEY_NULL},{KEY_PAUSE},      {KEY_SCROLL_LOCK}},
  {{KEY_NULL},   {KEY_NULL},   {KEY_NULL},   {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},      {KEY_NULL},{KEY_REC},        {KEY_VOL_UP_5}},
  {{KEY_NULL},   {KEY_NULL},   {KEY_NULL},   {KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_RW},  {KEY_FF},        {KEY_NULL},{KEY_VOL_UP},     {KEY_VOL_DOWN_5}},
  {{TRILL_MODE1},{TRILL_MODE2},{TRILL_MODE3},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_NULL},{KEY_MUTE},{LAYER_5}, {KEY_PLAY_PAUSE},{KEY_PREV},{KEY_VOL_DOWN},   {KEY_NEXT}}
};

#endif