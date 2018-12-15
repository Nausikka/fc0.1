#include <Wire.h>
#include <LiquidCrystal.h>
#//include <DS3231.h>
#include <DS3232RTC.h>

LiquidCrystal lcd(8,9,4,5,6,7);

DS3231 rtc (SDA, SCL);

Time t;

int Hor;
int Min;
int Sec;

#define pmp1 53
#define pmp2 51

void setup() {

  lcd.begin(16,2);     
  rtc.begin();

//set pin for the pump
  pinMode(pmp1,OUTPUT);
  pinMode(pmp2,OUTPUT);

//pump is off from the start
  digitalWrite(pmp1,HIGH);
  digitalWrite(pmp2,HIGH);
  
  Wire.begin();
  Serial.begin(9600);
  
// The following lines can be uncommented to set the date and time

//  rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
//
//  rtc.setTime(21, 44, 00);     // Set the time to 12:00:00 (24hr format)
//
//  rtc.setDate(28, 10, 2017);   // Set the date to January 1st, 2014


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
 if( Hor == 21 &&  (Min == 46 || Min == 47) && (Sec > 50)) //Comparing the current time with the Alarm time

      {
      lcd.clear();
      
      lcd.print("Water");
      
      lcd.setCursor(0,1);
      
      lcd.print("Watering: ");
      lcd.print(millis() / 1000);
      
      Pump();
      }else {      
//swithch the pump off again when the time pass  
      digitalWrite(pmp1,HIGH);
      digitalWrite(pmp2,HIGH);
      
      }
}
//switching ON and OFF the pump in half second intervals

void Pump()
{

digitalWrite(pmp1,HIGH);
digitalWrite(pmp2,HIGH);

delay(500);

digitalWrite(pmp1, LOW);
digitalWrite(pmp2, LOW);

delay(500);
}
