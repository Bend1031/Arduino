#include "system.h"
#include <OneWire.h>
#include <DallasTemperature.h>

// 数据输出脚接单片机A0
#define ONE_WIRE_BUS A0

void Temp_Init();
int GetTemp();
