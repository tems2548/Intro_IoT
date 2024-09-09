#define led1 8
#define led2 9

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(6,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  if(digitalRead(6) == 1){
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  delay(3000);
  digitalWrite(led2,0);
  delay(3000);  
  }else{
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  delay(1000);
  digitalWrite(led1,0);//1 cycle 1 sec
  delay(1000);
  digitalWrite(led1,1);
  delay(1000);
  digitalWrite(led2,0);// 1 cycle 3 sec
  digitalWrite(led1,0);
  delay(1000);
  digitalWrite(led1,1);
  delay(1000);
  digitalWrite(led1,0);
  delay(1000);
  }
}