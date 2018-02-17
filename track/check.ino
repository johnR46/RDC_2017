void check(){ 
  Serial.print(digitalRead(D1));
  Serial.print("\t");
  Serial.print(digitalRead(D2));
  Serial.print("\t");
  Serial.println(digitalRead(D3));
}
