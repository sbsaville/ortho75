#ifndef LAYER_0_H
#define LAYER_0_H

#include "main.h"

LayoutKey layout0[rowsCount][columnsCount] = {
  {{KEY_ESC},       {KEY_1},       {KEY_2},       {KEY_3},  {KEY_4},  {KEY_5},    {KEY_6},        {KEY_7},  {KEY_8},    {KEY_9},        {KEY_0},        {KEY_MINUS},     {KEY_EQUAL},      {KEY_BACKSPACE},{KEY_DELETE}},
  {{KEY_TAB},       {KEY_Q},       {KEY_W},       {KEY_E},  {KEY_R},  {KEY_T},    {KEY_Y},        {KEY_U},  {KEY_I},    {KEY_O},        {KEY_P},        {KEY_LEFT_BRACE},{KEY_RIGHT_BRACE},{KEY_HOME},     {KEY_END}},
  {{KEY_CAPS_LOCK}, {KEY_A},       {KEY_S},       {KEY_D},  {KEY_F},  {KEY_G},    {KEY_H},        {KEY_J},  {KEY_K},    {KEY_L},        {KEY_SEMICOLON},{KEY_QUOTE},     {KEY_ENTER},      {KEY_INSERT},   {KEY_PAGE_UP}},
  {{KEY_LEFT_SHIFT},{KEY_Z},       {KEY_X},       {KEY_C},  {KEY_V},  {KEY_B},    {KEY_N},        {KEY_M},  {KEY_COMMA},{KEY_PERIOD},   {KEY_SLASH},    {KEY_BACKSLASH}, {KEY_RIGHT_SHIFT},{KEY_UP},       {KEY_PAGE_DOWN}},
  {{KEY_LEFT_CTRL}, {KEY_LEFT_GUI},{KEY_LEFT_ALT},{LAYER_1},{LAYER_2},{KEY_SPACE},{KEY_BACKSPACE},{LAYER_3},{LAYER_4},  {KEY_RIGHT_ALT},{LAYER_5},      {KEY_RIGHT_CTRL},{KEY_LEFT},       {KEY_DOWN},     {KEY_RIGHT}}
};

LayoutKey layout0caps[rowsCount][columnsCount] = {
  {{KEY_ESC},       {KEY_1},       {KEY_2},       {KEY_3},  {KEY_4},  {KEY_5},    {KEY_6},        {KEY_7},  {KEY_8},    {KEY_9},        {KEY_0},        {KEY_MINUS},     {KEY_EQUAL},      {KEY_BACKSPACE},{KEY_DELETE}},
  {{KEY_TAB},       {KEY_Q},       {KEY_W},       {KEY_E},  {KEY_R},  {KEY_T},    {KEY_Y},        {KEY_U},  {KEY_I},    {KEY_O},        {KEY_P},        {KEY_LEFT_BRACE},{KEY_RIGHT_BRACE},{KEY_HOME},     {KEY_END}},
  {{LAYER_MIRROR},  {KEY_A},       {KEY_S},       {KEY_D},  {KEY_F},  {KEY_G},    {KEY_H},        {KEY_J},  {KEY_K},    {KEY_L},        {KEY_SEMICOLON},{KEY_QUOTE},     {KEY_ENTER},      {KEY_INSERT},   {KEY_PAGE_UP}},
  {{KEY_LEFT_SHIFT},{KEY_Z},       {KEY_X},       {KEY_C},  {KEY_V},  {KEY_B},    {KEY_N},        {KEY_M},  {KEY_COMMA},{KEY_PERIOD},   {KEY_SLASH},    {KEY_BACKSLASH}, {KEY_RIGHT_SHIFT},{KEY_UP},       {KEY_PAGE_DOWN}},
  {{KEY_LEFT_CTRL}, {KEY_LEFT_GUI},{KEY_LEFT_ALT},{LAYER_1},{LAYER_2},{KEY_SPACE},{KEY_BACKSPACE},{LAYER_3},{LAYER_4},  {KEY_RIGHT_ALT},{LAYER_5},      {KEY_RIGHT_CTRL},{KEY_LEFT},       {KEY_DOWN},     {KEY_RIGHT}}
};

LayoutKey layout0game[rowsCount][columnsCount] = {
  {{KEY_ESC},       {KEY_1},       {KEY_2},   {KEY_3},   {KEY_4},       {KEY_5},    {KEY_6},        {KEY_7},  {KEY_8},    {KEY_9},        {KEY_0},        {KEY_MINUS},     {KEY_EQUAL},      {KEY_BACKSPACE},{KEY_DELETE}},
  {{KEY_TAB},       {KEY_Q},       {KEY_W},   {KEY_E},   {KEY_R},       {KEY_T},    {KEY_Y},        {KEY_U},  {KEY_I},    {KEY_O},        {KEY_P},        {KEY_LEFT_BRACE},{KEY_RIGHT_BRACE},{KEY_HOME},     {KEY_END}},
  {{KEY_CAPS_LOCK}, {KEY_A},       {KEY_S},   {KEY_D},   {KEY_F},       {KEY_G},    {KEY_H},        {KEY_J},  {KEY_K},    {KEY_L},        {KEY_SEMICOLON},{KEY_QUOTE},     {KEY_ENTER},      {KEY_INSERT},   {KEY_PAGE_UP}},
  {{KEY_LEFT_SHIFT},{KEY_Z},       {KEY_X},   {KEY_C},   {KEY_V},       {KEY_B},    {KEY_N},        {KEY_M},  {KEY_COMMA},{KEY_PERIOD},   {KEY_SLASH},    {KEY_BACKSLASH}, {KEY_RIGHT_SHIFT},{KEY_UP},       {KEY_PAGE_DOWN}},
  {{KEY_LEFT_CTRL}, {KEY_LEFT_GUI},{KEY_NULL},{KEY_NULL},{KEY_LEFT_ALT},{KEY_SPACE},{KEY_BACKSPACE},{LAYER_3},{LAYER_4},  {KEY_RIGHT_ALT},{LAYER_5},      {KEY_RIGHT_CTRL},{KEY_LEFT},       {KEY_DOWN},     {KEY_RIGHT}}
};

#endif

/*     
 *
 *
 */
