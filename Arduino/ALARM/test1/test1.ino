#include <LiquidCrystal.h>
//#include <Wire.h>
#include <DS3231.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DS3231 rtc (SDA, SCL);


void setup() {

  lcd.begin(16,2);     
  rtc.begin();
  
  
//  Wire.begin();
  Serial.begin(9600);
  
  // The following lines can be uncommented to set the date and time

//  rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
//
//  rtc.setTime(17, 05, 50);     // Set the time to 12:00:00 (24hr format)
//
//  rtc.setDate(30, 9, 2017);   // Set the date to January 1st, 2014


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


// if( Hor == 11 &&  (Min == 32 || Min == 33)) //Comparing the current time with the Alarm time
//
//      {
//      
//      Buzzer();
//      
//      Buzzer();
//      
//      lcd.clear();
//      
//      lcd.print("Alarm ON");
//      
//      lcd.setCursor(0,1);
//      
//      lcd.print("Alarming");
//      
//      Buzzer();
//      
//      Buzzer();
//      
//      }
}

//void Buzzer()
//
//{
//
//digitalWrite(buz,HIGH);
//
//delay(500);
//
//digitalWrite(buz, LOW);
//
//delay(500);
//
//}
