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

#ifndef _SYSTEM_H_             //如果没有定义宏_MY_HEAD_H_
#define _SYSTEM_H_             //则，定义该宏名
//以下是被保护的代码区
//进行相应的全局变量和结构体类型定义
typedef unsigned char u8;

extern unsigned char key_state;
extern unsigned char last_state;
extern unsigned char state;
extern unsigned long temp;
extern bool ifscankey;

extern float Grubbs_lut1[16];
extern float Grubbs_lut5[16];

typedef struct mdata_process 
{
  double data_ave;
  double data_sdiff;
}MDP;
#endif     

MDP standard_diff(unsigned long *data,u8 MSB,u8 LSB);
void sort(unsigned long *data,u8 MSB,u8 LSB);
