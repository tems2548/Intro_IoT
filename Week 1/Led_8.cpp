// กำหนด pin ที่เริ่มต่อ ex. pin 8
#define led 8

void setup(){

  //กำหนด led เป็น mode OUTPUT
  pinMode(led,OUTPUT);

  //เปิด Serial monitor
  Serial.begin(9600);

}

void loop() {
  /*
    เป็นการหา Hz โดยใช้ Serial monitor ในการช่วยหาโดยกดไปที่ Serial monitor เเล้วเลือก beud rate 9600
    เเล้วดูการวิ่งของเลข
  */
  for(int j = 200;j <= 500 ;j = j+2){
    digitalWrite(j,1);
    delay(500-j);
    digitalWrite(j,0);
    delay(1500-(j*3));
  }
}
