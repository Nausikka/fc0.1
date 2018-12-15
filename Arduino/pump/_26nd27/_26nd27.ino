#define pmp1 26
#define pmp2 27



void setup() {
  // put your setup code here, to run once:
//set pin for the pump
  pinMode(pmp1,OUTPUT);
  pinMode(pmp2,OUTPUT);

//pump is off from the start
  digitalWrite(pmp1,LOW);
  digitalWrite(pmp2,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pmp1,LOW);
  digitalWrite(pmp2,LOW);

  delay (5000);

  digitalWrite(pmp1,HIGH);
  digitalWrite(pmp2,HIGH);

  delay (5000);

}
