#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define sensorPin A0
// create object and set his address
// 0x27 and 16 characters in 2 lines
LiquidCrystal_I2C lcd(0x27,16,2);  

 
void setup()
{
  lcd.init();// initialise display
  lcd.backlight(); // backlight on
 
}

void loop()
{
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
  voltage /=1024.0;
// fixing math
// float temperatureC = (voltage - 0.5) * 100;
  float temperatureC = (voltage - 0.5) * 10;
  float temperatureF = (temperatureC * 9.0 / 5.0) +32.0;

  lcd.setCursor(0,0);
  lcd.print("Temp in F:");
  lcd.setCursor(11,0);
  lcd.print(temperatureF);

  lcd.setCursor(0,1);
  lcd.print("Temp in C:");
  lcd.setCursor(11,1);
  lcd.print(temperatureC);

  delay(2000);  
}
