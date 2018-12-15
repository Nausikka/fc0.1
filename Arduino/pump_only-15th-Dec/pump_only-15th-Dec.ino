#include <DS3231.h> //Download the library form http://www.rinkydinkelectronics.com/library.php?id=73
#include <Wire.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(8,9,4,5,6,7);

DS3231 rtc (SDA, SCL);

Time t;

int Hor;
int Min;
int Sec;

#define pmp1 26
#define pmp2 27

#define lamp1 39
#define lamp2 41

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
//  rtc.setTime(16, 00, 00);     // Set the time to 12:00:00 (24hr format)
//
//  rtc.setDate(15, 12, 2018);   // Set the date to January 1st, 2014


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
 if( Hor == 16 &&  (Min == 9 || Min == 10) ) //Comparing the current time with the Alarm time

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
