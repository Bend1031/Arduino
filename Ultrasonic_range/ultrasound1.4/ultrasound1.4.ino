#include "temp.h"
#include "key.h"
#include "CS100.h"
#include "Show.h"
#include "system.h"
// 初始化针脚

CSUltra ca;

void Timer_Init()
{
  MsTimer2::set(2000, onTimer); //设置中断，每2000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
}

void onTimer()
{
  GetTemp();
  if (state == SHOW_TEMP)
    Show_Temp();
}

void setup()
{
  // put your setup code here, to run once:
  Show_Init();
  Show_Loading();
  ca.CSUltra_Init();
  Key_Init();
  Temp_Init();
  delay(1000);
  Timer_Init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  key_state = Key_Scan();
  switch (state)
  {
    case SMAIN_MENU:
      {
        Show_MainMenu();
        state = SIDLE;
        last_state = SMAIN_MENU;
        break;
      }

    case SIDLE: //空闲状态
      {
        if (key_state == 1) //Key1按下
          state = SMEA; //转入测距模式

        else if (key_state == 3)
          state = SHOW_TEMP;

        last_state = SIDLE;
        break;
      }

    case SMEA: //执行测距模块
      {
        ca.Mea();
        Show_Dis(ca.dis);
        last_state = SMEA;
        state = SIDLE;
        break;
      }

    case SHOW_TEMP: //空闲状态
      {
        if (key_state == 3) //Key3按下
          state = SMAIN_MENU; //转入主菜单

        if (last_state != SHOW_TEMP)
          Show_TempMenu();

        last_state = SHOW_TEMP;
        break;
      }
  }
}
