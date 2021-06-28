#define LED1 6
#define LED2 7
#define LED3 3
#define LED4 4
#define BUZZ 5
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 12
#define ENB 13

int Motor_speedL;    // 좌측모터 속도   0 ~ 255
int Motor_speedR;    // 우측모터 속도   0 ~ 255

char state;       // 블루투스 신호 상태 저장용 변수
int stateD = 0;

char str;

void setup()  {
  Serial.begin(38400);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(BUZZ,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(1000);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);

  
}

void loop()  {
 
//--- 수신되는 블루투스 신호 체크 후 루틴 ---
  if (Serial.available()){
    str = Serial.read();


    if (str=='S'){
      Motor_speedL = 255;
      Motor_speedR = 255;
    }else if (str=='l'){
      Motor_speedL = 200;
      Motor_speedR = 255;
    }else if (str=='r'){
      Motor_speedL = 255;
      Motor_speedR = 200;
    }else if (str=='L'){
      Motor_speedL = 120;
      Motor_speedR = 255;
    }else if (str=='R'){
      Motor_speedL = 255;
      Motor_speedR = 120;
    }
    analogWrite(ENA, Motor_speedL);
    analogWrite(ENB, Motor_speedR);
    
    if (str=='A'){              // 전진
      digitalWrite(IN1, HIGH);  // 모터A 설정
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);  // 모터B설정
      digitalWrite(IN4, HIGH);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
    }else if (str=='B'){        // 멈춤
      digitalWrite(IN1, LOW);   // 모터A 설정
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);   // 모터B설정
      digitalWrite(IN4, LOW);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
    }else if (str=='C'){        // 후진
      digitalWrite(IN1, LOW);   // 모터A설정
      digitalWrite(IN2, HIGH);  
      digitalWrite(IN3, HIGH);   // 모터B설정
      digitalWrite(IN4, LOW);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
    }else if (str=='D'){        //경적
      tone(BUZZ, 349, 600);
    }
  }
}
