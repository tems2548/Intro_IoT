
int segmentA = 11;
int segmentB = A1;
int segmentC = A2;
int segmentD = 2;
int segmentE = 4;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;

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

void segment(byte A ,byte B,byte C,byte D,byte E,byte F,byte G){
  digitalWrite(segmentA,A);
  digitalWrite(segmentB,B);
  digitalWrite(segmentC,C);
  digitalWrite(segmentD,D);
  digitalWrite(segmentE,E);
  digitalWrite(segmentF,F);
  digitalWrite(segmentG,G);
}
void dis_num(int digit1,int digit2,int digit3,int digit4){
  num = 4;
   for(num;num >= 0;num--){
      Active_pin(num);
     switch(num){
      case 4:
         displaysegment(digit1);
      break;
      case 3:
         displaysegment(digit2);
      break;
      case 2:
         displaysegment(digit3);
      break;
      case 1:
         displaysegment(digit4);
      break;
     }
      delay(2);
      diactivate_pin();
    }
}
void displaysegment(int digit){
    switch(digit){
    case 0:
     segment(1,1,1,1,1,1,0);
    break;
    case 1:
     segment(0,1,1,0,0,0,0);
     break;
    case 2:
     segment(1,1,0,1,1,0,1);
     break;
    case 3:
     segment(1,1,1,1,0,0,1);
     break;
    case 4:
     segment(0,1,1,0,0,1,1);
    break;
    case 5:
     segment(1,0,1,1,0,1,1);
    break;
    case 6:
     segment(1,0,1,1,1,1,1);
    break;
    case 7:
     segment(1,1,1,0,0,0,0);
    break;
    case 8:
     segment(1,1,1,1,1,1,1);
    break;
    case 9:
     segment(1,1,1,1,0,1,1);
    break;  
    case 10:
    segment(0,0,0,0,0,0,0);
     break;
  }
}
void dims_val(int PIN){
  dim = map(PIN,0,1023,0,255);
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
void loop() {
  ID_num(
  // //---------------------------------- // หน่วงเวลา // ----------------------------------
  // 20,
  // // ---------------------------------- เลขประจำตัว !!!!!!!! ของตัวเองงงงงงงงงงงงง //
  // 6,
  // 7,
  // 0,
  // 1,
  // 1,
  // 5,
  // 7,
  // 8
  // );
}