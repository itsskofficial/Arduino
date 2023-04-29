#include <Wire.h>
#include <Adafruit_TCS34725.h>
#define red 3
#define green 5
#define blue 6 
#define commonAnode true

byte gammaTable[256];
Adafruit_TCS34725 sensor = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Color View Test");

  if (sensor.begin())
  {
    Serial.println("RGB sensor connected");
  }
  else
  {
    Serial.println("RGB sensor not connected, please check your connections");
    while(1);
  }

  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);

  for (int i=0; i < 256; i++)
  {
    float x=i;
    x/=255;
    x=pow(x,2.5);
    x*=255;

    if (commonAnode)
    {
      gammaTable[i] = 255-x;
    }
    else
    {
      gammaTable[i]=x;
    }
    Serial.println(gammaTable[i]);
  }

}

void loop() 
{
  // put your main code here, to run repeatedly:
  uint16_t clear, r, g, b;
  sensor.setInterrupt(false);
  delay(100);
  sensor.getRawData(&r, &g, &b, &clear);
  sensor.setInterrupt(true);

  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(r);
  Serial.print("\tG:\t"); Serial.print(g);
  Serial.print("\tB:\t"); Serial.print(b);

  uint32_t sum = clear;
  float r_conv, g_conv, b_conv;
  r_conv = r; 
  r_conv /= sum;
  g_conv = g; 
  g_conv /= sum;
  b_conv = b; 
  b_conv /= sum;
  r_conv *= 256; 
  g_conv *= 256; 
  b_conv *= 256;
  
  Serial.print("\t");
  Serial.print((int)r_conv, HEX); 
  Serial.print((int)g_conv, HEX); 
  Serial.print((int)b_conv, HEX);
  Serial.println();

  analogWrite(red, gammaTable[(int)r_conv]);
  analogWrite(green, gammaTable[(int)g_conv]);
  analogWrite(blue, gammaTable[(int)b_conv]);

}
