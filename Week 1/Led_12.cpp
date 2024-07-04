#define led_1 8
#define led_2 9

void setup() {
  Serial.begin(9600);
  pinMode(led_1,8);
  pinMode(led_2,9);
}

void loop() {
  // led 2 period is 0.5 second (2 Hz)
  digitalWrite(led_2,1);
  delay(250);
  digitalWrite(led_2,0);
  delay(250);

  // led 1 period is 1 second (1 Hz)
  digitalWrite(led_1,1);
  delay(250);
  digitalWrite(led_1,0);
  delay(250);
}
