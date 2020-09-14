#include "temp.h"
#include "key.h"
#include "CS100.h"
#include "Show.h"
#include "system.h"
// 初始化针脚

CSUltra ca;
unsigned char key_state = 0;
unsigned char State = SIDLE;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  ca.CSUltra_Init();
  Show_Init();
  Key_Init();
  Temp_Init();
}

void loop()
{
  // put your main code here, to run repeatedly:

  key_state = Key_Detect();
  switch (State)
  {
  case SIDLE: //等待按键中
  {
    if (key_state == 1) //Key1按下
    {
      State = SMEA; //转入测距模式
      //Serial.println(key_state);
      Serial.println(GetTemp());
    }
    else
    {
    }
  }
  break;

  case SMEA: //执行测距模块
  {
    //Serial.println(State);
    State = SIDLE;
    //Serial.println(State);
    ca.Getdata();
    ca.time2dis(GetTemp());
    ShowData(ca.dis_int, GetTemp());
    //Serial.println(key_state);
  }
  break;
  }
}
