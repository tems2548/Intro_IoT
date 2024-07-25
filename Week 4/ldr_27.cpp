int temp1 = 0;
void setup() {
  Serial.begin(115200);
    pinMode(7,OUTPUT);
}
void loop() {
  temp1 = analogRead(A1);
  if(temp1 < 750){
    digitalWrite(7,1);
  }else{
    digitalWrite(7,0);
  }
}