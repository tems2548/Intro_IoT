#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp> // Include the library
uint16_t sAddress = 0x1037;//613f
uint16_t sCommand_1 = 0xABCD1;//FE01613f
uint16_t sCommand_2 = 0xABCD2;
uint16_t sCommand_3 = 0xABCD3;
uint16_t sCommand_4 = 0xABCD4;
uint16_t commands[] = {
  sCommand_1,
  sCommand_2,
  sCommand_3,
  sCommand_4
};
uint8_t sRepeats= 0;

int key_1 = 12; // KEY pin
int key_2 = 11;
int key_3 = 10;
int key_4 = 9;

int led = 13; // LED pin 
void setup()
{
  Serial.begin(9600);
  IrSender.begin(); // Start with IR_SEND_PIN 
  disableLEDFeedback();
  pinMode(led, OUTPUT);
  pinMode(key_1, INPUT_PULLUP); 
  pinMode(key_2, INPUT_PULLUP); 
  pinMode(key_3, INPUT_PULLUP); 
  pinMode(key_4, INPUT_PULLUP); 
  pinMode(LED_BUILTIN, OUTPUT); // LED pin Serial.begin(9600); IrSender.begin(); // Start with IR_SEND_PIN disableLEDFeedback(); // Disable feedback LED at default feedback LED pin
}
void loop() {
  IR_send(digitalRead(key_1),0);
  IR_send(digitalRead(key_2),1);
  IR_send(digitalRead(key_3),2);
  IR_send(digitalRead(key_4),3);
}
void IR_send(int button_val,int command){
  if (button_val == 0)
{
Serial.println();
Serial.print("Send IR signals at pin ");
Serial.println(IR_SEND_PIN);
Serial.print("Send Protocol=NEC : address=");
Serial.print(sAddress, HEX);
Serial.print(", command=");
Serial.print(commands[command], HEX);
Serial.print(", repeats=");
Serial.println(sRepeats);
IrSender.sendNEC(sAddress, commands[command], sRepeats);
delay(100);
}
}