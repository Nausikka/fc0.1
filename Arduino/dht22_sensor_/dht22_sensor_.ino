#include <DHT.h> //cargamos la librera DHT

#define DHTPIN D3     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE); 
 
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
 
void setup(){
  Serial.begin(9600);
}
 
void loop()
{
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  Serial.print("Temperature = ");
  Serial.println(temp);
  Serial.print("Humidity = ");
  Serial.println(hum);
  delay(1000);
}
