#include <ESP8266WiFi.h>

String apiKey = "1YQDRV8CP16Q3AKB";
const char* ssid = "water";
const char* pass = "123456789";
const char* server = "api.thingspeak.com";

WiFiClient client;

void setup() {
  Serial.begin(9600);
  delay(10);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() { 
  if(Serial.available()>0){
    String data = Serial.readStringUntil('\n');

    int indexA = data.indexOf("a") + 1;
    int indexB = data.indexOf("b") + 1;
    int indexC = data.indexOf("c") + 1;
    int indexD = data.indexOf("d") + 1;
    int indexE = data.indexOf("e") + 1;

    String valueA = data.substring(indexA, indexB - 1);
    String valueB = data.substring(indexB, indexC - 1);
    String valueC = data.substring(indexC, indexD - 1);
    String valueD = data.substring(indexD, indexE - 1);

    if (client.connect(server, 80)) {
      String postStr = apiKey;
      postStr += "&field1=" + valueA;
      postStr += "&field2=" + valueB;
      postStr += "&field3=" + valueC;
      postStr += "&field4=" + valueD;

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);
      client.stop();
    }
  }
  delay(5000);
}   
