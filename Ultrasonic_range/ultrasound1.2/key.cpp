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

unsigned int Key_Detect()
{

   if ((!K1_STATE && Last_K1_State) || (!K2_STATE && Last_K2_State) || (!K3_STATE && Last_K3_State) || (!K4_STATE && Last_K4_State))
   {
      delay(20);
      if (!K1_STATE)
      {
        key = 1;
        Last_K1_State=!Last_K1_State;
        }
         
      else if (!K2_STATE)
         key = 2;
      else if (!K3_STATE)
         key = 3;
      else if (!K4_STATE)
         key = 4;
   }
   else if(K1_STATE && !Last_K1_State)
   {
    delay(20);
    if(K1_STATE)
    {    
      Last_K1_State=!Last_K1_State;
    key=0;
      }

    }
  
//   Last_K1_State = K1_STATE;
//   Last_K2_State = K2_STATE;
//   Last_K3_State = K3_STATE;
//   Last_K4_State = K4_STATE;

   return key;
}
