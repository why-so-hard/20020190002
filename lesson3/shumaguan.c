// C++ code
//���ڿ�ԴӲ��ʵս�γ���ҵ��������ܴ���

int Pin[7]={13,12,11,10,9,8,7};
//����
unsigned char pincon[10][7]=
{
  	{0,1,1,1,1,1,1},//0
    {0,0,0,1,0,0,1},//1
    {1,0,1,1,1,1,0},//2
    {1,0,1,1,0,1,1},//3
    {1,1,0,1,0,0,1},//4
    {1,1,1,0,0,1,1},//5
    {1,1,1,0,1,1,1},//6
    {0,0,1,1,0,0,1},//7
    {1,1,1,1,1,1,1},//8
    {1,1,1,1,0,1,1}//9
};
//ÿ�����ֶ�Ӧ�ĸ�����״̬
void setup()
{
  pinMode(13, OUTPUT);//��Ӧ�����g����
  pinMode(12, OUTPUT);//f
  pinMode(11, OUTPUT);//a
  pinMode(10, OUTPUT);//b
  pinMode(9, OUTPUT);//e
  pinMode(8, OUTPUT);//d
  pinMode(7, OUTPUT);//c
  Serial.begin(9600);
}

void loop()
{
  int i;
  int num=0;
  num=int(Serial.read())-48;
  //��ȡ���ڼ��������͵����ݲ�����Ϊint����
  if(num>=0&&num<=9)
  {
    for(i=0;i<9;i++)
    {
      digitalWrite(Pin[i],pincon[num][i]);
    }
    //��ʾ����
  }
}