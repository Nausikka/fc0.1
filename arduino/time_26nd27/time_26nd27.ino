#include <Wire.h>
#include <LiquidCrystal.h>
#include <DS3231.h>


LiquidCrystal lcd(8, 9, 4, 5,6,7);

//DS3231 rtc (SDA, SCL);
DS3231 rtc;
Time t;                                                             

int Hor;
int Min;
int Sec;

#define pmp1 26
#define pmp2 27

#define lamp1 39
#define lamp2 41

void setup() {
   lcd.begin(16, 2);
   rtc.begin();
   Wire.begin();
    Serial.begin(9600);
    Serial.print("Running:time_26and27.ino");
 
////The following lines can be uncommented to set the date and time

//  rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
//
//  rtc.setTime(15, 58, 00);     // Set the time to 12:00:00 (24hr format)
//
//  rtc.setDate(3, 2, 2018);   // Set the date to January 1st, 2014
//  
  pinMode(pmp1,OUTPUT);
  pinMode(pmp2,OUTPUT);
  // pump is off from the start
  digitalWrite(pmp1, HIGH); // HIGH means off
  digitalWrite(pmp2, HIGH);

  pinMode(lamp1,OUTPUT);
  pinMode(lamp2,OUTPUT);

  digitalWrite(lamp1, LOW);
  digitalWrite(lamp2, LOW);

}

void loop() {  
//print Date on LCD display
  lcd.setCursor(0,0);
  lcd.print("Date:");
  lcd.print(rtc.getDateStr());

  lcd.setCursor(0,1);
  lcd.print("Time: "); 
  lcd.print(rtc.getTimeStr());
  
  Serial.println();
  delay (1000);


  Hor = rtc.getHour();
  Min = rtc.getMinute();
  Sec = rtc.getSecond();

  Serial.println("Hour " +  Hor );
  Serial.println("Min " +  Min );
  Serial.println("Sec " +  Sec );
  
//switch the pump on from at 15:50 for 8 minutes
  if( Hor == 17 && (Min > 50  && Min < 55)) {
    //pump start
  digitalWrite(pmp1, LOW);
  digitalWrite(pmp2, LOW);  
  }else {
    digitalWrite(pmp1, HIGH);
    digitalWrite(pmp2, HIGH);
  }
  
 //switch the lamp on from 7:00 - 15:00
    if( Hor >= 17 && Hor < 19 ) {
      
  digitalWrite(lamp1, HIGH);
  digitalWrite(lamp2, HIGH);
    }else {
      digitalWrite(lamp1, LOW);
      digitalWrite(lamp2, LOW);
    }
}

