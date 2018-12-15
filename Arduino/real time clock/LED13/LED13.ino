#include <config.h>
#include <ds3231.h>


void setup() {
  pinMode (13,OUTPUT);

}

void loop() {
  switch (clock.dayOfWeek)
  {
    case MON: //on Monday
      switch (clock.hour)
      {
        case 14: //at 2 o'clock
          switch (clock.minute)
          {
            case 30: //at 30 minutes
              switch (clock.second)
              {
                case 1: //at 1 second
                  digitalWrite(13, HIGH);   // turn the Relay on (HIGH is the voltage level)
                  delay(5000);              // wait for 5 seconds
                  digitalWrite(13, LOW);    // turn the Relay off by making the voltage LOW
                  delay(5000);              // wait for 5 seconds
              }
          }
      }
  }

}
