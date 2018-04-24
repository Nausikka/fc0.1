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

#define fan 27
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
//  rtc.setTime(21, 13, 00);     // Set the time to 12:00:00 (24hr format)
//
//  rtc.setDate(10, 4, 2018);   // Set the date to January 1st, 2014
//

//set pin for the pump, air pump and the lamp
  pinMode(fan,OUTPUT);
  pinMode(water,OUTPUT);
  pinMode(air,OUTPUT);
  pinMode(lamp,OUTPUT);

//all devices are off from the start
  digitalWrite(fan,HIGH);
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

 //set time for fan: twice per day for 2 minute
 if( (Hor == 11 || Hor == 15 || Hor== 18) && (Min >  2 && Min < 5)) //Comparing the current time with the Alarm time
      {
       digitalWrite(fan,LOW);
      }else {      
      digitalWrite(fan,HIGH);         
      }
  
  //set time for water: once per day for 1 minute
 if( (Hor == 8) && (Min >  2 && Min < 5)) //Comparing the current time with the Alarm time
      {
       digitalWrite(water,LOW);
      }else {      
      digitalWrite(water,HIGH);         
      }

//set time for the air: 3x per day for 10min

  if( (Hor == 18 || Hor==14 || Hor == 7) &&  (Min > 0  && Min < 5) ) 
      {
      digitalWrite(air, LOW);
      }else {      
      digitalWrite(air,HIGH);
      }

//set time for the lamp: continuously from 7am-6pm
if(  Hor >= 7 && Hor <= 19 ) 
      {
      digitalWrite(lamp, LOW);
      }else {      
      digitalWrite(lamp, HIGH);   
      }
}

