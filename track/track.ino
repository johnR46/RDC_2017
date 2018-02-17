#define BRAKEVCC 0
#define CW   1
#define CCW  2
#define BRAKEGND 3
#define CS_THRESHOLD 100
#define D3 31
#define D2 33
#define D1 35

// เจอ ดำ  = 0  ขาว  = 1
byte inApin[2] = {7, 4};
byte inBpin[2] = {8, 9};
byte pwmpin[2] = {5, 6};
byte cspin[2] = {2, 3};
byte enpin[2] = {0, 1};
byte statpin = 13;
void setup() {
  Serial.begin(9600);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(statpin, OUTPUT);
  for (int i = 0; i < 2; i++)
  {
    pinMode(inApin[i], OUTPUT);
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
}

void loop() {
  bool l = digitalRead(D1);
  bool m = digitalRead(D2);
  bool r = digitalRead(D3); // ดำ 0 ขาว  1
  check();
     
  if (l == 0 && m == 1 && r == 0) { // 0 1 0
    motorGo(0, CW, 512);    // cw = หน้า 
    motorGo(1, CW, 512);    // ccw = หลัง
  }
  else if (l == 1 && m == 1 && r == 0) {
    motorGo(0, CCW, 512);    // ซ้าย
    motorGo(1, CW, 512);
  }
  else if (l == 1 && m == 0 && r == 0) {
    motorGo(0, CCW, 256);   // ซ้าย
    motorGo(1, CW, 256);
  }
  else if (l == 0 && m == 1 && r == 1) {
    motorGo(0, CW, 512);  // ขวา
    motorGo(1, CCW, 512);
  }
  else if (l == 0 && m == 0 && r == 1) {
    motorGo(0, CW, 256);   // ขวา
    motorGo(1, CCW, 256);
  }
  else if (l == 1 && m == 1 && r == 1) {
    motorGo(0, CW, 512); // หน้า
    motorGo(1, CW, 512);
  }
//    else if (l == 0 && m == 0 && r == 0) {
//    motorGo(0, CW, 0);
//    motorGo(1, CW, 0);
//  }

  if ((analogRead(cspin[0]) < CS_THRESHOLD) && (analogRead(cspin[1]) < CS_THRESHOLD))
    digitalWrite(statpin, HIGH);
}
