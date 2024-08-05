
int segmentA = 11;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;

int avg[50];
int bt = 12;
int num;
int a = 1;

int dim;
int active_d1 = 5;
int active_d2 = 6;
int active_d3 = 9;
int active_d4 = 10;

int read_;
int delay_disp;
float R_thermistor;
float temperature;
float C_temp;
float avg_temp;
unsigned long previous_time = 0;
unsigned long wait = 200;

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
    case 10:
    segment(0,0,0,0,0,0,0,dp);
     break;
  }
}
void dis_num(int digit1,int digit2,int digit3,int digit4,int act_dp = 0,int dp_digit = 0){
  num = 4;

   for(num;num >= 0;num--){
      Active_pin(num);
     switch(num){
      case 4:
         displaysegment(digit1);
         if(act_dp == 1 && dp_digit == 4){
           displaysegment(digit1,1);
         }
      break;
      case 3:
         displaysegment(digit2);
        if(act_dp == 1 && dp_digit == 2){
           displaysegment(digit2,1);
         }
      break;
      case 2:
         displaysegment(digit3);
         if(act_dp == 1 && dp_digit == 3){
           displaysegment(digit3,1);
         }
      break;
      case 1:
         displaysegment(digit4);
         if(act_dp == 1 && dp_digit == 4){
           displaysegment(digit4,1);
         }
      break;
     }
      delay(2);
      diactivate_pin();
    }
}

void setup() {
  Serial.begin(9600);
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
void display_value(float val){
  int Shift_val = val*100;

  int digit_1 = Shift_val % 10;
  int digit_2 = (Shift_val % 100)/10;
  int digit_3 = (Shift_val % 1000)/100;
  int digit_4 = (Shift_val % 10000)/1000;

  dis_num(digit_4,digit_3,digit_2,digit_1,1,2);
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
void loop() {
  float voltage_val = analogRead(A0)*(5.0/1023);
  calculate_temp();
  display_value(avg_temp);
  Serial.println(temperature);
}