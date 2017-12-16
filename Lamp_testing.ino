
#include <Wire.h>

#define in1 39
#define in2 41

void setup() {

//set pin for the pump
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);

//pump is off from the start
  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);

  Wire.begin();
  Serial.begin(9600);
}

 void loop(){

digitalWrite(in1,HIGH);
digitalWrite(in2,HIGH);

delay(1500);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);

delay(1500);
}
