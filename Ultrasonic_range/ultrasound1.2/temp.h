#include <OneWire.h>
#include <DallasTemperature.h>

// 数据输出脚接开发板数字引脚2
#define ONE_WIRE_BUS A0

void Temp_Init();
int GetTemp();
