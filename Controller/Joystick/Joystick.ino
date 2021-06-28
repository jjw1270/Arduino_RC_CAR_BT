const int buttonPinA = 2;
const int buttonPinB = 3;
const int buttonPinC = 4;
const int buttonPinD = 5;
const int buttonPinE = 6;
const int buttonPinF = 7;
const int buttonPinK = 8;


void setup() {
  Serial.begin(38400);
  
  pinMode(buttonPinA, INPUT_PULLUP);
  pinMode(buttonPinB, INPUT_PULLUP);
  pinMode(buttonPinC, INPUT_PULLUP);
  pinMode(buttonPinD, INPUT_PULLUP);
  pinMode(buttonPinK, INPUT_PULLUP);
  //E,F,K
}

void loop() {

  //int X = map(analogRead(1), 0, 1023, 0, 100);
  int Y = map(analogRead(0), 0, 1023, 0, 100);
  char Yshift = 'S';
  char button_state = '_';
  int buttonValueA = digitalRead(buttonPinA);
  int buttonValueB = digitalRead(buttonPinB);
  int buttonValueC = digitalRead(buttonPinC);
  int buttonValueD = digitalRead(buttonPinD);
  int buttonValueK = digitalRead(buttonPinK);
  
  if (buttonValueA == LOW) {
    button_state = 'A';
  }else if (buttonValueB == LOW) {
    button_state = 'B';
  }else if (buttonValueC == LOW) {
    button_state = 'C';
  }else if (buttonValueD == LOW) {
    button_state = 'D';
  }
  
  if (buttonValueK == LOW) {
    button_state = 'K';
  }

  if (Y>46 and Y<51){
    Yshift = 'S';
  }else if (Y>=51 and Y<94) {
    Yshift = 'r';
  }else if (Y>94) {
    Yshift = 'R';
  }else if (Y>6 and Y<=46) {
    Yshift = 'l';
  }else if (Y<=6) {
    Yshift = 'L';
  }

  Serial.print(Yshift);
  Serial.print(",");
  Serial.println(button_state);
  
  delay(500);
}
