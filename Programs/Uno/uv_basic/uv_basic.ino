void setup() 
{ 
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.print(sensorValue);
  Serial.print(',');
  float uvIndex = voltage / 0.1;
  Serial.println(uvIndex);
  delay(1000);
}
