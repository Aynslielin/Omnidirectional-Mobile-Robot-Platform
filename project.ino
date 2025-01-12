int ENA1 = 2;
int IN1 = 3;
int IN2 = 4;
int PWMspeed1 = 90;
//左後輪--1
int IN3 = 6;
int IN4 = 5;
int ENB1 = 7;
int PWMspeed2 = 145;
//右後輪--2


int ENA2 = 8;
int IN5 = 9;
int IN6 = 10;
int PWMspeed3 = 150;
//左前輪--3

int IN7 = 12;
int IN8 = 11;
int ENB2 = 13;
int PWMspeed4 = 120;
//右前輪--4
// String incomingString = "";
char incomingChar;

const int trig = A0;
const int echo = A1;
const int inter_time = 1000;
int time = 0;

void setup() {
Serial.begin(9600); //設定監控視窗鮑率
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(ENA1, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(ENB1, OUTPUT);

pinMode(IN5, OUTPUT);
pinMode(IN6, OUTPUT);
pinMode(ENA2, OUTPUT);
pinMode(IN7, OUTPUT);
pinMode(IN8, OUTPUT);
pinMode(ENB2, OUTPUT);

pinMode(echo, INPUT);
pinMode(trig, OUTPUT);


}

void loop() 
{ 
  // FRONT();
  if(Serial.available())//當輸入任意指令時
  {
  Distance();//啟動超聲波測距

  }
  // L();
}

/////////////////////////////
void Distance()
{
  float duration, distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/29;
  // Serial.print("Data:");
  // Serial.print(time/1000);
  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println("cm");
  // time = time + inter_time;
  // delay(inter_time);
  if(distance >= 20)//與障礙物距離20cm以上時
  {
    FRONT();//向前行
    delay(10);
  }else //與障礙物距離小於20cm時
  {
    STOP();//停下
    delay(500);
    L();//向左平移
    delay(2800);
  }
}

void FRONT1()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA1, PWMspeed1);
}//1前

void FRONT2()
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB1, PWMspeed2);
}//2前

void FRONT3()
{
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENA2, PWMspeed3);
}//3前

void FRONT4()
{
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(ENB2, PWMspeed4);
}//4前

void BACK1()
{
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  analogWrite(ENA1, PWMspeed1);
}//1後

void BACK2()
{
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  analogWrite(ENB1, PWMspeed2);
}//2後

void BACK3()
{
  digitalWrite(IN6, LOW);
  digitalWrite(IN5, HIGH);
  analogWrite(ENA2, PWMspeed3);
}//3後

void BACK4()
{
  digitalWrite(IN8, LOW);
  digitalWrite(IN7, HIGH);
  analogWrite(ENB2, PWMspeed4);
}//4後

void STOP1()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}//1停

void STOP2()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}//2停

void STOP3()
{
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
}//3停

void STOP4()
{
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
}//4停

///////////////////////////////////////////////////////////

void FRONT()//往前移動
{
  FRONT1();
  FRONT2();
  FRONT3();
  FRONT4();
}

void BACK()//往後移動
{
  BACK1();
  BACK2();
  BACK3();
  BACK4();
}

void LF()//左前移動
{
  FRONT1();
  STOP2();
  STOP3();
  FRONT4();
}

void RF()//右前移動
{
  STOP1();
  FRONT2();
  FRONT3();
  STOP4();
}

void L()//往左平移
{
  FRONT1();
  BACK2();
  BACK3();
  FRONT4();
}

void R()//往右平移
{
  BACK1();
  FRONT2();
  FRONT3();
  BACK4();
}

void LB()//左後移動
{
  STOP1();
  BACK2();
  BACK3();
  STOP4();
}

void RB()//右後移動
{
  BACK1();
  STOP2();
  STOP3();
  BACK4();
}

void STOP()//停止
{
  STOP1();
  STOP2();
  STOP3();
  STOP4();
}

void Lround()//逆時針自轉
{
  BACK1();
  FRONT2();
  BACK3();
  FRONT4();
}

void Rround()//順時針自轉
{
  FRONT1();
  BACK2();
  FRONT3();
  BACK4();
}
