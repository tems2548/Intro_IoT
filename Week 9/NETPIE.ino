#include <WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include "DHT.h"
#include "Arduino_LED_Matrix.h" 
#define LED_PIN 7 //ขาที่ต่อกับ LED
#define DHTPIN 4   //ขาที่ต่อเซนเซอร์ DHT11
int LDR = A5; //ldr value
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "TemZ"; //อย่าลืมแก้ไข SSID ของ WIFI ที่จะให้ NodeMCU ไปเชื่อมต่อ
const char* password = "0960698678"; //อย่าลืมแก้ไข PASSWORD ของ WIFI
const char* mqtt_server = "broker.netpie.io"; //อย่าลืมแก้ไข BROKER
const int mqtt_port = 1883;
const char* mqtt_Client = "a839fad7-9767-43d9-99d2-01410534f896";  //อย่าลืมแก้ไข ClientID
const char* mqtt_username = "rJT1eJnWBLDDNKJd3T2xXF74vKhje5wt";  //อย่าลืมแก้ไข Token
const char* mqtt_password = "jAhv8nnwZD52fNkR6PQnvDtbEFTSytw5"; //อย่าลืมแก้ไข Secret

WiFiClient espClient; 
PubSubClient client(espClient);

long lastMsg = 0;
int value = 0;
char msg[300];
String DataString;
ArduinoLEDMatrix matrix;

const uint32_t happy[] = {
	0x19819,
	0x80000001,
	0x81f8000
};

const uint32_t heart[] = {
	0x3184a444,
	0x44042081,
	0x100a0040
};

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
  if (client.connect(mqtt_Client, mqtt_username, mqtt_password)) { //เชื่อมต่อกับ MQTT BROKER
    Serial.println("connected");
    client.subscribe("@msg/operator");
    client.subscribe("@msg/matrix");
  }
  else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println("try again in 5 seconds");
    delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String message;
  for (int i = 0; i < length; i++) {
    message = message + char(payload[i]);
    
  }
  Serial.println(message);
  if(String(topic) == "@msg/operator") {
    if (message == "ON"){
      digitalWrite(LED_PIN,HIGH);
      //client.publish("@shadow/data/update", "{\"data\" : {\"led\" : \"on\"}}");
      Serial.println("LED ON"); }
    else if (message == "OFF") {
      digitalWrite(LED_PIN,LOW);
      //client.publish("@shadow/data/update", "{\"data\" : {\"led\" : \"off\"}}");
      Serial.println("LED OFF"); }
    } 

    if(String(topic) == "@msg/matrix") {
    if (message == "HAPPY"){
      matrix.loadFrame(happy);
      //client.publish("@shadow/data/update", "{\"data\" : {\"led\" : \"on\"}}");
      }
    else if (message == "HEART") {
      matrix.loadFrame(heart);
      //client.publish("@shadow/data/update", "{\"data\" : {\"led\" : \"off\"}}");
      }
    }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN,OUTPUT);
  matrix.begin();
  dht.begin();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); //เชื่อมต่อกับ WIFI
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //เชื่อมต่อกับ WIFI สำเร็จ แสดง IP
  client.setServer(mqtt_server, mqtt_port); //กำหนด MQTT BROKER, PORT ที่ใช้
  client.setCallback(callback); //ตั้งค่าฟังก์ชันที่จะทำงานเมื่อมีข้อมูลเข้ามาผ่านการ Subscribe
  client.subscribe("@msg/operator");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  long now = millis();
  if (now - lastMsg > 100) { //จับเวลาส่งข้อมูลทุก ๆ 5 วินาที
    lastMsg = now;
    ++value;
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int light = map(analogRead(LDR),0,1024,100,0);
    DataString = "{\"data\":{\"Temperature\":" + String(t) + ",\"Humidity\":" + String(h) + ",\"Light\":" + String(light) + "}}";
    // Example of data : {"data":{"temperature":25 , "humidity": 60}}
    DataString.toCharArray(msg, 300);
    Serial.println(msg);
    client.publish("@shadow/data/update", msg); // อย่าลืมแก้ไข TOPIC ที่จะทำการ PUBLISH ไปยัง MQTT BROKER
  }
  delay(1);
}