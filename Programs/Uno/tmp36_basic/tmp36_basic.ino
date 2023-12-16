int tmpPin = 0;
float supply_voltage = 5;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int tmpReading = analogRead(tmpPin);
  float voltage = tmpReading * supply_voltage / 1024;
  Serial.print(voltage);
  Serial.println(" volts");

  float t_c =  (voltage - 0.5) * 100;
  Serial.print(t_c);
  Serial.println(" *C");

  float t_f = (t_c * 9.0 / 5.0) + 32.0;
  Serial.print(t_f);
  Serial.println(" *F");
  delay(1000);
}  