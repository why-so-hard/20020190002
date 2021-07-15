// C++ code
//假期开源硬件实战课程作业——流水灯代码
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  int i;
  for(i=9;i<=13;i++)
  {
    digitalWrite(i, HIGH);
    delay(1000); 
    digitalWrite(i, LOW);
    delay(1000); 
  }
}