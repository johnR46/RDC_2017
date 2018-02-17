byte D1 = 31;
byte D2 = 33;
byte D3 = 35;
void setup() {
  // put your setup code here, to run once:
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(digitalRead(D1));
Serial.print("\t");
Serial.print(digitalRead(D2));
Serial.print("\t");
Serial.println(digitalRead(D3));
delay(500);

  // โดนเส้นดำ  = 1  เส้นขาว  = 0
 //  0 0 0  หลุดเส้น
 //  0 0 1  เลี้ยวซ้าย
 //  0 1 0  เดินตรง
 //  0 1 1  เจอตัว T เลี้ยวขวา
 //  1 0 0
 //  1 0 1
 //  1 1 0
 //  1 1 1 
int Left = digitalRead(D1);
int Mid = digitalRead(D2);
int Right = digitalRead(D3);
if(Left == 0 && Mid == 1&& Right == 0){
  Serial.println("Forward");
} else if(Left == 1&&Mid == 0&& Right == 0){
    Serial.println("Turn Left");
  
} else if(Left == 1&&Mid == 0&& Right == 0){
  
} else if(Left == 1&&Mid == 0&& Right == 0)

}
