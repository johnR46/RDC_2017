int pin = 53;
void setup() {
pinMode(pin,OUTPUT); 

}

void loop() {
 
 for(int i=500;i>0;i--){
   digitalWrite(pin,HIGH);
  delay(i);
  digitalWrite(pin,LOW);
  delay(i);
    }
 
}



