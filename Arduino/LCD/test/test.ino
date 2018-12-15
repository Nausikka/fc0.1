#include <LiquidCrystal.h>

//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(7, 8, 5, 4, 3, 2);

void setup() {
    lcd.begin(16,1);
    lcd.print("h");
    
}

void loop() {
    lcd.setCursor(0,1);
    lcd.print("it works");        
  
}
