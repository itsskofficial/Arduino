#include <DHT.h>
#define DHTPIN 12
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test");
  dht.begin();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  delay(3000);
  float h = dht.readHumidity();
  float t_c = dht.readTemperature();
  float t_f = dht.readTemperature(true);

  if (isnan(h) || isnan(t_c) || isnan(t_f))
  {
    Serial.println("Failed to read from the DHT sensor, check your connections again");
    return;
  }

  float heatIndex_f = dht.computeHeatIndex(t_f, h);
  float heatIndex_c = dht.computeHeatIndex(t_c, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t_c);
  Serial.print(" *C ");
  Serial.print(t_f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(heatIndex_c);
  Serial.print(" *C ");
  Serial.print(heatIndex_f);
  Serial.println(" *F");
}
