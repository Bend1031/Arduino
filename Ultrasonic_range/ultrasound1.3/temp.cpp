#include "temp.h"
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void Temp_Init()
{
  sensors.begin();
}

int GetTemp()
{
  sensors.requestTemperatures(); // 发送命令获取温度
  temp = int(100 * sensors.getTempCByIndex(0));

  return temp;
}
