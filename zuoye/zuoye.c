// C++ code
//���ڿ�ԴӲ��ʵս�γ̡�������ҵ
#include<MsTimer2.h>
#define a1 4
#define a2 5
#define a3 6
#define a4 7
#define locks 8
#define lockg 9
#define buttonInterrupt 2

int tickg=0;//��λ
int ticks=0;//ʮλ
void buttonchange()
{
  if ( digitalRead(buttonInterrupt) == 1 )
  {
    ticks=0;
  	tickg=0;
  	Serial.println("ok");
  }
  //���°�ť������
}

void timedo()
{
  Serial.print(ticks);
  Serial.println(tickg);
  //��ӡ��ǰ����
  digitalWrite(locks,LOW);
  digitalWrite(lockg,HIGH);
  //����ʮλ����
  digitalWrite(a1,(ticks&0x1));
  digitalWrite(a2,((ticks>>1)&0x1));
  digitalWrite(a3,((ticks>>2)&0x1));
  digitalWrite(a4,((ticks>>3)&0x1));
  //��ʾ
  
  digitalWrite(lockg,LOW);
  digitalWrite(locks,HIGH);
  //������λ����
  digitalWrite(a1,(tickg&0x1));
  digitalWrite(a2,((tickg>>1)&0x1));
  digitalWrite(a3,((tickg>>2)&0x1));
  digitalWrite(a4,((tickg>>3)&0x1));
  //��ʾ

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
  //����99�����  
}

void setup()
{
  pinMode(a1, OUTPUT);//CD4511 A1
  pinMode(a2, OUTPUT);//A2
  pinMode(a3, OUTPUT);//A3
  pinMode(a4, OUTPUT);//A4
  pinMode(locks, OUTPUT);//ʮλ������
  pinMode(lockg, OUTPUT);//��λ������
  pinMode(2,INPUT);//��ť�ж�
  Serial.begin(9600);
  MsTimer2::set(1000, timedo); //�����жϣ�1sΪ���
  MsTimer2::start(); //��ʼ��ʱ
  attachInterrupt( digitalPinToInterrupt(buttonInterrupt),buttonchange, RISING);//�������ű仯��ʵ��ͨ����ť����
}

void loop()
{
}