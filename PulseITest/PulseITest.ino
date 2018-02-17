byte PWM_L = 5;
byte ML1 = 8;
byte ML2 = 7;
byte PWM_R = 6;
byte MR1 = 4;
byte MR2 = 9;
#define PWML 255
#define PWMR 255
int ch1 = 53;
int ch2 = 51;
int ch3 = 49;
int ch4 = 47;
const int MAXCH1 = 1950;
const int MidCH1 = 1500;
const int MinCH1 = 1000;

const int MAXCH2 = 1950;
const int MidCH2 = 1500;
const int MinCH2 = 1000;

const int Error  = 100;
//int MAXCH3 = 1080;
//int MidCH3 = 1500;
//int MinCH3 = 1900;
//int MAXCH4 = 1900;
//int MidCH4 = 1495;
//int MinCH4 = 1080;
void setup() {
  pinMode(ML1, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(PWM_L, OUTPUT);
    pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
//  pinMode(ch3, INPUT);
//  pinMode(ch4, INPUT);
 pinMode(A0,OUTPUT);
 pinMode(12,OUTPUT);
   Serial.begin(9600);
}
void loop() {
  int CH1 =  pulseIn(ch1, HIGH);
  int CH2 =  pulseIn(ch2, HIGH);
  int CH3 =  pulseIn(ch3, HIGH);
 int CH4 =  pulseIn(ch4, HIGH);
  Serial.print(CH1);
  Serial.print("\t");
  Serial.print(CH2);
  Serial.print("\t");
  Serial.print(CH3);
  Serial.print("\t");
Serial.println(CH4);
   
// if((CH1<=MidCH1+Error) && (CH1>=MidCH1-Error)&&(CH2<=MidCH2+Error) && (CH2>=MidCH2-Error)){
//  //Serial.println("STOP");
//   Stop();
// }else if(CH1>MidCH1+Error&&CH1<MAXCH1){
// Serial.println("RIGHT");
//  
// }else if(CH1<MidCH1-Error&&CH1>MinCH1){
// Serial.println("Left");
//   
// }else if(CH2>MidCH2+Error&&CH2<MAXCH2){
// //Serial.println("Backward");
//  backward();
//  
// }else if(CH2<MidCH2-Error&&CH2>MinCH2){
//   forward();
// //Serial.println("Forward");
//   
// }
}
void forward() {
  analogWrite(PWM_R, PWMR);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
  analogWrite(PWM_L, PWML);
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
}
void backward() {
  analogWrite(PWM_R, PWMR);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, HIGH);
  analogWrite(PWM_L, PWML);
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, HIGH);
}
void Stop() {
  analogWrite(PWM_R, 0);
  digitalWrite(MR1, LOW);
  digitalWrite(MR2, 0);
  analogWrite(PWM_L, 0);
  digitalWrite(ML1, LOW);
  digitalWrite(ML2, 0);
}


