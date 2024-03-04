#define BLYNK_TEMPLATE_ID "TMPL6hgP9zhO8"
#define BLYNK_TEMPLATE_NAME "RGB LED"
#define BLYNK_AUTH_TOKEN "1Jt9OObtXLJuLAQFtG99vpJ2jQb79wq3"
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(8, 12);
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);
char auth[] = BLYNK_AUTH_TOKEN;

//---HOTSPOT ANDA
char ssid[] = ">+++[++]";
char pass[] = "tfks321921";
const int RedPin = 9;
const int GreenPin = 10;
const int BluePin = 11;
BLYNK_WRITE(V0){
  String r = param[0].asString();
  String g = param[1].asString();
  String b = param[2].asString();
  int red = r.toInt();
  int green = g.toInt();
  int blue = b.toInt();  
  analogWrite(RedPin,red);
  analogWrite(GreenPin,green);
  analogWrite(BluePin,blue);
}
void setup() {
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  Serial.begin(9600);
  EspSerial.begin(ESP8266_BAUD);
  Blynk.begin(auth, wifi, ssid, pass);
}

void loop() {
  Blynk.run();
}