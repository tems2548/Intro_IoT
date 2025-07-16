#ifndef intro_IoTe
#define intro_IoTe

#include <Arduino.h>
class StepMotor {

private:
  int motorPin1;  // Blue
  int motorPin2;  // Pink
  int motorPin3;  // Yellow
  int motorPin4;  // Orange

  int stepCount = 0;  // number of steps the motor has taken
  void motor_drive(byte pin4, byte pin3, byte pin2, byte pin1, int motorDelay = 50);
  void wavedrive();
  void fullstep();
  void halfstep();
  void reverse_halfstep();
  void reverse_fullstep();
  void reverse_wavedrive();

public:
  void begin(uint8_t motorPin_1, uint8_t motorPin_2, uint8_t motorPin_3, uint8_t motorPin_4);
  void drive(int mode, bool reverse = false);
};

class seven_segments {
private:
  int segmentA;
  int segmentB;
  int segmentC;
  int segmentD;
  int segmentE;
  int segmentF;
  int segmentG;
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

  void Active_pin(int act);
  void diactivate_pin();
  void segment(byte A, byte B, byte C, byte D, byte E, byte F, byte G, byte dp);
public:
  void begin(
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
    int d4);

 void displaysegment(int num, int dp = 0, int digit_active = 0);
 void dis_num(int digit1, int digit2, int digit3, int digit4, int act_dp = 0, int dp_digit = 0);
 void ID_num(int delay_display, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8);
 void dp_display(int digit);
 void display_value(float val);
 void display_integer_value(int val, unsigned long wait = 1000);
};
#endif
