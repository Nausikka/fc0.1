#include "UbidotsMicroESP8266.h"
#define TOKEN  "BBFF-ITD2IL1WkfhFmrQ9kjqOlZP4Enck5O"  // Put here your Ubidots TOKEN
#define WIFISSID "VM5318725"
#define PASSWORD "c4hkQfmsvpph"

Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    delay(10);
    client.wifiConnection(WIFISSID, PASSWORD);
}
void loop(){
    float value = analogRead(A0);
    client.add("Temperature", value);
    client.sendAll(true);
}

