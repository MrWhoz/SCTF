/*
 * IoT Project: City Live Sensor Mesh
 * Author: Tung
 * Target: read sensor then push to cloud
*/


#include <stdio.h>
#include <TH02_dev.h>
#include "Arduino.h"
#include "Wire.h"
#include <stdlib.h>
#include <rgb_lcd.h>
#include "WiFi.h"
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;
char ssid[] = "Hackathon 2016";     //  your network SSID (name) 
char pass[] = "bd@hackathon";  // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 0;

void setup(){
  
  Serial.begin(9600);        // start serial for output
  
  Serial.println("Node Station Starting Up");
  /* Power up,delay 150ms,until voltage is stable */
  delay(150);
  /* Reset HP20x_dev */
  TH02.begin();
  delay(100);
  lcd.begin(16, 2);
    
  lcd.setRGB(colorR, colorG, colorB);
  
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:    
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.println("Node Station now is Online");    
}


void loop()
{

   float temper = TH02.ReadTemperature(); 
   Serial.println("Temperature: ");   
   Serial.print(temper);
   Serial.println("C\r\n");
   lcd.setCursor(0, 0);
   lcd.print(temper);
   
   
   float humidity = TH02.ReadHumidity();
   lcd.setCursor(8,0);
   lcd.print(humidity);
   
   Serial.println("Humidity: ");
   Serial.print(humidity);
   Serial.println("%\r\n");

   delay(1000);
}
 
