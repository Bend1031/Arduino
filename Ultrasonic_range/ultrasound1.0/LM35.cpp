#include "LM35.h"

LMTem::LMTem()
{
  temp=0;
  raw_data=0;
}

LMTem::GetData()
{
  raw_data=analogRead(TEM_DATA_PIN);
  temp=raw_data*48828/1000;
}
