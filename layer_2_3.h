#ifndef LAYER_2_3_H
#define LAYER_2_3_H

#include "main.h"

LayoutKey layout2_3[rowsCount][columnsCount] = {
  {{KEY_NULL},{KEY_NULL},         {KEY_NULL},    {KEY_NULL},       {KEY_NULL},    {KEY_NULL},     {KEY_NULL},  {KEY_NULL},      {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},{KEY_QUESTION_MARK},{KEY_NULL},    {KEY_EXCLAMATION},{KEY_ASTERISK},{KEY_NULL},     {KEY_NULL},  {KEY_UNDERSCORE},{KEY_NULL},{KEY_NULL}, {KEY_PERCENT},{KEY_NULL},{KEY_NULL}, {KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},{KEY_AT},           {KEY_SLASH},   {KEY_DOLLAR},     {KEY_NULL},    {KEY_DEGREES},  {KEY_MINUS}, {KEY_NULL},      {KEY_NULL},{KEY_EQUAL},{KEY_NULL},   {KEY_NULL},{KEY_ENTER},{KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},         {KEY_ASTERISK},{KEY_CARAT},      {KEY_NULL},    {KEY_BACKSLASH},{KEY_HASH},  {KEY_AMPERSAND}, {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL},{KEY_NULL}},
  {{KEY_NULL},{KEY_NULL},         {KEY_NULL},    {KEY_NULL},       {LAYER_2},     {KEY_SPACE},    {KEY_SPACE}, {LAYER_3},       {KEY_NULL},{KEY_NULL}, {KEY_NULL},   {KEY_NULL},{KEY_NULL}, {KEY_NULL},{KEY_NULL}}
};

#endif
