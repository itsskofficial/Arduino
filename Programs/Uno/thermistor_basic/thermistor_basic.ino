#include <thermistor.h>
#define RESISTOR 950
#define THERMISTORPIN A2

THERMISTOR thermistor(THERMISTORPIN, 1000, 3950, 1000);
uint16_t temperature;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  float thermistor_value;
  thermistor_value = analogRead(THERMISTORPIN);

  Serial.print("Analog Reading: ");
  Serial.println(thermistor_value);

  thermistor_value = (1023 / thermistor_value) - 1;
  thermistor_value = RESISTOR / thermistor_value;
  Serial.print("Thermistor Resistance: ");
  Serial.println(thermistor_value);

  temperature = thermistor.read();
  Serial.print("Temperature (*C): ");
  Serial.println(temperature);

  delay(2000);
}
