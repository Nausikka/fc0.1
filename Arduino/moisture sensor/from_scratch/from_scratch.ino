  int inPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);

  pinMode(inPin, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  analogRead (inPin);
  Serial.print(inPin);
  Serial.println();
  delay(1000);

}
