#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned long dis_int;
unsigned long temp;
unsigned int dis_high;
unsigned int dis_low;
unsigned int temp_high;
unsigned int temp_low;

void setup()
{
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  dis_int = 12345;
  temp = 2345;
  dis_high = dis_int / 100;
  dis_low = dis_int % 100;
  temp_high = temp / 100;
  temp_low = temp % 100;
}

void loop()
{
  // put your main code here, to run repeatedly:
  lcd.print("Dis: ");
  lcd.print(dis_high);
  lcd.print(".");
  lcd.print(dis_low);
  lcd.print(" ");
  lcd.setCursor(13, 0);
  lcd.print("cm");

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print("Tem: ");
  lcd.print(temp_high);
  lcd.print(".");
  lcd.print(temp_low);
  lcd.print(" ");
  lcd.setCursor(11, 1);
  lcd.print("C");
  delay(1000);
  lcd.clear();
}
