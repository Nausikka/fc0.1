int sensor_pin = A0; 
int output_value ;

void setup() {
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);

//  pinMode(4, OUTPUT);
//  pinMode(5, OUTPUT);
  }

void loop() {

  output_value= analogRead(sensor_pin);
  Serial.print("Mositure : ");
  Serial.print(output_value);
  Serial.println();
  delay(1000);

  if(output_value>500) {
    digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(5, HIGH);
    delay(5000);
    digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(5, LOW);
    Serial.print("Water meee!");
}else {
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  Serial.print("No need to water, I am wet ;)");
  Serial.println("%");
  }
}




