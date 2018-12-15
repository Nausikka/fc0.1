int redLED = 9; 
int greenLED = 10;
int blueLED = 11;
void setup() {
  // Declare the pins for the LED as Output
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}
// A simple function to set the level for each color from 0 to 255
void setColor(int redValue, int greenValue, int blueValue){
  analogWrite(redLED, 255 - redValue);
  analogWrite(greenLED, 255 - greenValue);
  analogWrite(blueLED, 255 - blueValue);
}
void loop(){
  // Change a few colors
  setColor(255, 0, 0);
 // Red Color
  delay(500);
  setColor(0, 255, 0); 
// Green Color
  delay(500);
  setColor(0, 0, 255); // Blue Color
  delay(500);
  setColor(255, 255, 0); 
// Yellow
  delay(500);
  setColor(0, 255, 255);
 // Cyan
  delay(500);
  setColor(255, 0, 255); 
// Magenta
  delay(500);
  setColor(255, 255, 255);
 // White
  delay(500);
}
