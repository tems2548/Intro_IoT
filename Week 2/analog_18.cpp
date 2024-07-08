#define led_1 9
#define led_2 10
int temp = 0;
void setup() {
  Serial.begin(115200);
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
}
void loop() {
  temp = analogRead(A0);
  delay(100);
  Serial.println(temp);
  if(temp < 500){
    digitalWrite(led_1,1);
    digitalWrite(led_2,0);
  }else{
    digitalWrite(led_1,0);
    digitalWrite(led_2,1);
  }
}
