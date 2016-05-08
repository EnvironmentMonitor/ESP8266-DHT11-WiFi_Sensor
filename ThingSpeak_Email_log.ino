/*
This sketch will post the data from an i2c HTU21D Sensor to thingspeak, 
with the spiffs used to store a 24 hour data log the log is emailed,
system rebooted every 24 hours.

Set up an account at http://smtp2go.com
Encrypt your Password & Username using https://www.base64encode.org/

Set up an account at http://thingspeak.com

*/


#include "ESP8266WiFi.h"
#include <Wire.h>
#include "HTU21D.h"
#include "FS.h"
HTU21D myHTU21D;
ADC_MODE(ADC_VCC);
WiFiClient  client;
char popyahoo[] = "smtpcorp.com";                                   // set email service
int port = 2525;                                                    // Port for mail server
unsigned long ulMeasCount=0;                                        // values already measured
unsigned long ulMeasDelta_ms = 60000;                               // Sample interval 60 Seconds
unsigned long ulNextMeas_ms;                                        // next meas time
const char* thingspeak_key = "AAAAAAAAAAAAAAAA";                    // your thingspeak write key
char ssid[] = "-Network-";                                          // your network SSID (name) 
char pass[] = "----Passkey----";                                    // your network password
String toaddres = "RCPT To: <AAAAAAAAAAAAAAAAAAAAAAAAAA@AAAA.AAA>"; // Where your Last 24Hr Log has to be emailed To
String frmaddrs = "MAIL From: <AAAAAAAAAAAAAAAAAAAAAAA@AAAA.AAA>";  // Where your Log has to be emailed From
String b64Usernm = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";  // B64 Encrypted smtp2go Username
String b64Passwd = "AAAAAAAAAAAAAAAA";                              // B64 Encrypted smtp2go Password
String emailbutton = "off";                                         // Flag for sending mail by push button
extern "C" 
{
#include "user_interface.h"
}
void wsysreset()
{
    ESP.restart();
}

void setup() {
  Wire.begin(4,5);
  myHTU21D.begin();
  // inital connect
  WiFi.mode(WIFI_STA);
  delay(500);
  WiFi.begin(ssid, pass);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  // initialize the SPIFFS
  if (!SPIFFS.begin()) {
       while(1);
       }
  // clear any old data....
  // File f = SPIFFS.open("/humidlog.CSV", "w");
  // f.close();
  if (SPIFFS.exists("/humidlog.CSV")){ SPIFFS.remove("/humidlog.CSV");}
  ulNextMeas_ms = millis()+ulMeasDelta_ms;
}

void loop() {

  // Check the number of samples if =>1440 or button pressed > send mail.....
  if (ulMeasCount==1440 || digitalRead(0)==0) {// Set the Number of samples before the Log is to be emailed
    delay(3000);
     if(sendEmail()) {
     wsysreset();
      } 
      else {
     wsysreset();
      }
  }  

if (millis()>=ulNextMeas_ms) 
 {   
 ulNextMeas_ms = millis()+ulMeasDelta_ms;
 ulMeasCount++;
  // Read the input on each pin, convert the reading, and set each field to be sent to ThingSpeak.
  // On ESP8266: ESP.getVcc measures the supply input 0-4000 millivolts
  // On ESP8266: analogRead 0 - 1023 maps to 0 - 1 volts
   float pfVcC = ESP.getVcc();
   float S1pfHum = myHTU21D.readHumidity();
   float S1pfTemp = myHTU21D.readTemperature();
   float a = 17.67;
   float b = 243.5;
   float alpha = (a * S1pfTemp)/(b + S1pfTemp) + log(S1pfHum/100);
   float pfDew = (b * alpha)/(a - alpha);

 String logdata = "[";
  logdata += ulMeasCount;
  logdata += ","; 
  logdata += S1pfTemp; 
  logdata += ",";
  logdata += S1pfHum;  
  logdata += ",";    
  logdata += pfVcC/1000;
  logdata += "]\r\n";
File logF = SPIFFS.open("/humidlog.CSV", "a");
  if (logF) { 
    logF.print(logdata);
    logF.close();
    ulMeasCount++;   
      }
    else {
      while(1);
    }


   
// Use WiFiClient class to create Thingspeak Post
  WiFiClient client;
  if (!client.connect("api.thingspeak.com", 80)) {
    return;
  }
  String url = "/update?key=";
  url += thingspeak_key;
  url += "&field1=";
  url += S1pfTemp;
  url += "&field2=";
  url += S1pfHum;
  url += "&field3=";
  url += pfDew;
  url += "&field4=";
  url += pfVcC/1000;
/*  url += "&field5=";
  url += pfTemp;
  url += "&field6=";
  url += pfHum;  
*/
// This will send the request to Thingspeak
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: api.thingspeak.com\r\n" + 
               "Connection: close\r\n\r\n");
  delay(50);
  client.stop();

  
 }
}

byte sendEmail()
{
  byte thisByte = 0;
  byte respCode;

  if(client.connect( popyahoo,port) == 1) {
  } else {
    return 0;
  }
  if(!eRcv()) {return 0 ;}
  client.print("EHLO ");
    client.println(WiFi.localIP());
  if(!eRcv()) {return 0 ;}
  client.println("auth login");
  if(!eRcv()) {return 0 ;}
// Change to your base64 encoded user
  client.println(b64Usernm);//
  if(!eRcv()) {return 0 ;}
// change to your base64 encoded password
  client.println(b64Passwd);//
  if(!eRcv()) {return 0;}
// change to your email address (sender)
  client.println(frmaddrs);
  if(!eRcv()) {return 0 ;}
// change to recipient address
  client.println(toaddres);
  if(!eRcv()) {return 0 ;}
  client.println("DATA");
  if(!eRcv()) {return 0 ;}
// change to recipient address
  client.println("To: The Environment Monitor <environmental.monitor.log@gmail.com>");
String sTable,DsTable;
// change to your address This is sensor ID
  client.print("From: I2C HTU21D Monitor <");
  client.print(wifi_station_get_hostname());
  client.println(">");

  client.println("Subject: ESP8266 Daily Environment Report\r\n");

  client.println("This is Sent Directly from An ESP8266 Module every 24 Hours");

  client.print("The Total Number Of Environment Samples Values Being Tranferred Are -  ");

  client.println(ulMeasCount);
  
  client.println("_____________________________________________________________");
File logF = SPIFFS.open("/humidlog.CSV", "r");
    if (!logF) {
      while(1);
    } 
  DsTable = logF.readStringUntil('[');
    while (logF.available())
    {
      sTable = logF.readStringUntil(']');  
      client.println(sTable);
     DsTable = logF.readStringUntil('[');
      sTable="";
    }

  client.println(sTable);

  client.println("_________________End of Data_______________");

  client.println(".");  
  if(!eRcv()) {return 0 ;}
  client.println("QUIT");
  if(!eRcv()) {return 0 ;}
  client.stop();
  return 1;
}

byte eRcv()
{
  byte respCode;
  byte thisByte;
  int loopCount = 0;

  while(!client.available()) {
    delay(1);
    loopCount++;

    // if nothing received for 10 seconds, timeout
    if(loopCount > 10000) {
      client.stop();
      return 0;
    }
  }

  respCode = client.peek();

  while(client.available())
  {
    thisByte = client.read();
  }

  if(respCode >= '4')
  {
    efail();
    return 0;
  }

  return 1;
}


void efail()
{
  byte thisByte = 0;
  int loopCount = 0;

  client.println("QUIT");

  while(!client.available()) {
    delay(1);
    loopCount++;

    // if nothing received for 10 seconds, timeout
    if(loopCount > 10000) {
      client.stop();
      return;
    }
  }

  while(client.available())
  {
    thisByte = client.read();
  }

  client.stop();
}
