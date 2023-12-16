#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 sensor = Adafruit_BMP280();
Adafruit_BMP280_Temp temp_sensor = Adafruit_BMP280_Temp(&sensor);

void displaySensorDetails(void)
{
  sensor_t bmp;
  temp_sensor.getSensor(&bmp);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); 
  Serial.println(bmp.name);
  Serial.print  ("Driver Version:   "); 
  Serial.println(bmp.version);
  Serial.print  ("Unique ID:    "); 
  Serial.println(bmp.sensor_id);
  Serial.print  ("Max Value:    "); 
  Serial.print(bmp.max_value); 
  Serial.println(" hPa");
  Serial.print  ("Min Value:    "); 
  Serial.print(bmp.min_value); 
  Serial.println(" hPa");
  Serial.print  ("Resolution:   "); 
  Serial.print(bmp.resolution); 
  Serial.println(" hPa");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("BMP280 Test");
  Serial.println("Starting the sensor...");
  sensor.begin();

  if(!sensor.begin())
  {
    Serial.println("BMP280 not found, please check your connections");
    while(1);
  }

  Serial.println("Started the sensor");
  //displaySensorDetails();
}

void loop() 
{
  // put your main code here, to run repeatedly
    float pressure = sensor.readPressure();
    Serial.print("Pressure:    ");
    Serial.print(pressure);
    Serial.println(" hPa");

    float t_c = sensor.readTemperature();
    Serial.print("Temperature: ");
    Serial.print(t_c);
    Serial.println(" *C");

    float altitude=sensor.readAltitude();
    Serial.print("Altitude: ");
    Serial.print(altitude);
    Serial.println(" m");
    Serial.println();

    delay(2000);
}
