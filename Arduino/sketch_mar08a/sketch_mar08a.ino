#include <Adafruit_RGBLCDShield.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <DS3231.h>

LiquidCrystal lcd(8, 9, 4, 5,6,7);


DS3231 rtc (SDA, SCL);

Time t;                                                             

int Hor;
int Min;
int Sec;



#define pmp1 26
#define pmp2 27

#define air 3
#define lamp 2


void setup() {
  // put your setup code here, to run once:
pinMode(pmp1,OUTPUT);
  pinMode(pmp2,OUTPUT);

  pinMode(air,OUTPUT);
  pinMode(lamp,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pmp1,HIGH);
digitalWrite(pmp2,HIGH);


digitalWrite(air,LOW);
digitalWrite(lamp,LOW);







}
