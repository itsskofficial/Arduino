int buttonState=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(4,INPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(4);
  if (buttonState == HIGH) 
  {
    Serial.println("HIGH");
    digitalWrite(8,HIGH);
  }
  else
  {
    Serial.println("LOW");  
    digitalWrite(8,LOW);
  }
}
