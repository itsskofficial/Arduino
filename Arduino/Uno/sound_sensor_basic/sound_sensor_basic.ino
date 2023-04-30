int currentValue;
int maxValue;
int minValue;
unsigned long timer;
int sampleSpan = 200;
int volume;
int ledPin = 4;
int sensorGroundPin = 8;

void resetValues()
{
  maxValue = 0;
  minValue = 1024;
  timer = millis();
}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  resetValues();
  digitalWrite(sensorGroundPin, LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  currentValue = analogRead(A0);
  if (currentValue < minValue)
  {
    minValue = currentValue;
  }
  if (currentValue > maxValue)
  {
    maxValue = currentValue;
  }
  if ((millis() - timer) >= sampleSpan)
  {
    volume = maxValue - minValue;
    Serial.println(volume);
    resetValues();
  }
  if(volume > 400)
  {
    Serial.println("Loud");
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    Serial.println("Quiet");
    digitalWrite(ledPin, LOW);
  }

  delay(300);
}
