#include <stdio.h>
#include <TH02_dev.h>
#include "Arduino.h"
#include "Wire.h"
#include <stdlib.h>
#include <rgb_lcd.h>
#include "WiFi.h"
#include <PubSubClient.h>
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;
char ssid[] = "SCTF";     //  your network SSID (name) 
char pass[] = "khongcobiet";  // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status
float temper = 0;
float humidity = 0;
rgb_lcd lcd;

const int colorR = 0;
const int colorG = 255;
const int colorB = 0;

void setup(){
  Serial1.begin(9600);
  Serial.begin(9600);        // start serial for output
  
  Serial.println("Node Station Starting Up");
  /* Power up,delay 150ms,until voltage is stable */
  delay(150);
  /* Reset HP20x_dev */
  TH02.begin();
  delay(100);
  lcd.begin(16, 2);
    
  lcd.setRGB(colorR, colorG, colorB);
//  
//  while ( status != WL_CONNECTED) { 
//    Serial.print("Attempting to connect to WPA SSID: ");
//    Serial.println(ssid);
//    // Connect to WPA/WPA2 network:    
//    status = WiFi.begin(ssid, pass);
//
//    // wait 10 seconds for connection:
//    delay(10000);
//  }
//    IPAddress ip = WiFi.localIP();
//    Serial.print("IP Address: ");
//  Serial.println(ip);
//  Serial.println("Node Station now is Online");    
//}
//
}
void loop()
{

   temper = TH02.ReadTemperature(); 
   Serial.println("Temperature: ");   
   Serial.print(temper);
   Serial.println("C\r\n");
   lcd.setCursor(0, 0);
   lcd.print(temper);
   
   
   humidity = TH02.ReadHumidity();
   lcd.setCursor(8,0);
   lcd.print(humidity);
   
   Serial.println("Humidity: ");
   Serial.print(humidity);
   Serial.println("%\r\n");

   sensorValue = analogRead(sensorPin);
   lcd.setCursor(0,1);
   lcd.print(sensorValue);

  //String t = dtostrf(temper,1,4,buffer);
  //char voltageMsg[25];
//sprintf(voltageMsg, temper);

   char buffer[5];
  sprintf(buffer,"%f", temper);
  String temp2 = String(buffer);
  char buffer2[5];
  sprintf(buffer2,"%f", humidity);
  String humid2 = String (buffer2);
char buffer3[5];
   sprintf(buffer3,"%d", sensorValue);
  String CO = String(buffer3); 
  
//  String url = "curl --data \'{\"temp\" : \""+temp2+"\"}\'  https://edisoniot.firebaseio.com/test.json";
//  String url = "curl --data \'{\"Date\":\"26 Mar\",\"temp\" : \""+temp2+"\",\"humid\" : \""+humid2+"\",\"CO\" : \""+CO+"\" }\'  https://edisoniot.firebaseio.com/SCTF.json";
//  char* s; 
//  s =&url[0];
//  
// //system("curl --data \'{\"temp\" :"+t+" \"\"}\'  https://edisoniot.firebaseio.com/test.json");
//system(s);
Serial1.write("012");
   delay(1000);
}

