// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("LCD Key Shield");
  lcd.setCursor(0,1);
  lcd.print("Press Key:");
  delay(1000);
}

void loop() 
{
  int x;
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
  x = analogRead(A0);
  lcd.setCursor(0,0);

  if (x < 60) 
  {
    lcd.print ("Right");
  }
  else if (x < 200) 
  {
    lcd.print ("Up");
  }
  else if (x < 400)
  {
    lcd.print ("Down");
  }
  else if (x < 600)
  {
    lcd.print ("Left");
  }
  else if (x < 800)
  {
    lcd.print ("Select");
  }

  delay(100);
}