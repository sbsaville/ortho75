#ifndef LAYER_2_H
#define LAYER_2_H

#include "main.h"

LayoutKey layer2Layout[rowsCount][columnsCount] = {
  {{KEY_TILDE},  {KEY_F1},           {KEY_F2},      {KEY_F3},         {KEY_F4},      {KEY_F5},       {KEY_F6},    {KEY_F7},        {KEY_F8},  {KEY_F9},   {KEY_F10},    {KEY_F11}, {KEY_F12},  {KEY_NULL},{KEY_NULL}},
  {{KEY_ALT_TAB},{KEY_QUESTION_MARK},{KEY_NULL},    {KEY_EXCLAMATION},{KEY_ASTERISK},{KEY_NULL},     {KEY_NULL},  {KEY_UNDERSCORE},{KEY_NULL},{KEY_NULL}, {KEY_PERCENT},{KEY_NULL},{KEY_NULL}, {KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},   {KEY_AT},           {KEY_SLASH},   {KEY_DOLLAR},     {KEY_NULL},    {KEY_DEGREES},  {KEY_MINUS}, {KEY_NULL},      {KEY_NULL},{KEY_EQUAL},{KEY_NULL},   {KEY_NULL},{KEY_ENTER},{KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},   {KEY_NULL},         {KEY_ASTERISK},{KEY_CARAT},      {KEY_NULL},    {KEY_BACKSLASH},{KEY_HASH},  {KEY_AMPERSAND}, {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL},{KEY_NULL}},
  {{KEY_RELEASE},{KEY_NULL},         {KEY_NULL},    {KEY_NULL},       {LAYER_2},     {KEY_ENTER},    {KEY_DELETE},{KEY_NULL},      {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL},{KEY_NULL}}
};

#endif
