#include <Wire.h>
#include <Adafruit_MCP9808.h>

Adafruit_MCP9808 sensor = Adafruit_MCP9808();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("MCP9808 Test");

  if (!sensor.begin())
  {
    Serial.println("MCP9808 sensor not found, please check your connections");
    while(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  float t_c = sensor.readTempC();
  float t_f = sensor.readTempF();
  Serial.print("Temperature: ");
  Serial.print(t_c);
  Serial.print(" *C\t");
  Serial.print(t_f);
  Serial.println(" *F");
  delay(1000);

  Serial.println("Shutting down the sensor...");
  sensor.shutdown_wake(1);  
  delay(2000);
  Serial.println("Waking up the sensor...");
  sensor.shutdown_wake(0);
}
