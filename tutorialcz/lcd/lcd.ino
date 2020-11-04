#include <LiquidCrystal_I2C.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// vytvoří objekt lcd a nastaví jeho adresu
// 0x20 a 16 zanků na 2 řádcích
LiquidCrystal_I2C lcd(0x20,16,2);  
 
void setup()
{
  lcd.begin();// inicializuje displej
   
  lcd.backlight(); // zapne podsvětlení
  lcd.print("Ahoj lidi..."); // vypíše text
}
 
void loop()
{
}
