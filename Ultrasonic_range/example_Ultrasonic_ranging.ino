/*[mw_shl_code=c,true]
//功能：利用SR04超声波传感器进行测距，并用串口显示测出的距离值
*/

// 设定SR04连接的Arduino引脚
const int TrigPin = 4;
const int EchoPin = 2;

float distance;
unsigned long time;
unsigned long dm;
int pos = 0;
const int NumOfSample = 5;
double Samples[NumOfSample];

//计算连续N个值，返回平均值和标准差
double mean(double a[], int n, double *ps)
{
  double sum = 0.0, aver = 0.0, e = 0.0;

  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  aver = sum / n;

  if (ps != 0) {
    for (int i = 0; i < n; i++) {
      e += (a[i] - aver) * (a[i] - aver);
    }
    e /= n - 1;
    *ps = sqrt(e);
  }

  return aver;
}


void setup()
{
  // 初始化串口通信及连接SR04的引脚
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  // Trig设置为输出状态
  pinMode(EchoPin, INPUT);
  // 要检测引脚上输入的脉冲宽度，需要先设置为输入状态
  Serial.println("Ultrasonic sensor:");
}
void loop()
{
  // 产生一个10us的高脉冲去触发TrigPin
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  // 检测脉冲宽度，并计算出距离
  distance = pulseIn(EchoPin, HIGH) * 0.017;

  if (pos < NumOfSample) {
    // 连续读取多个返回值
    Samples[pos] = distance;
    pos++;
    delay(50);
  }
  else {
    // 多个返回值已经读取完毕，计算结果是否符合要求
    pos = 0;
    double s = 0;
    double m = mean(Samples, NumOfSample, &s);
    dm=long(m*100);
//#if 0
//    // 调试时候打开
//    Serial.print("The mean is ");
//    Serial.print(m);
//    Serial.print(", the standard deviation: ");
//    Serial.print(s);
//    Serial.println();
//#endif

    if (s < 0.2) {
      // 标准差小于0.2，就认为比较稳定了，可以将均值作为最终结果
      // 实际应用中，可以调整这个参数值，达到理想的结果
      Serial.print("Reliable distance: ");
      Serial.print(m);
      Serial.println();
      Serial.print(dm);
      Serial.println();
    }
    delay(1000);
  }
}
//[/mw_shl_code]
