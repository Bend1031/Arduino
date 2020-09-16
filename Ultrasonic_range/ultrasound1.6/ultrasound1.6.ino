#include "temp.h"
#include "key.h"
#include "CS100.h"
#include "Show.h"
#include "system.h"
// 初始化针脚

CSUltra ca;

void setup()
{
  // put your setup code here, to run once:
  pinMode(STATE_LED_PIN, OUTPUT);
  digitalWrite(STATE_LED_PIN, LOW);
  Show_Init();
  Show_Loading();
  ca.CSUltra_Init();
  Key_Init();
  Temp_Init();
  delay(1500);
  Serial.begin(115200);
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
      state = SMEA;     //转入测距模式
    last_state = SIDLE;
    break;
  }

  case SMEA: //执行测距模块
  {
    digitalWrite(STATE_LED_PIN, HIGH);
    GetTemp();
    ca.Mea();
    Show_Dis(ca.dis);
    Show_Temp();
    last_state = SMEA;
    state = SIDLE;
    digitalWrite(STATE_LED_PIN, LOW);
    break;
  }
  }
}
