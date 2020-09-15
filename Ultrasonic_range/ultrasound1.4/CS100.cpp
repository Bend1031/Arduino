#include "CS100.h"

//Constructor function
CSUltra::CSUltra()
{
  time_us = 0;
  dis = 0;
  temp = 0;
  dis_int = 0;
}

//管脚初始化
void CSUltra::CSUltra_Init()
{
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

//获取超声波返回的脉冲时长
int CSUltra::Getdata()
{
  // 产生一个10us的高脉冲去触发TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  time_us = pulseIn(ECHO_PIN, HIGH);
  return time_us;
}

//脉冲时长转化成距离
int CSUltra::time2dis()
{
  double temp_double = 0.0;
  double v = 0.0;
  double dis = 0.0;
  temp_double = double(temp) / 100;
  v = 331.4 * sqrt(temp_double / 273.16 + 1);
  //v=332+0.607*temp;
  dis = v * time_us / 2 / 10000;
  dis_int = long(dis * 100.0);

  return dis_int;
}

void CSUltra::Mea()
{
  unsigned long dis_sum = 0;
  for (u8 i = 0; i < AVER_NUM; i++)
  {
    Getdata();
    dis_sum += time2dis();
    delay(10);
  }
  dis = dis_sum / AVER_NUM;
}
