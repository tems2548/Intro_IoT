// กำหนด pin ที่เริ่มต่อ ex. pin 8 => pin 13
#define pin_start 8
#define pin_end 13

void setup() {
//กำหนด pin เป็น mode OUTPUT
  for(int i = pin_start;i <= pin_end;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
//เปิดไปตั้งเเต่ 8 => 13
  for(int j = pin_start;j <= pin_end ;j++){
    digitalWrite(j,1);
    delay(100);
    digitalWrite(j,0);
  }
//เปิดไปตั้งเเต่ 13 => 8
  for(int j = pin_end;j >= pin_start ;j--){
    digitalWrite(j,1);
    delay(100);
    digitalWrite(j,0);
  }
}
