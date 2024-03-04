#define BLYNK_TEMPLATE_ID "TMPL6t18cTzgr"
#define BLYNK_TEMPLATE_NAME "Monitoring Sensor Ultrasonik"
#define BLYNK_AUTH_TOKEN "oSFTrHnRFCXRiL9jyef-NnXnC88_i9C3"

#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

#include <SoftwareSerial.h>
SoftwareSerial EspSerial (8, 9); // RX, TX
ESP8266 wifi(&EspSerial);
#define ESP8266_BAUD 9600

#include <LiquidCrystal.h>
LiquidCrystal Icd(2,3,4,5,6,7);

const int TRIGPIN=10;
const int ECHOPIN=11;
unsigned int jarak,timer;

WidgetLCD LCD(V0);
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "daffa";
char pass[] = "123456789";

void setup(){
pinMode(ECHOPIN, INPUT);
pinMode(TRIGPIN, OUTPUT);
Icd.begin(16,2);
Icd.print("Tes Koneksi WiFi");
Icd.setCursor(0,1);
Icd.print(ssid);
Serial.begin(9600);
EspSerial.begin(9600);
delay(10);
Blynk.begin(auth, wifi, ssid, pass);
Icd.print(" OK!");
delay(2000);
Icd.clear();
Icd.print("Ukur Jarak");
Icd.setCursor(0,1);
Icd.print("Jarak:");
}
//--
void loop(){
Blynk.run();
Baca_SRF04();
Icd.setCursor(6,1);
Icd.print(jarak);
Icd.print("cm");
//-----send to LCD Blynk
LCD.print(0,0,"Ukur Jarak");
LCD.print(0,1, "Jarak=");
byte x;
LCD.print(7,1,jarak);
if (jarak>99)x=10;
else if(jarak>9)x=9;
else x=8;
LCD.print(x,1,"cm ");
delay(1000);
}
//=
void Baca_SRF04(){
digitalWrite(TRIGPIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIGPIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGPIN, LOW);
timer = pulseIn(ECHOPIN, HIGH);
jarak= timer/58;
}