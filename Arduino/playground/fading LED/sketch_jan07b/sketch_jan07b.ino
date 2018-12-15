
int LED = 9;

void setup() {
  // put your setup code here, to run once:
pinMode (LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    for (int i = 0; i < 256; i++){
    analogWrite(LED, i);
    delay(50);
    }
    for (int i = 255; i < 0; i--){
    analogWrite(LED, i);
    delay(50);
    }
}
