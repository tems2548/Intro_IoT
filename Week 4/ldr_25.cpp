int temp = 0;
int temp1 = 0;
void RGB(byte R,byte G,byte B){
  digitalWrite(8,R);
  digitalWrite(9,G);
  digitalWrite(10,B);
}
void setup() {
  Serial.begin(115200);
  for(int i = 7;i<=10;i++){
    pinMode(i,OUTPUT);
  }
}
void loop() {
  temp = analogRead(A0);
  delay(100);
  Serial.println(temp1);
  if(temp >= 700){
  RGB(1,0,0);
  }else if(temp >= 600){
  RGB(0,1,0);
  }else if(temp >= 500){
  RGB(0,0,1);
  }else if(temp >= 400){
  RGB(1,1,0);
  }else if(temp >= 300){
  RGB(1,0,1);
  }else if(temp >= 200){
  RGB(0,1,1);
  }else if(temp >= 100){
  RGB(1,1,1);
  }
}