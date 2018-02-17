byte D1 = 23;
byte D2 = 25;
byte D3 = 27;
#define BRAKEVCC 0
#define CW   1
#define CCW  2
#define BRAKEGND 3
#define CS_THRESHOLD 2000
#define StatePin 13

int inApin[2] = {7, 4};
int inBpin[2] = {8, 9};
int pwmpin[2] = {5, 6};
int cspin[2] = {2, 3};
int enpin[2] = {0, 1};
void setup() {
  // put your setup code here, to run once:
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  Serial.begin(9600);
  Initial_MotorShield();

}
// 0 0 0  = หลุดเส้น
// 0 0 1  =  เอียงขวา
// 0 1 0  =  เดินตรง
// 0 1 1  = เอียงขวา && เลี้ยวขวา
// 1 0 0  = เอียงซ้าย
// 1 0 1 =  หลุดเส้น
// 1 1 0  = เอียงซ้าย && เลี้ยวซ้าย
void loop() {
  //  Serial.print(digitalRead(D1));
  //  Serial.print("\t");
  //  Serial.print(digitalRead(D2));
  //  Serial.print("\t");
  //  Serial.println(digitalRead(D3));
  int Speed = 255;
  int count = 0;
  if (digitalRead(D1) == 0 && digitalRead(D2) == 0 && digitalRead(D3) == 0) {
    //Serial.prin tln("STOP");
    Right(0, 50);
  }
  else if (digitalRead(D1) == 0 && digitalRead(D2) == 0 && digitalRead(D3) == 1) {
    Right (0, 100);
  }
  else if (digitalRead(D1) == 0 && digitalRead(D2) == 1 && digitalRead(D3) == 0) {
    Go(0, 100);
  }
  else if (digitalRead(D1) == 0 && digitalRead(D2) == 1 && digitalRead(D3) == 1) {
    Right(0, 100);
  }
  else if (digitalRead(D1) == 1 && digitalRead(D2) == 0 && digitalRead(D3) == 0) {
    Left(0, 100);
  }
  else if (digitalRead(D1) == 1 && digitalRead(D2) == 0 && digitalRead(D3) == 1) {
    Back(0,50);
  }
  else if (digitalRead(D1) == 1 && digitalRead(D2) == 1 && digitalRead(D3) == 0) {
    Left(0, 100);
  }



}
