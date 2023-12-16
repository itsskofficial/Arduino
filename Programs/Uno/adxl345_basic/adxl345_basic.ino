#include <Adafruit_ADXL345_U.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>

Adafruit_ADXL345_Unified sensor = Adafruit_ADXL345_Unified();

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!sensor.begin())
  {
    Serial.println("ADXL345 not found, please check your connections");
    while(1);
  }
  else
  {
    Serial.println("Sensor started");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors_event_t event;
  sensor.getEvent(&event);
  Serial.print("X acceleration: ");
  Serial.print(event.acceleration.x);
  Serial.print("\tY acceleration: ");
  Serial.print(event.acceleration.y);
  Serial.print("\tZ acceleration: ");
  Serial.println(event.acceleration.z);
  delay(1000);
}
