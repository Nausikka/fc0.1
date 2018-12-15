#include <ThingSpeak.h>
#include <DHT_U.h>
#include <DHT.h>
#include <Wire.h>

#include <ESP8266WiFi.h>
 
// replace with your channel's thingspeak API key,
String apiKey = "MRP97SSATI289GY8";
String readAPIKey = "IMSWZX7BOCRP64UM";


const char* HapiKey = "DYN8PSFKKBOZN9LA";
const char* HreadAPIKey = "IMSWZX7BOCRP64UM";

unsigned long HchannelID = 483297;
unsigned int HdataFieldOne = 1;
unsigned int HdataFieldTwo = 2;

// replace with your wifi ssid and wpa2 key
const char *ssid =  "Makespace";
const char *pass =  "getexc1tedandmaketh1ngs";
float aConst;

unsigned long channelID = 483256;
unsigned int dataFieldOne = 1;
unsigned int dataFieldTwo = 2;

int red = 12;
int blue = 14;


const char* server = "api.thingspeak.com";
#define DHTPIN 2 // pin where the dht22 is connected
 
DHT dht(DHTPIN, DHT22,15);

WiFiClient client;
 
void setup() {
  Serial.begin(115200);
  delay(10);
  dht.begin();

  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
}
 
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (client.connect(server,80)) {  //   "184.106.153.149" or api.thingspeak.com
    String postStr = apiKey;
           postStr +="&field1=";
           postStr += String(t);
           postStr +="&field2=";
           postStr += String(h);
           postStr += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");
     client.print("Connection: close\n");
     client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
     client.print("Content-Type: application/x-www-form-urlencoded\n");
     client.print("Content-Length: ");
     client.print(postStr.length());
     client.print("\n\n");
     client.print(postStr);     

     Serial.println(t);
     Serial.println(h);

//float temperatureInC = ThingSpeak.readFloatField(HchannelID, HdataFieldOne, HreadAPIKey);
//float humidityPerc = ThingSpeak.readFloatField(HchannelID, HdataFieldTwo, HreadAPIKey);

     //Serial.println(temperatureInC);
     //Serial.println(humidityPerc);
 
      if (t < 26) {
      digitalWrite(red, HIGH);
      digitalWrite(blue, LOW);
      Serial.print("less than 25");
      
     }
     if (t >= 27) {
      digitalWrite(blue,HIGH);
      digitalWrite(red, LOW);
      Serial.print("more than 28");
     }     
  
  }
  
  client.stop();
 
  Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(15000);
}


