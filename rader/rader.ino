#include<Servo.h>
Servo myservo;
int pos = 0;
int angle = 0;

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  //기본 설정을 해 줍니다.
}

void loop() {
  for (pos = 0; pos <= 90; pos += 1)
  {
    myservo.write(pos);
    delay(10);
    ultraSonicAll();
    angle=angle+1;
    //모터 회전을 설정합니다.
  }
  for (pos = 90; pos >= 0; pos -= 1)
  {
    myservo.write(pos);
    delay(10);
    ultraSonicAll();
    angle=angle-1;
    //모터 회전을 설정합니다.
  }
}

void ultraSonicAll() {
  Serial.print(ultraSonic(2, 5));
  Serial.print(",");
  Serial.print(ultraSonic(10, 8));
  Serial.print(",");
  Serial.print(ultraSonic(11, 7));
  Serial.print(",");
  Serial.print(ultraSonic(3, 6));
  Serial.print(",");
  Serial.print(-angle);
  Serial.print(".");
  //값을 화면에 출력합니다.
}


int ultraSonic(int trigPin, int echoPin) {
  unsigned long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH,6000);
  int distance  = duration * 17 / 1000;
  if(distance >= 40 || distance == 0) {
    distance = 40;
}
  return distance;
 //초음파 센서값을 측정합니다.
}

[출처] 초음파 레이더 프로젝트/아두이노/프로세싱|작성자 오픈랩
