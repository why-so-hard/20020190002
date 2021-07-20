// C++ code
//假期开源硬件实战课程——大作业
#include<MsTimer2.h>
#define a1 4
#define a2 5
#define a3 6
#define a4 7
#define locks 8
#define lockg 9
#define buttonInterrupt 2

int tickg=0;//个位
int ticks=0;//十位
void buttonchange()
{
  if ( digitalRead(buttonInterrupt) == 1 )
  {
    ticks=0;
  	tickg=0;
  	Serial.println("ok");
  }
  //按下按钮后清零
}

void timedo()
{
  Serial.print(ticks);
  Serial.println(tickg);
  //打印当前数字
  digitalWrite(locks,LOW);
  digitalWrite(lockg,HIGH);
  //开启十位销锁
  digitalWrite(a1,(ticks&0x1));
  digitalWrite(a2,((ticks>>1)&0x1));
  digitalWrite(a3,((ticks>>2)&0x1));
  digitalWrite(a4,((ticks>>3)&0x1));
  //显示
  
  digitalWrite(lockg,LOW);
  digitalWrite(locks,HIGH);
  //开启个位销锁
  digitalWrite(a1,(tickg&0x1));
  digitalWrite(a2,((tickg>>1)&0x1));
  digitalWrite(a3,((tickg>>2)&0x1));
  digitalWrite(a4,((tickg>>3)&0x1));
  //显示

  tickg++;
  if(tickg>9)
  {
    ticks++;
    tickg=0;
    if(ticks>9)
    {
      ticks=0;
    }
  }
  //到达99后归零  
}

void setup()
{
  pinMode(a1, OUTPUT);//CD4511 A1
  pinMode(a2, OUTPUT);//A2
  pinMode(a3, OUTPUT);//A3
  pinMode(a4, OUTPUT);//A4
  pinMode(locks, OUTPUT);//十位数锁销
  pinMode(lockg, OUTPUT);//个位数锁销
  pinMode(2,INPUT);//按钮判断
  Serial.begin(9600);
  MsTimer2::set(1000, timedo); //设置中断，1s为间隔
  MsTimer2::start(); //开始计时
  attachInterrupt( digitalPinToInterrupt(buttonInterrupt),buttonchange, RISING);//监视引脚变化以实现通过按钮清零
}

void loop()
{
}