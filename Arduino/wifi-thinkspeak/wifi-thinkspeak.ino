#include <ThingSpeak.h>

/* DEVELOPER: hernando Bolanos - Colaborations - original code and libraries for wifi modules and code uploaded in GITHUB for send information to Thinhspeak-Libraries according to each author
 *  
 *  This code send to  Thingspeak DHT22 data each 20 seconds -using wifi 
 *  This program do not use arduino just use the GPIO2 to receive DHT22 sensor information and demux it. How to load directly to de esp8266 from arduino IDE is a chellenge- take a look to the "el profe garcia videos on youtube"
 */
#include <DHT.h> //cargamos la librera DHT
#define DHTPIN D3 //Seleccionamos el pin en el que se conectar el sensor
#define DHTTYPE DHT22 //Se selecciona el DHT22(hay otros DHT)
DHT dht(DHTPIN, DHTTYPE); //Se inicia una variable que ser usada por Arduino para comunicarse con el sensor
#include <ESP8266WiFi.h>

unsigned long myChannelNumber = 167319;
const char * myWriteAPIKey = "MRP97SSATI289GY8";

const char* ssid = "VM5318725";
const char* password = "c4hkQfmsvpph";

 WiFiClient  client;
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
   dht.begin(); //Se inicia el sensor
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  
  // Start the server
 // server.begin();
 // Serial.println("Server started");
  // Print the IP address
  Serial.println(WiFi.localIP());

ThingSpeak.begin(client);
   
}

void loop() {

float h = dht.readHumidity(); //Se lee la humedad
  float t = dht.readTemperature(); //Se lee la temperatura
  //Se imprimen las variables
  Serial.println("Humedad: "); 
  Serial.println(h);
  Serial.println("Temperatura: ");
  Serial.println(t);
  delay(2000); //Se espera 2 segundos para seguir leyendo //datos
 
ThingSpeak.writeField(myChannelNumber, 1, h, myWriteAPIKey);
  delay(20000); 
  
ThingSpeak.writeField(myChannelNumber, 2, t, myWriteAPIKey);
  delay(20000); 
  }
