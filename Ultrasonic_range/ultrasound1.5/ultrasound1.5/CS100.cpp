#include "CS100.h"

//Constructor function
CSUltra::CSUltra()
{
  time_us=0;
  dis=0;
  dis_int = 0;
}

//管脚初始化
void CSUltra::CSUltra_Init()
{
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
}

//获取超声波返回的脉冲时长
unsigned long CSUltra::Getdata()
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
unsigned long CSUltra::time2dis()
{
  double temp_double = 0.0;
  double v = 0.0;
  double dis = 0.0;
  temp_double = double(temp) / 100.0;
  v=332.0+0.607*temp_double;
  dis = v * time_us / 2 / 10000;
  dis_int = long(dis * 100.0);
  
  return dis_int;
}

void CSUltra::Mea()
{
  unsigned long dis_raw[AVER_NUM];
  
  u8 MSB=AVER_NUM-1;//排序后利用准则剔除，剔除完后数组有多少个数-1
  u8 LSB=0;//排序后利用准则剔除，剔除完后最小数据所在数组位数

  MDP mdp;

  for(u8 i=0;i<AVER_NUM;i++)
  {
    Getdata();
    dis_raw[i]=time2dis();
    delay(20);
  }
  
  for(u8 i=0;i<AVER_NUM;i++)
  {
    double gmin=0.0,gmax=0.0;
    mdp=standard_diff(dis_raw,MSB,LSB);
    sort(dis_raw,MSB,LSB);
    
    gmin=(mdp.data_ave-dis_raw[LSB])/mdp.data_sdiff;
    gmax=(dis_raw[MSB]-mdp.data_ave)/mdp.data_sdiff;
    if(gmax>=Grubbs_lut5[MSB-LSB-4])
      MSB--;
    else if(gmin>=Grubbs_lut5[MSB-LSB-4])
      LSB++;
    else
      break;
  }
  dis=(unsigned long)(mdp.data_ave+0.5);
}
