/*This file defines the CS100 ultrasound chip's drivers*/
/*Last edit in 2020.9.6*/

#include "system.h"

#define ECHO_PIN 2
#define TRIG_PIN 4
#define AVER_NUM 30

//  Basic data processing methods is recommended, such as
//  Averaging the testing values of repeated measurements
//  Compensating the effect of temperature on the speed of sound
//  Calibration
//  ......

class CSUltra
{
  public:
    unsigned long dis;
    unsigned int temp;

    void CSUltra_Init();

    int Getdata();
    int time2dis();
    void Mea();

    CSUltra();

  protected:
    unsigned long dis_int;
    unsigned long time_us;

  private:
};
