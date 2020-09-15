#include "system.h"

u8 key_state = 0;
u8 last_state = SMAIN_MENU;
u8 state = SMAIN_MENU;
unsigned long temp=0;
bool ifscankey=0;

float Grubbs_lut1[16]={1.75,1.94,2.1,2.22,2.32,2.41,2.48,2.55,2.61,2.66,2.7,2.75,2.78,2.82,2.85,2.88};
float Grubbs_lut5[16]={1.67,1.82,1.94,2.03,2.11,2.18,2.23,2.28,2.33,2.37,2.41,2.44,2.48,2.5,2.53,2.56};

MDP standard_diff(unsigned long *data,u8 MSB,u8 LSB)
{
  double data_diff_sum=0;
  double data_sum=0;
  MDP mdp;
  
  for(u8 i=LSB;i<MSB+1;i++)
    data_sum+=double(data[i]);
    
  mdp.data_ave=data_sum/(MSB-LSB+1);
  
  for(u8 i=LSB;i<MSB+1;i++)
    data_diff_sum+=(double(data[i]-mdp.data_ave))*(double(data[i]-mdp.data_ave));
  mdp.data_sdiff=sqrt(data_diff_sum/(MSB-LSB));
  return mdp;
}

void sort(unsigned long *data,u8 MSB,u8 LSB)
{
  unsigned long temp=0;
  for (u8 i=LSB;i<MSB+1;i++) // 10个数，10 - 1轮冒泡，每一轮都将当前最大的数推到最后 
  { 
    for (u8 j=LSB;j<MSB+1-i;j++) // 9 - i，意思是每当经过一轮冒泡后，就减少一次比较 
      if (data[j] > data[j+1]) 
      { 
        temp = data[j]; 
        data[j] = data[j+1]; 
        data[j+1] = temp; 
      } 
  }   
}
