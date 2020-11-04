#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// vytvoří objekt lcd a nastaví jeho adresu
// 0x20 a 16 zanků na 2 řádcích
//LiquidCrystal_I2C lcd(0x20,16,2);  
LiquidCrystal_I2C lcd(0x27,16,2);  

 
void setup()
{
  lcd.init();// inicializuje displej
  lcd.backlight(); // zapne podsvětlení
 
}
 
void loop()
{
  for (int i = 0; i < 500; i++) // smyčka pro počítání
  {
    lcd.setCursor(7,1); // nastaví kurzor na 8 znak a 2.řádek
    lcd.print(i);       // zobrazí číslo z proměné i
    delay(100);         // čeká 100ms
  }
 
  lcd.setCursor(7,1); // nastaví kurzor na 8 znak a 2.řádek
  lcd.print("   ");   // vymaže prostor po trojmístém číslu
                      // jinak řečeno přepíše číslo mezerami
}
