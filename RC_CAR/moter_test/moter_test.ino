#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

void setup()
{
// 방향 제어핀 출력 설정
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
}
void loop()
{
// 모터 A,B 정방향
digitalWrite(IN1, HIGH);   // 모터A 설정
digitalWrite(IN2, LOW);
analogWrite(ENA, Motor_speed);  
digitalWrite(IN3, HIGH);  // 모터B설정
digitalWrite(IN4, LOW);
analogWrite(ENB, Motor_speed);
delay(3000);              // 3초동안 정방향 회전
// 모터A,B 역방향
digitalWrite(IN1, LOW);  // 모터A설정
digitalWrite(IN2, HIGH);  
analogWrite(ENA, Motor_speed);
digitalWrite(IN3, LOW); // 모터B설정
digitalWrite(IN4, HIGH);
analogWrite(ENB, Motor_speed);
delay(3000);       // 3초동안 역방향 회전
}
