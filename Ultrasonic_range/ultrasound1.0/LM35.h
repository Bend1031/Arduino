/*This file defines the LM35 temperature's drivers*/
/*Last edit in 2020.9.6*/

#include "system.h"

#define TEM_DATA_PIN A0

//  Find the relationship between AD value and temperature

class LMTem
{
  public:
  unsigned long temp;
  int GetData();
  
  LMTem();
  protected:
  unsigned long raw_data;
  private:
};
