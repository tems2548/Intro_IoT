int temp = 0;
void setup() {
  Serial.begin(115200);
}
void loop() {
  temp = analogRead(A0);
  delay(100);
  Serial.println(temp);
}
