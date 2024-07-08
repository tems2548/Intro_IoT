#define led_1 9
#define led_2 10
#define led_3 11
int temp = 0;
void setup() {
  Serial.begin(115200);
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
}
void loop() {
  temp = analogRead(A0);
  delay(100);
  Serial.println(temp);
  if(temp > 784){
    digitalWrite(led_1,0);
    digitalWrite(led_2,0);
    digitalWrite(led_3,0);
  }else if(temp > 716){
    digitalWrite(led_1,1);
    digitalWrite(led_2,0);
    digitalWrite(led_3,0);
  }else if(temp > 650){
    digitalWrite(led_1,0);
    digitalWrite(led_2,1);
    digitalWrite(led_3,0);
  }else if(temp > 500){
    digitalWrite(led_1,0);
    digitalWrite(led_2,0);
    digitalWrite(led_3,1);
  }
}