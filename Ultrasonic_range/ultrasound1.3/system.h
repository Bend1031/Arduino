/*This file defines the basic functions of the instrument*/
/*Last edit in 2020.9.6*/
#include <arduino.h>
#include <LiquidCrystal.h>
#include <MsTimer2.h>

#define BUZZER_PIN 10
#define STATE_LED_PIN 9

#define SMAIN_MENU 0
#define SIDLE 1
#define SMEA 2
#define SHOW_TEMP 3

typedef unsigned char u8;

extern unsigned char key_state;
extern unsigned char last_state;
extern unsigned char state;
extern unsigned long temp;

void Timer_Init();
void onTimer();
