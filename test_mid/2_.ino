#include <IoTe.h>
float Vin = 5.0;
float Vout;
float Rref = 10000.0;
float sensor_value;

void setup() {
 Serial.begin(9600);
}

void loop() {
  sensor_value = analogRead(A4);
  Vout = (Vin * sensor_value)/1023.0;
  float R = Rref*sensor_value*(1.0/(1023.0-sensor_value));
  delay(500);
  Serial.print("R : ");
  Serial.println(R);
}
