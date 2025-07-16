
class StepMotor{


public: 

int motorPin1;   // Blue
int motorPin2;   // Pink
int motorPin3;  // Yellow
int motorPin4;  // Orange

int stepCount = 0;    // number of steps the motor has taken

void begin(uint8_t motorPin_1,uint8_t motorPin_2,uint8_t motorPin_3,uint8_t motorPin_4){
  pinMode(motorPin_1,OUTPUT);
  pinMode(motorPin_2,OUTPUT);
  pinMode(motorPin_3,OUTPUT);
  pinMode(motorPin_4,OUTPUT);

  motorPin1 = motorPin_1;   // Blue
  motorPin2 = motorPin_2;   // Pink
  motorPin3 = motorPin_3;  // Yellow
  motorPin4 = motorPin_4;  // Orange
}

void motor_drive(byte pin4, byte pin3, byte pin2, byte pin1,int motorDelay = 100) {
  digitalWrite(motorPin4, pin4);
  digitalWrite(motorPin3, pin3);
  digitalWrite(motorPin2, pin2);
  digitalWrite(motorPin1, pin1);
  delayMicroseconds(motorDelay);
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

void drive(int mode,bool reverse = false){
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
};

StepMotor SM;


void setup() {
  SM.begin(9,8,7,6);

}

void loop() {
  // put your main code here, to run repeatedly:

}
