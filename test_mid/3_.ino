#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp> // Include the library
// uint16_t sAddress = 0x1037;//613f
uint16_t sCommand_1 = 0x6C;//FE01613f
uint16_t sCommand_2 = 0x48;
uint16_t commands[] = {
  sCommand_1,
  sCommand_2
};
uint8_t sRepeats= 0;

int key_1 = 6; // KEY pin
int key_2 = 5;
int led_1 = 8; // LED pin 
int led_2 = 9;

uint16_t lights[] = {
  led_1,
  led_2
};
void setup()
{
  Serial.begin(9600);
  IrSender.begin(); // Start with IR_SEND_PIN 
  disableLEDFeedback();
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(key_1, INPUT_PULLUP); 
  pinMode(key_2, INPUT_PULLUP); 
  pinMode(LED_BUILTIN, OUTPUT); // LED pin Serial.begin(9600); IrSender.begin(); // Start with IR_SEND_PIN disableLEDFeedback(); // Disable feedback LED at default feedback LED pin
}
void loop() {
  IR_send(digitalRead(key_1),0,0);
  IR_send(digitalRead(key_2),1,1);
}
void IR_send(int button_val,int command,int light){
  if (button_val == 1)
{
digitalWrite(lights[light],1);
delay(200);
digitalWrite(lights[light],0);
delay(200);
Serial.println();
// Serial.print("Send IR signals at pin ");
// Serial.println(IR_SEND_PIN);
// Serial.print("Send Protocol=NEC : address=");
// Serial.print(sAddress, HEX);
Serial.print("command = ");
Serial.print(commands[command], HEX);
// Serial.print(", repeats=");
// Serial.println(sRepeats);
IrSender.sendNEC(commands[command], sRepeats);
delay(100);
}
}