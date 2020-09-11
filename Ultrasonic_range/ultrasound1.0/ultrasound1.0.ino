#include "LM35.h"
#include "key.h"
#include "CS100.h"
#include "Show.h"

// 初始化针脚

CSUltra ca;
LMTem cb;

void setup()
{
  // put your setup code here, to run once:

  //debug code
  Serial.begin(9600);
  Serial.println("Ultrasonic sensor:");
  //

  ca.CSUltra_Init();
  ca.temp = 2500;
  Show_Init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  ca.Getdata();
  ca.time2dis();
  cb.GetData();
  ShowData(ca.dis_int, cb.temp);
  delay(1000);
}
