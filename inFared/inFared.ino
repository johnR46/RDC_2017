byte D1 = A0;
byte D2 = A1;
byte D3 = A2;
byte PWM_L = 5;
byte ML1 = 8;
byte ML2 = 7;
byte PWM_R = 6;
byte MR1 = 4;
byte MR2 = 9;
#define PWML 255
#define PWMR 255
void setup() {
  pinMode(ML1, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(PWM_L, OUTPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  Serial.begin(9600);
}

void forward() {
  analogWrite(PWM_R, PWMR);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
  analogWrite(PWM_L, PWML);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
}
void Left() { // ซ้าย

}
void Right() { // ขวา

}

void loop() {
  if (!(digitalRead(D1) == 0 && digitalRead(D2) == 0 && digitalRead(D3) == 0)) {

  }
  else if (!(digitalRead(D1) == 0 && digitalRead(D2) == 0 && digitalRead(D3) == 1)) {

  }
  else if (!(digitalRead(D1) == 0 && digitalRead(D2) == 1 && digitalRead(D3) == 0)) {

  }
  else if (!(digitalRead(D1) == 0 && digitalRead(D2) == 1 && digitalRead(D3) == 1)) {

  }
  else if (!(digitalRead(D1) == 1 && digitalRead(D2) == 0 && digitalRead(D3) == 0)) {

  }
  else if (!(digitalRead(D1) == 1 && digitalRead(D2) == 0 && digitalRead(D3) == 1)) {

  }
  else if (!(digitalRead(D1) == 1 && digitalRead(D2) == 1 && digitalRead(D3) == 0)) {

  }
  else if (!(digitalRead(D1) == 1 && digitalRead(D2) == 1 && digitalRead(D3) == 1)) {

  }

}

