#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>
#include "GravityTDS.h"
#include <OneWire.h>
#include <DallasTemperature.h>

SoftwareSerial phsensor(10, 11);
String pHval;
#define TdsSensorPin A0
GravityTDS gravityTds;
String uno;
float temperature = 25, tdsValue = 0;
const int rs = A5, en = A4, d4 = A3, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int oneWireBus = A2;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
int trubidity = A1;
const int trigPin = 4;
const int echoPin = 3;
int relay1 = 9;
int relay2 = 8;
float a, b, c, d, e, f;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  Serial.begin(9600);
  phsensor.begin(9600);
  lcd.begin(16, 2);
  sensors.begin();
  gravityTds.setPin(TdsSensorPin);
  gravityTds.setAref(5.0);
  gravityTds.setAdcRange(1024);
  gravityTds.begin();
  lcd.setCursor(0, 0);
  lcd.print("HYDROMIND MACHINE");
  lcd.setCursor(0, 1);
  lcd.print("LEARNING HYDRO:)");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PONIC FARMING:)");
  delay(1000);
}

void loop() {
  String data1 = "";
  if (Serial.available() > 0) {
    data1 = Serial.readString();
    if (data1.indexOf('t') != -1 && data1.length() > 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("RECEIVE DATA:)");
      lcd.setCursor(0, 1);
      lcd.print(data1);
      delay(2000);
      int indexA = data1.indexOf("t") + 1;
      int indexB = data1.indexOf("u") + 1;
      int indexC = data1.indexOf("v") + 1;
      int indexD = data1.indexOf("w") + 1;
      int indexE = data1.indexOf("x") + 1;
      int indexF = data1.indexOf("y") + 1;
      delay(500);
      String valueA = data1.substring(indexA, indexB - 1);
      String valueB = data1.substring(indexB, indexC - 1);
      String valueC = data1.substring(indexC, indexD - 1);
      String valueD = data1.substring(indexD, indexE - 1);
      String valueE = data1.substring(indexE, indexF - 1);
      String valueF = data1.substring(indexF);
      a = valueA.toFloat();
      b = valueB.toFloat();
      c = valueC.toFloat();
      d = valueD.toFloat();
      e = valueE.toFloat();
      f = valueF.toFloat();
    }
    if (data1 != ".") {
      if (a < -0.28) {
        digitalWrite(relay2, LOW);
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("TURBI HIGH:)");
        lcd.setCursor(0, 1);
        lcd.print("PUMP ON :)");
        delay(2000);
      } else digitalWrite(relay2, HIGH);

      if (b < 0.50) {
        digitalWrite(relay2, LOW);
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("PH VALUE HIGH:)");
        lcd.setCursor(0, 1);
        lcd.print("PUMP ON :)");
        delay(2000);
      } else digitalWrite(relay2, HIGH);

      if (c > 0.21) {
        digitalWrite(relay2, LOW);
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("TDS VALUE HIGH:)");
        lcd.setCursor(0, 1);
        lcd.print("PUMP ON :)");
        delay(2000);
      } else digitalWrite(relay2, HIGH);

      if (d < 0.40) {
        digitalWrite(relay1, LOW);
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("TEMP HIGH:)");
        lcd.setCursor(0, 1);
        lcd.print("FAN ON :)");
        delay(2000);
      } else digitalWrite(relay1, HIGH);

      if (e < 0.20) {
        digitalWrite(relay2, LOW);
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WATERLEVEL LOW:)");
        lcd.setCursor(0, 1);
        lcd.print("PUMP ON :)");
        delay(2000);
      } else digitalWrite(relay2, HIGH);
    }
    sensors.requestTemperatures();
    float temperatureC = sensors.getTempCByIndex(0);
    int value = analogRead(trubidity);
    gravityTds.setTemperature(temperature);
    gravityTds.update();
    tdsValue = gravityTds.getTdsValue();
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.setCursor(0, 1);
    lcd.print("TDS :");
    lcd.print(tdsValue);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TURB : ");
    lcd.print(value);
    lcd.setCursor(0, 1);
    lcd.print("TEMP :");
    lcd.print(temperatureC);
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PH VALUE ");
    lcd.setCursor(0, 1);
    lcd.print(pHval);
    delay(2000);
    if (phsensor.available() > 0) {
      pHval = phsensor.readString();
      int a = pHval.indexOf(':');
      int b = pHval.indexOf(',');
      a = a + 1;
      pHval = pHval.substring(a, b);
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DATA SENT ML:)");
    lcd.setCursor(0, 1);
    lcd.print("PROCESSING:)");
    delay(1000);
    uno = "a" + String(value) + "b" + String(pHval) +  "c" + String(tdsValue) +  "d" + String(temperatureC) +  "e" + String(distance) +  "f";
    Serial.println(uno);
    delay(2000);
  }
}
