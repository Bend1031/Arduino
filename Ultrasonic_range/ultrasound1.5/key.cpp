#include "key.h"

unsigned char key = 0;
unsigned char Last_K1_State = 1;
unsigned char Last_K2_State = 1;
unsigned char Last_K3_State = 1;
unsigned char Last_K4_State = 1;

void Key_Init()
{
  pinMode(K1_PIN, INPUT_PULLUP);
  pinMode(K2_PIN, INPUT_PULLUP);
  pinMode(K3_PIN, INPUT_PULLUP);
  pinMode(K4_PIN, INPUT_PULLUP);
}

//检测按键按下，因为模式切换是靠按下按键实现的，若检测按键按下的低电平，则一直按着按键就会一直切换模式导致混乱
//而我们希望是按一下切一下，因此，需要检测按键的下降沿，即从高电平变到低电平这一过程，即下降沿检测
//KEY_Scan函数就是完成这一功能的
u8 Key_Scan()
{
  u8 K4_STATE_down;
  u8 K3_STATE_down;
  u8 K2_STATE_down;
  u8 K1_STATE_down;
  if (K1_STATE == 0 || K2_STATE == 0 || K3_STATE == 0)
  {
    ifscankey = 1;
    delay(20); //消抖
    if (K1_STATE == 0)
    {

      K1_STATE_down = Last_K1_State && (!K1_STATE);
      Last_K1_State = K1_STATE;
      if (K1_STATE_down)
      {
        ifscankey = 0;
        return (1);
      }
      else
      {
        ifscankey = 0;
        return (0);
      }
    }
    else if (K2_STATE == 0)
    {
      K2_STATE_down = Last_K2_State && (!K2_STATE);
      Last_K2_State = K2_STATE;
      if (K2_STATE_down)
      {
        ifscankey = 0;
        return (2);
      }
      else
      {
        ifscankey = 0;
        return (0);
      }
    }
    else if (K3_STATE == 0)
    {
      K3_STATE_down = Last_K3_State && (!K3_STATE);
      Last_K3_State = K3_STATE;
      if (K3_STATE_down)
      {
        ifscankey = 0;
        return (3);
      }
      else
      {
        ifscankey = 0;
        return (0);
      }
    }
    else if (K4_STATE == 0)
    {
      K4_STATE_down = Last_K4_State && (!K4_STATE);
      Last_K4_State = K4_STATE;
      if (K4_STATE_down)
      {
        ifscankey = 0;
        return (4);
      }
      else
      {
        ifscankey = 0;
        return (0);
      }
    }
  }
  else
  {
    Last_K1_State = 1;
    Last_K2_State = 1;
    Last_K3_State = 1;
    Last_K4_State = 1;
    ifscankey = 0;
    return 0;
  }
}
