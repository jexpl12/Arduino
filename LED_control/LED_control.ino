#define BLYNK_TEMPLATE_ID "TMPL6-MsHYUPA"
#define BLYNK_TEMPLATE_NAME "Kontrol 1 LED"
#define BLYNK_AUTH_TOKEN "iLE5UyJRzNSBWAxQ0tbkswQ3dXal9mqu"

#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial EspSerial(8, 9); // RX, TX
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Declare the lcd object
ESP8266 wifi(&EspSerial);

char auth[] = "iLE5UyJRzNSBWAxQ0tbkswQ3dXal9mqu";
char ssid[] = "Galaxy S23 Ultra";
char pass[] = "mfj83pn48m53kdwi";

BLYNK_WRITE(V0)
{
  int value1 = param.asInt();
  digitalWrite(10, value1);
}

BLYNK_WRITE(V1)
{
  int value2 = param.asInt();
  digitalWrite(11, value2);
}

BLYNK_WRITE(V2)
{
  int value3 = param.asInt();
  digitalWrite(12, value3);
}

BLYNK_WRITE(V3)
{
  int value4 = param.asInt();
  digitalWrite(13, value4);
}

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Tes Koneksi WiFi");
  lcd.setCursor(0, 1);
  lcd.print(ssid);
  pinMode(10, OUTPUT);
  digitalWrite(10, 0);

  Serial.begin(115200);
  EspSerial.begin(9600);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);

  lcd.print(" OK!");
  delay(2000);
  lcd.clear();
  lcd.print("Kontrol LED xixixi");
  delay(2000);
}

void loop() {
  Blynk.run();
  // Your other loop code here
}