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


#define lamp1 39
#define lamp2 41


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  rtc.begin();
  Serial.print("Running:lamp_pump_jan_27.ino");


  ////The following lines can be uncommented to set the date and time

//  rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY
//
//  rtc.setTime(20, 19, 00);     // Set the time to 12:00:00 (24hr format)
//
//  rtc.setDate(27, 1, 2018);   // Set the date to January 1st, 2014
  //set pin for the pump
  pinMode(pmp1,OUTPUT);
  pinMode(pmp2,OUTPUT);

//pump is off from the start
//digitalWrite(pmp1,HIGH);
//digitalWrite(pmp2,HIGH);

//set pin for the lamp
  pinMode(lamp1,OUTPUT);
  pinMode(lamp2,OUTPUT);

//lamp is off from the start
  digitalWrite(lamp1,LOW);
  digitalWrite(lamp2,LOW);

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
 if( Hor == 8 && Min == 19 ) //Comparing the current time with the Alarm time

      {
      
      Pump();
      }else {      
//swithch the pump off again when the time pass  
      digitalWrite(pmp1,HIGH);
      digitalWrite(pmp2,HIGH);
      
  }

  if( Hor >= 19 && Hor < 21) //Comparing the current time with the Alarm time

      {
      lcd.clear();
      
      lcd.print("Svieti");
      
      lcd.setCursor(0,1);
      
      lcd.print("Svieti: ");
      lcd.print(millis() / 1000);
      
      Lamp();
      }else {      
//swithch the lamp off again when the time pass  
      digitalWrite(lamp1,LOW);
      digitalWrite(lamp2,LOW);
      
  }
}

void Pump() {
  digitalWrite(pmp1,LOW);
  digitalWrite(pmp2,LOW);

}

void Lamp(){

digitalWrite(lamp1, HIGH);
digitalWrite(lamp2, HIGH);
}


