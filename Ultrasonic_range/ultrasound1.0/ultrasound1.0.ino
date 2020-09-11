#include "LM35.h"
#include "key.h"
#include "CS100.h"
#include <LiquidCrystal.h>

// 初始化针脚
const int rs = 12, en = 11, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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
  ca.temp=2500;

  lcd.begin(16, 2);
}

void loop()
{
  // put your main code here, to run repeatedly:
  ca.Getdata();
  ca.time2dis();
  cb.GetData();
  lcd.print(ca.dis_int);
  lcd.setCursor(0, 0);
  
  Serial.print(ca.dis_int);
  Serial.println();
  Serial.print(cb.temp);
  Serial.println();
  delay(500);
  lcd.clear();

}
