#include <IoTe.h>
int number = 0;
void setup() {
   pinMode(12,OUTPUT);
  // step_motor_begin(A5,12,3,A4);
  Segment_begin(11,A1,A2,2,4,7,8,13,5,6,9,10);
  Serial.begin(115200);
}

void loop() { 

//  drive(2,1.4,true);

int per = analogRead(A5);
if(per < 400){
  delay(300);
  number++;
}
Serial.println(per);
displaysegment(number,0,1);
if(number == 6){ 
  for(int count = 0;count < 3;count++){
    digitalWrite(12,1);
    delay(500);
    digitalWrite(12,0);
    delay(500);
  }
  number = 0;

}
digitalWrite(12,0);
}