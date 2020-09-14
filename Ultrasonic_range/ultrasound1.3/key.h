/*This file defines the keys of the instrument*/
/*Last edit in 2020.9.6*/

#include "system.h"

//From left to right, top to bottom, K1 K2 K3 K4
#define K1_PIN A4
#define K2_PIN A3
#define K3_PIN A1
#define K4_PIN A2

#define K1_STATE digitalRead(K1_PIN)
#define K2_STATE digitalRead(K2_PIN)
#define K3_STATE digitalRead(K3_PIN)
#define K4_STATE digitalRead(K4_PIN)

//extern unsigned char Key;

extern u8 Last_K1_State;
extern u8 Last_K2_State;
extern u8 Last_K3_State;
extern u8 Last_K4_State;

//  Try to use timer rather than delay to eliminate buffeting of keystroke

void Key_Init();
u8 Key_Scan();
