#include <IRremote.h>
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#define RECV 12

IRrecv irrecv(RECV);
decode_results results;
ArduinoLEDMatrix matrix;

int segmentA = A4;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;

int avg[50];
int HEX_num[8];

int bt = 12;
int num;
int ir;
int wait_val;
int dim;
int active_d1 = 5;
int active_d2 = 6;
int active_d3 = 9;
int active_d4 = 10;
int i = 0;

int read_;
int delay_disp;
float R_thermistor;
float temperature;
float C_temp;
float avg_temp;

unsigned long previous_time = 0;

void Active_pin(int act){
   switch(act){
    case 1:
      digitalWrite(active_d1,1);
     break;
    case 2:
      digitalWrite(active_d2,1);
     break;
    case 3:
      digitalWrite(active_d3,1);
     break;
    case 4:
      digitalWrite(active_d4,1);
    break;
   }
};

void diactivate_pin(){
    digitalWrite(active_d1,0);
    digitalWrite(active_d2,0);
    digitalWrite(active_d3,0);
    digitalWrite(active_d4,0);
};

void segment(byte A ,byte B,byte C,byte D,byte E,byte F,byte G,byte dp = 0){
  digitalWrite(segmentA,A);
  digitalWrite(segmentB,B);
  digitalWrite(segmentC,C);
  digitalWrite(segmentD,D);
  digitalWrite(segmentE,E);
  digitalWrite(segmentF,F);
  digitalWrite(segmentG,G);
  digitalWrite(segmentDP,dp);
}
void displaysegment(int digit,int dp = 0){
    switch(digit){
    case 0:
     segment(1,1,1,1,1,1,0,dp);
    break;
    case 1:
     segment(0,1,1,0,0,0,0,dp);
     break;
    case 2:
     segment(1,1,0,1,1,0,1,dp);
     break;
    case 3:
     segment(1,1,1,1,0,0,1,dp);
     break;
    case 4:
     segment(0,1,1,0,0,1,1,dp);
    break;
    case 5:
     segment(1,0,1,1,0,1,1,dp);
    break;
    case 6:
     segment(1,0,1,1,1,1,1,dp);
    break;
    case 7:
     segment(1,1,1,0,0,0,0,dp);
    break;
    case 8:
     segment(1,1,1,1,1,1,1,dp);
    break;
    case 9:
     segment(1,1,1,1,0,1,1,dp);
    break;  
    // A B C D E F
    case 10:
    segment(1,1,1,0,1,1,1,dp);
    break;
    case 11:
    segment(1,1,1,1,1,1,1,dp);
    break;
    case 12:
    segment(1,0,0,1,1,1,0,dp);
    break;
    case 13:
    segment(1,1,1,1,1,1,0,dp);
    break;
    case 14:
    segment(1,0,0,1,1,1,1,dp);
    break;
    case 15:
    segment(1,0,0,0,1,1,1,dp);
    break;
  }
}
void dis_num(int digit1,int digit2,int digit3,int digit4,int act_dp = 0,int dp_digit = 0){
  num = 4;

   for(num;num >= 0;num--){
      Active_pin(num);
     switch(num){
      case 4:
         displaysegment(digit1,0);
         if(act_dp == 1 && dp_digit == 4){
           displaysegment(digit1,1);
         }
      break;
      case 3:
         displaysegment(digit2,0);
        if(act_dp == 1 && dp_digit == 2){
           displaysegment(digit2,1);
         }
      break;
      case 2:
         displaysegment(digit3,0);
         if(act_dp == 1 && dp_digit == 3){
           displaysegment(digit3,1);
         }
      break;
      case 1:
         displaysegment(digit4,0);
         if(act_dp == 1 && dp_digit == 4){
           displaysegment(digit4,1);
         }
      break;
     }
      delay(2);
      diactivate_pin();
    }
}

void ID_num(int delay_display ,int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8){
  for(int count = 0;count <= delay_display;count++){
    dis_num(10,10,10,n1);
  }
  for(int count = 0;count <= delay_display;count++){
    dis_num(10,10,n1,n2);
  }
  for(int count = 0;count <= delay_display;count++){
    dis_num(10,n1,n2,n3);
  }
    for(int count = 0;count <= delay_display;count++){
    dis_num(n1,n2,n3,n4);
  }
  for(int count = 0;count <= delay_display;count++){
    dis_num(n2,n3,n4,n5);
  }
    for(int count = 0;count <= delay_display;count++){
    dis_num(n3,n4,n5,n6);
  }
     for(int count = 0;count <= delay_display;count++){
    dis_num(n4,n5,n6,n7);
  }
  for(int count = 0;count <= delay_display;count++){
    dis_num(n5,n6,n7,n8);
  }
    for(int count = 0;count <= delay_display;count++){
    dis_num(n6,n7,n8,10);
  }
  for(int count = 0;count <= delay_display;count++){
    dis_num(n7,n8,10,10);
  }
    for(int count = 0;count <= delay_display;count++){
    dis_num(n8,10,10,10);
  }
      for(int count = 0;count <= delay_display;count++){
    dis_num(10,10,10,10);
  }
}
void dp_display(int digit){
  Active_pin(digit);
  digitalWrite(segmentDP,1);
  delay(2);
  digitalWrite(segmentDP,0);
  diactivate_pin();
}
void display_float_value(float val,int dp_digit){
  int Shift_val = val*100;

  int digit_1 = Shift_val % 10;
  int digit_2 = (Shift_val % 100)/10;
  int digit_3 = (Shift_val % 1000)/100;
  int digit_4 = (Shift_val % 10000)/1000;

  dis_num(digit_4,digit_3,digit_2,digit_1,1,dp_digit);
}

void display_integer_value(int val,unsigned long wait = 1000){
if(millis() - wait >= previous_time){
  previous_time = millis();
  wait_val = val;
}
  int digit_1 = wait_val % 10;
  int digit_2 = (wait_val % 100)/10;
  int digit_3 = (wait_val % 1000)/100;
  int digit_4 = (wait_val % 10000)/1000;


 dis_num(digit_4,digit_3,digit_2,digit_1);
}
void display_HEX_value(){
// 0xB04FFE01
  int digit_1 = HEX_num[4];
  int digit_2 = HEX_num[5];
  int digit_3 = HEX_num[6];
  int digit_4 = HEX_num[7];

// Serial.print(HEX_num[7],HEX);
// Serial.print(HEX_num[6],HEX);
// Serial.print(HEX_num[5],HEX);
// Serial.print(HEX_num[4],HEX);

 dis_num(digit_4,digit_3,digit_2,digit_1);
}
void calculate_temp(){
  float R1 = 10000.00;
  float analog_val = analogRead(A5);
 /* จากสูตร
   R1 คือค่าคงที่ของตัวต้านทานที่ต่อเเบบอนุกรม คือ 10 k ohm
   analog_val คือค่าดิบที่อ่านได้จากตัวของ thermistor
   ค่าที่สูงที่สุดของ analog เมื่อเทียบกีบเเรงดัน คือ 1023
   อย่างเเรกต้องหาค่าที่ R เปลี่ยนไปของ thermistor ต่ออุณหถูมิ
 */
  float diff_analog = 1023.00-analog_val;
  R_thermistor = (R1*(analog_val/diff_analog));

  /*
   การคำนวนหวอุณหภูมิจะได้จากสูตรสมการของ Steinhart-Hart
   โดยเป็นสมการที่ว่าด้วยความสัมพันธ์ระหว่างความต้านทานของ thermistor เเละ อุณหภูมิโดยคิดเป็น celcius
   มาจากการเพาะกราฟเเล้วหาตัวเเปรค่าคงที่มาคูณคือ B  ที่มีค่าระหว่าง 3000 - 4000
  */
float Const_B = 3435.00; //B constant
float R0 = 10000.00;//ค่าของความต้านทาน thermistor ที่อุณหภูมิ 25 C
float T0 = 25.00+273.15; //T เร่ิม
float ln = log(R_thermistor/R0);
temperature = (1.00/((1.00/T0) + (ln/Const_B)));
C_temp = temperature-273;


for(int i = 0; i < sizeof(avg)/sizeof(int);i++){
  avg[i] = C_temp;

}
for(int num = 0; num < sizeof(avg)/sizeof(int);num++){
  avg_temp += avg[num];
}
avg_temp = avg_temp/50;
}
void IRsignal(int decode_val){
  switch(decode_val) // Remote IR codes
{
case 0xF906FE01: Serial.println("OK "); break;
case 0xB34CFE01: Serial.println("LEFT "); break;
case 0xBF40FE01: Serial.println("RIGHT "); break;
case 0xBB44FE01: Serial.println("FORWARD "); break;
case 0xB748FE01: Serial.println("REVERSE "); break;
case 0xB04FFE01: Serial.println("1 "); read_ = 1; break;
case 0xB44BFE01: Serial.println("2 "); read_ = 2;break;
case 0xB847FE01: Serial.println("3 "); read_ = 3;break;
case 0xB14EFE01: Serial.println("4 "); read_ = 4;break;
case 0xB54AFE01: Serial.println("5 "); read_ = 5;break;
case 0xB946FE01: Serial.println("6 "); read_ = 6;break;
case 0xB24DFE01: Serial.println("7 "); read_ = 7;break;
case 0xB649FE01: Serial.println("8 "); read_ = 8;break;
case 0xBA45FE01: Serial.println("9 "); read_ = 9;break;
case 0xBE41FE01: Serial.println("0 "); read_ = 0;break;
case 0xFF42BD: Serial.println("* "); break;
case 0xFF52AD: Serial.println("# "); break;
case 0xFFFFFFFF: Serial.println("REPEAT ");break;
// default: Serial.print("other button ");
}
}
void mat_(String x){
  matrix.stroke(0xFFFFFFFF);
  matrix.textFont(Font_5x7);
  matrix.beginText(3,1, 0xFFFFFF);
  matrix.println(x);
  matrix.endText();
  matrix.endDraw();
}
void Mat_display(int number){
    switch(number){
    case 0:
     mat_("0");  
    break;
    case 1:
     mat_("1");
     break;
    case 2:
     mat_("2");
     break;
    case 3:
     mat_("3");
     break;
    case 4:
    mat_("4");
    break;
    case 5:
     mat_("5");
    break;
    case 6:
     mat_("6");
    break;
    case 7:
     mat_("7");
    break;
    case 8:
     mat_("8");
    break;
    case 9:
     mat_("9");
    break;  
      case 10:
     mat_("*");
    break;  
  }
}
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  // irrecv.blink13(true);
  matrix.begin();
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  pinMode(segmentA,OUTPUT);
  pinMode(segmentB,OUTPUT);
  pinMode(segmentC,OUTPUT);
  pinMode(segmentD,OUTPUT);
  pinMode(segmentE,OUTPUT);
  pinMode(segmentF,OUTPUT);
  pinMode(segmentG,OUTPUT);
  pinMode(segmentDP,OUTPUT);
  pinMode(active_d1,OUTPUT);
  pinMode(active_d2,OUTPUT);
  pinMode(active_d3,OUTPUT);
  pinMode(active_d4,OUTPUT);
  pinMode(bt,INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
//address 2367613F
// display_integer_value(read_);
Mat_display(read_);

if (IrReceiver.decode()) // Received IR signal
{
IRsignal(IrReceiver.decodedIRData.decodedRawData);
Serial.println("");
IrReceiver.resume(); 
ir = IrReceiver.decodedIRData.decodedRawData;
i = 0;

}
while(IrReceiver.decodedIRData.decodedRawData > 0){
  HEX_num[i] = IrReceiver.decodedIRData.decodedRawData % 0x10;
  IrReceiver.decodedIRData.decodedRawData /= 0x10;
  i++;
}
for(int j = i-1;j>=0;j--){
  Serial.println(HEX_num[j],HEX);
}
display_HEX_value();
}