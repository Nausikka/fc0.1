
int i=1;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {  
        
      digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(400);      
      digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(5, LOW);
      delay(1000);   
      digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(400);    
      digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(5, LOW);
      delay(1000);     
      digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(400);      
      digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
      digitalWrite(5, LOW);
      delay(1000);   

}
