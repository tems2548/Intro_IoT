#include "IoTe.h";

int segmentA ;
int segmentB ;
int segmentC ;
int segmentD ;
int segmentE ;
int segmentF ;
int segmentG ;
int segmentDP;

int num;
int a = 1;

int active_d1;
int active_d2;
int active_d3;
int active_d4;

int read_;
int delay_disp;
int wait_val;
unsigned long previous_time = 0;
unsigned long wait = 200;

int motorPin1;   // Blue
int motorPin2;   // Pink
int motorPin3;  // Yellow
int motorPin4;  // Orange

// Red
  //variable to set stepper speed
int stepCount = 0;    // number of steps the motor has taken
void step_motor_begin(
int motorPin1_,   // Blue
int motorPin2_,   // Pink
int motorPin3_,  // Yellow
int motorPin4_   // Orange
){
  motorPin1 = motorPin1_;
  motorPin2 = motorPin2_;
  motorPin3 = motorPin3_;
  motorPin4 = motorPin4_;

  pinMode(motorPin1_, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2_, OUTPUT);
  pinMode(motorPin3_, OUTPUT);
  pinMode(motorPin4_, OUTPUT);
  // initialize the serial port:
}
void motor_drive(byte pin4, byte pin3, byte pin2, byte pin1,int motorSpeed) {
  digitalWrite(motorPin4, pin4);
  digitalWrite(motorPin3, pin3);
  digitalWrite(motorPin2, pin2);
  digitalWrite(motorPin1, pin1);
  delayMicroseconds(motorSpeed);
}
void wavedrive() {
  motor_drive(1, 0, 0, 0);
  motor_drive(0, 1, 0, 0);
  motor_drive(0, 0, 1, 0);
  motor_drive(0, 0, 0, 1);
}
void fullstep() {
  motor_drive(1, 1, 0, 0);
  motor_drive(0, 1, 1, 0);
  motor_drive(0, 0, 1, 1);
  motor_drive(1, 0, 0, 1);
}
void halfstep() {
  motor_drive(1, 0, 0, 0);
  motor_drive(1, 1, 0, 0);
  motor_drive(0, 1, 0, 0);
  motor_drive(0, 1, 1, 0);
  motor_drive(0, 0, 1, 0);
  motor_drive(0, 0, 1, 1);
  motor_drive(0, 0, 0, 1);
  motor_drive(1, 0, 0, 1);
}
void reverse_halfstep() {
  motor_drive(0, 0, 0, 1);
  motor_drive(0, 0, 1, 1);
  motor_drive(0, 0, 1, 0);
  motor_drive(0, 1, 1, 0);
  motor_drive(0, 1, 0, 0);
  motor_drive(1, 1, 0, 0);
  motor_drive(1, 0, 0, 0);
  motor_drive(1, 0, 0, 1);
}
void reverse_fullstep() {
  motor_drive(0, 0, 1, 1);
  motor_drive(0, 1, 1, 0);
  motor_drive(1, 1, 0, 0);
  motor_drive(1, 0, 0, 1);
}
void reverse_wavedrive() {
  motor_drive(0, 0, 0, 1);
  motor_drive(0, 0, 1, 0);
  motor_drive(0, 1, 0, 0);
  motor_drive(1, 0, 0, 0);
}

void drive(int mode,float step,bool reverse){
   switch (mode)
   {
   case 1:
   if(reverse == true){
     reverse_wavedrive();
   }else{
     wavedrive();
   }
    break;
   case 2:
  if(reverse == true){
     reverse_fullstep();
   }else{
     fullstep();
   }
    break;
   case 3:
  if(reverse == true){
     reverse_halfstep();
   }else{
     halfstep();
   }
   break; 
   }
 }

void Segment_begin(
int A,  
int B,  
int C, 
int D,  
int E, 
int F, 
int G,  
int DP,
int d1,
int d2,
int d3,
int d4
)
{
   segmentA = A;
   segmentB = B;
   segmentC = C;
   segmentD = D;
   segmentE = E;
   segmentF = F;
   segmentG = G;
   segmentDP = DP;

     active_d1 = d1;
     active_d2 = d2;
     active_d3 = d3; 
     active_d4 = d4;


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
  
}

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

void segment(byte A ,byte B,byte C,byte D,byte E,byte F,byte G,byte dp){
  digitalWrite(segmentA,A);
  digitalWrite(segmentB,B);
  digitalWrite(segmentC,C);
  digitalWrite(segmentD,D);
  digitalWrite(segmentE,E);
  digitalWrite(segmentF,F);
  digitalWrite(segmentG,G);
  digitalWrite(segmentDP,dp);
}
void displaysegment(int num,int dp,int digit_active){
    switch (digit_active)
    {
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
   
    switch(num){ 
    case -1:
    segment(0,0,0,0,0,0,0,dp);
    break;
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
void dis_num(int digit1,int digit2,int digit3,int digit4,int act_dp,int dp_digit){
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
void ID_num(int delay_display ,int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8){
  for(int count = 0;count <= delay_display;count++){
    dis_num(-1,-1,-1,n1);
  }
  for(int count = 0;count <= delay_display;count++){
    dis_num(-1,-1,n1,n2);
  }
  for(int count = 0;count <= delay_display;count++){
    dis_num(-1,n1,n2,n3);
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
    dis_num(n6,n7,n8,-1);
  }
  for(int count = 0;count <= delay_display;count++){
    dis_num(n7,n8,-1,-1);
  }
    for(int count = 0;count <= delay_display;count++){
    dis_num(n8,-1,-1,-1);
  }
      for(int count = 0;count <= delay_display;count++){
    dis_num(-1,-1,-1,-1);
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

void display_integer_value(int val,unsigned long wait){
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