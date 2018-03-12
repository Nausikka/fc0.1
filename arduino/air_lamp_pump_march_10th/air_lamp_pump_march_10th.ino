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

#define water 26
#define lamp 39
#define air 41


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  rtc.begin();



  ////The following lines can be uncommented to set the date and time

//  rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
//
//  rtc.setTime(7, 11, 00);     // Set the time to 12:00:00 (24hr format)
//
//  rtc.setDate(8, 3, 2018);   // Set the date to January 1st, 2014
//

//set pin for the pump, air pump and the lamp
  
  pinMode(water,OUTPUT);
  pinMode(air,OUTPUT);
  pinMode(lamp,OUTPUT);

//all devices are off from the start
  digitalWrite(water,HIGH);
  digitalWrite(air,HIGH);
  digitalWrite(lamp,HIGH);

  Wire.begin();
  Serial.begin(9600);
}

void loop() {

  
  //print on Serial monitor script which is running
  lcd.setCursor(0,0);
  Serial.print("lamp_pump_march_10.ino");
  delay (5000);
  
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
 if( (Hor == 8) && (Min >  10 && Min < 12)) //Comparing the current time with the Alarm time
      {
       digitalWrite(water,LOW);
      }else {      
      digitalWrite(water,HIGH);         
      }

//set time for the air

  if( (Hor == 19 || Hor==14 || Hor == 8) &&  (Min > 0  && Min < 10) ) 
      {
      digitalWrite(air, LOW);
      }else {      
      digitalWrite(air,HIGH);
      }

//set time for the lamp
if(  Hor >= 7 && Hor < 18 ) 
      {
      digitalWrite(lamp, LOW);
      }else {      
      digitalWrite(lamp, HIGH);   
      }
}

