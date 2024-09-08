#ifndef IoTe_h
#define IoTe_h

#include <Arduino.h>
void Segment_begin(
int segmentA,  
int segmentB,  
int segmentC, 
int segmentD,  
int segmentE, 
int segmentF, 
int segmentG,  
int segmentDP,
int active_d1,
int active_d2,
int active_d3,
int active_d4
);
void Active_pin(int act);
void diactivate_pin();
void segment(byte A ,byte B,byte C,byte D,byte E,byte F,byte G,byte dp = 0);
void displaysegment(int num,int dp = 0,int digit_active = 0);
void dis_num(int digit1,int digit2,int digit3,int digit4,int act_dp = 0,int dp_digit = 0);
void ID_num(int delay_display ,int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8);
void dp_display(int digit);
void display_value(float val);
void display_integer_value(int val,unsigned long wait = 1000);
void step_motor_begin(
int motorPin1,   // Blue
int motorPin2,   // Pink
int motorPin3,  // Yellow
int motorPin4   // Orange
);
void drive(int mode,float step,bool reverse);
void wavedrive();
void fullstep();
void halfstep();
void reverse_halfstep();
void reverse_fullstep();
void reverse_wavedrive(); 
void motor_drive(byte pin4, byte pin3, byte pin2, byte pin1,int motorSpeed = 2500);

#endif