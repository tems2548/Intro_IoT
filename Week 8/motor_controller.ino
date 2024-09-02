#define bt 12
int motorPin1 = 8;   // Blue
int motorPin2 = 9;   // Pink
int motorPin3 = 10;  // Yellow
int motorPin4 = 11;  // Orange


// Red
int motorSpeed = 2500;  //variable to set stepper speed
int stepCount = 0;    // number of steps the motor has taken
void motor_drive(byte pin4, byte pin3, byte pin2, byte pin1) {
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
void reverse_fullstep() {
  motor_drive(0, 0, 1, 1);
  motor_drive(0, 1, 1, 0);
  motor_drive(1, 1, 0, 0);
  motor_drive(1, 0, 0, 1);
}
void setup() {
  pinMode(motorPin1, OUTPUT);  //declare the motor pins as outputs
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(bt, INPUT_PULLUP);
  Serial.begin(115200);  // initialize the serial port:
}

void loop() {
  // 1.42 degree per fullstep,wavedrive,halfstep
  // fullstep();
  // wavedrive();  // จ่ายไฟให้ทำงานครั้งละ 1 ขด
  // halfstep();   // ใช้ทั้งสองแบบรวมกันทำให้หมุนได้ครั้งละครึ่งเสตป
  if (digitalRead(bt) == 0) {
      reverse_fullstep();  // จ่ายไฟให้ทำงานครั้งละ 2 ขด
      Serial.print("steps:");
      Serial.println(stepCount);
  }
    else {
      fullstep();
      Serial.print("steps:");
      Serial.println(stepCount);
    }
  }
