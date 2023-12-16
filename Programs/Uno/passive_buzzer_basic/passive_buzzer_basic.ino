const int buzzerPin = 8;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  tone(buzzerPin, 10000);
  delay(1000);
  noTone(buzzerPin);
  delay(1000);
  tone(buzzerPin, 10000);
  delay(1000);
  noTone(buzzerPin);
  delay(1000);
  tone(buzzerPin, 10000);
  delay(1000);
  noTone(buzzerPin);
  delay(1000);
}
