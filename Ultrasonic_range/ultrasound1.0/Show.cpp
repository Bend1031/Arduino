#include "Show.h"
LiquidCrystal lcd(RS_PIN, EN_PIN, D4, D5, D6, D7);
void Show_Init()
{
    lcd.begin(16, 2);
}
void ShowData(unsigned long dis, unsigned long temp)
{
    unsigned int dis_high;
    unsigned int dis_low;
    unsigned int temp_high;
    unsigned int temp_low;
    dis_high = dis / 100;
    dis_low = dis % 100;
    temp_high = temp / 100;
    temp_low = temp % 100;
    
    lcd.clear();
    lcd.print("Dis: ");
    lcd.print(dis_high);
    lcd.print(".");
    lcd.print(dis_low);
    lcd.print(" ");
    lcd.setCursor(12, 0);
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
    
}
