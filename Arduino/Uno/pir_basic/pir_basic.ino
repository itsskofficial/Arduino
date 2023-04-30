int ledPin = 4;
int sensorPin = 3;
int pirState = LOW;
int pinStatus = 0;
int calibrationTime = 30;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  Serial.println("Waiting for the sensor to warm up...");
  delay(calibrationTime * 1000);
  Serial.println("Sensor active");
}

void loop() {
  // put your main code here, to run repeatedly:
  pinStatus = digitalRead(sensorPin);
  Serial.println(pinStatus);
  if (pinStatus == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    if (pirState == LOW)
    {
      Serial.println("Motion detected");
      pirState = HIGH;
    }
  }
  else
  {
    digitalWrite(ledPin, LOW);
    if (pirState == HIGH)
    {
      Serial.println("Motion ended");
      pirState = LOW;
    }
  }

  delay(1000);
}
