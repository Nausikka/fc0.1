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

#define pmp_air 39
#define lamp 37


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  rtc.begin();
  Serial.print("Running:lamp_pump_feb_24.ino");


  ////The following lines can be uncommented to set the date and time

//  rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
//
//  rtc.setTime(8, 57, 00);     // Set the time to 12:00:00 (24hr format)
//
//  rtc.setDate(3, 3, 2018);   // Set the date to January 1st, 2014

//set pin for the air pump   
  pinMode(pmp_air,OUTPUT);
  digitalWrite(pmp_air,LOW);


//set pin for the lamp   
pinMode(lamp,OUTPUT);  
digitalWrite(lamp,LOW);

  Wire.begin();
  Serial.begin(9600);

}

void loop() {
   //print on Serial monitor  
  Serial.print("Date: ");
  Serial.print(rtc.getDOWStr());
  
//print date on Serial monitor
  Serial.print(" ");
  Serial.print(rtc.getDateStr());
  Serial.println();
  
//print time on Serial monitor
  Serial.print("Time: ");
  Serial.print(rtc.getTimeStr());

  
//print Date on LCD display
  lcd.setCursor(0,0);
  lcd.print("Date:");
  lcd.print(rtc.getDateStr());

  lcd.setCursor(0,1);
  lcd.print("Time: "); 
  lcd.print(rtc.getTimeStr());
  
  Serial.println();
  delay (1000);

  t = rtc.getTime();

  Hor = t.hour;
  Min = t.min;
  Sec = t.sec;

}
