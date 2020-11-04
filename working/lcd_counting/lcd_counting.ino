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
  for (int i = 0; i < 20; i++) // smyčka pro počítání
  {
    lcd.setCursor(0,0); // nastaví kurzor na 1/1
    lcd.print("I did that shit!");       // print text
    lcd.setCursor(7,1); // nastaví kurzor na 8 znak a 2.řádek
    lcd.print(i);       // zobrazí číslo z proměné i
    delay(100);         // čeká 100ms
  }
 
  lcd.setCursor(0,0); // nastaví kurzor na 5/1
  lcd.print("                ");   // wipe 16 chars
  delay(400);
  lcd.setCursor(0,0); // nastaví kurzor na 5/1
  lcd.print("Thats's all!  <3");       // print text
  delay(400);
  lcd.setCursor(7,1); // nastaví kurzor na 8 znak a 2.řádek
  lcd.print("   ");   // vymaže prostor po trojmístém číslu
  delay(800);         // delay
}
