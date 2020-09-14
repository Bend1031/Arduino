#include "temp.h"
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void Temp_Init()
{
    sensors.begin();
}

int GetTemp()
{
     //float temp;
    unsigned long temp=0;
    sensors.requestTemperatures(); // 发送命令获取温度
    temp=int(100*sensors.getTempCByIndex(0));
   //temp=sensors.getTempCByIndex(0);

    return temp;

}
