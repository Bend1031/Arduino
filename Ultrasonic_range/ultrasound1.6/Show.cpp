#include "Show.h"
LiquidCrystal lcd(RS_PIN, EN_PIN, D4, D5, D6, D7);
void Show_Init()
{
  lcd.begin(16, 2);
}

void Show_Loading()
{
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Measure System");
  lcd.setCursor(3, 1);
  lcd.print("Loading...");
}

void Show_MainMenu()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Dis: ");
  lcd.setCursor(12, 0);
  lcd.print("cm");

   lcd.setCursor(1, 1);
  lcd.print("Temp: ");
  lcd.setCursor(12, 1);
  lcd.write(0xdf);
  lcd.print("C");
}

void Show_Dis(unsigned long dis)
{
  char dis_char[7];

  if (dis / 10000)
    dis_char[0] = dis / 10000 + 0x30;
  else
    dis_char[0] = ' ';
  dis_char[1] = dis / 1000 % 10 + 0x30;
  dis_char[2] = dis / 100 % 10 + 0x30;
  dis_char[3] = '.';
  dis_char[4] = dis / 10 % 10 + 0x30;
  dis_char[5] = dis % 10 + 0x30;
  dis_char[6] = '\0';

  lcd.setCursor(6, 0);
  lcd.print(dis_char);
}

void Show_TempMenu()
{
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("Temp: ");
  lcd.setCursor(12, 1);
  lcd.write(0xdf);
  lcd.print("C");
}

void Show_Temp()
{
  char temp_char[6];

  temp_char[0] = temp / 1000 + 0x30;
  temp_char[1] = temp / 100 % 10 + 0x30;
  temp_char[2] = '.';
  temp_char[3] = temp / 10 % 10 + 0x30;
  temp_char[4] = temp % 10 + 0x30;
  temp_char[5] = '\0';
  lcd.setCursor(7, 1);
  lcd.print(temp_char);
}
