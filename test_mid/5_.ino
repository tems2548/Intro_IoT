#include <IoTe.h>
int count = 0;
bool once = false;
void setup() {
  step_motor_begin(7,A1,6,A2);
  Serial.begin(9600);
}

void loop() { 
 int val = analogRead(A5);
 Serial.println(val);
 if(val < 100){
  if(once == false){
    for(int i = 0;i < 2;i++){
      for(int i = 0;i < 512;i++){
      drive(2,1.4,true);
    }
   }
  }
  once = true;
  count = 0;
 }else{
    once = false;
    count++;
    if(count <= 3){
     for(int i = 0;i < 512;i++){
      drive(2,1.4,false);
    }
  }
 }
 
}