// Ultrazvukový modul HY-SRF05 pro měření vzdálenosti

// load library for ultrasound
#include <NewPing.h>
// load library for lcd 16x2 i2c
#include <LiquidCrystal_I2C.h>

// nastavení propojovacích pinů - ultrazvuk
#define pinTrigger    3
#define pinEcho       4
#define maxVzdalenost 450

// inicializace měřícího modulu ultrazvuku z knihovny
NewPing sonar(pinTrigger, pinEcho, maxVzdalenost);
// inicializace displaya na I2C adrese 0x27
// 0x27 and 16 characters in 2 lines
LiquidCrystal_I2C lcd(0x27,16,2);  

void setup() {
  // zahájení komunikace po sériové lince
  Serial.begin(9600);
  // inicializacia displaya
  lcd.init();// initialise display
  lcd.backlight(); // backlight on
}

void loop() {
  // načtení vzdálenosti v centimetrech do vytvořené proměnné vzdalenost
  int vzdalenost = sonar.ping_cm();
  // pauza před dalším měřením
  delay(50);
  // pokud byla detekována vzdálenost větší než 0,
  // provedeme další měření
  if (vzdalenost > 0) {
    vzdalenost = 0;
    // pro získání stabilnějších výsledků provedeme 5 měření
    // a výsledky budeme přičítat do proměnné vzdalenost
    for (int i = 0; i < 5; i++) {
      vzdalenost += sonar.ping_cm();
      delay(50);
    }
    // v proměnné vzdálenost máme součet posledních 5 měření
    // a musíme tedy provést dělení 5 pro získání průměru
    vzdalenost = vzdalenost / 5;
    // vytištění informací po sériové lince
    Serial.print("Vzdalenost mezi senzorem a predmetem je ");
    Serial.print(vzdalenost);
    Serial.println(" cm.");
    // print na display
    lcd.setCursor(0,0);
    lcd.print("Vzdialenost je:");
    // lcd.setCursor(11,0);
    // lcd.print(temperatureF);
    lcd.setCursor(0,1);
    lcd.print(vzdalenost);
    lcd.println(" cm."            );
    // lcd.setCursor(11,1);
    // lcd.print(temperatureC);
  }
  // pokud byla detekována vzdálenost 0, je předmět mimo měřící rozsah,
  // tedy příliš blízko nebo naopak daleko
  else {
    Serial.println("Vzdalenost mezi senzorem a predmetem je mimo merici rozsah.");
    lcd.setCursor(0,0);
    lcd.print(" Predmet mimo   ");
    lcd.setCursor(0,1);
    lcd.print(" meraci rozsah !");
    delay(500);
    
  }
}
