#define BLYNK_TEMPLATE_ID "TMPL67YCCcqz3"
#define BLYNK_TEMPLATE_NAME "Monitoring DHT11"
#define BLYNK_AUTH_TOKEN "ulWlI5_rjjRtkFAGyBBpoG1tJ6KYGaKM"
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal Lcd(2,3,4,5,6,7);
#include "DHT.h"
#define DHTPIN 10
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
char auth[] = BLYNK_AUTH_TOKEN;
// Sesuaikan dengan ssid dan password hotspot anda
char ssid[] = "RV-A2";
char pass[] = "monde555";
SoftwareSerial EspSerial(8, 9); // RX, TX
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);
int humi, temp;
void setup(){
  Lcd.begin(16,2);
  Lcd.print("Tes Koneksi WiFi");
  Lcd.setCursor(0,1);
  Lcd.print("Tunggu...");
  Serial.begin(9600);
  EspSerial.begin(9600);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass);
  Lcd.print("OK! ");
  delay(2000);
  Lcd.clear();
  Lcd.print("Monitoring Suhu");
  Lcd.setCursor(0,1);
  Lcd.print("dan Kelembaban");
  delay(2000);
  dht.begin();
  Lcd.clear();
}
void sendData(){
  humi = dht.readHumidity();
  temp = dht.readTemperature();
  if (isnan(humi) || isnan(temp)) {
    Serial.println("DHT11 tidak terbaca... !");
    return;
  }
  else{
    Lcd.setCursor(0,0);
    Lcd.print("Temp:");
    Lcd.print(temp);
    Lcd.print("C");
    Lcd.setCursor(0,1);
    Lcd.print("Humi:");
    Lcd.print(humi);
    Lcd.print("%");
    Blynk.virtualWrite(0, temp);
    Blynk.virtualWrite(1, humi);
  }
}
void loop(){
  Blynk.run();
  delay(1000);
  sendData();
}