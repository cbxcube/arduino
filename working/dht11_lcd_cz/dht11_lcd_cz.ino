#include  <LiquidCrystal.h>    //importuje knihovnu LiquidCrystal
#include <dht11.h>             // importuje naši novou knihovnu DHT11

// !!! Upozornění !!! 
// Vzhledem k tomu, že čidlo je napojeno na pin 0, který slouží 
// při programování ke komunikaci, odpojete propojovací vodič 
// z pin 0 vedoucí do DHT11 při nahrávání programu do Arduina. 
// V opačném případě počítač při programování ukáže chybovou 
// hlášku. Toto platí i pro Arduino UNO. Další možností je 
// připojit datový vývod z DHT11 k jinému pinu např. 10 a upravit
// program. 


// Více zde: https://arduino8.webnode.cz/news/lekce-6-cidlo-dht11-teplota-vlhkost/


// inicializuje lcd s definicí připojení na piny.
// MojeLCD1(RS,Enable, D4, D5, D6, D7)
LiquidCrystal MojeLCD1(2,3,4,5,6,7);
 
//vytvoří objekt DHT11 s názvem MojeCidlo
dht11 MojeCidlo; //
 
void setup() {
  // nastaví typ displeje na 20 znaků a 4 řádky (upravte dle sebe)
  MojeLCD1.begin(20, 4);
 
  MojeLCD1.print("arduino8.webnode.cz"); // napíše text "arduino8.we...
 
}
 
void loop() {
 
  MojeCidlo.read(0); // přečte údaje z čidla DTH11 připojeného na pin 0
  int hodnota = MojeCidlo.temperature;  // přečte hodnotu z A0
  int vlhkost = MojeCidlo.humidity;    
  MojeLCD1.setCursor(0,2);          // nastaví kurzor na třetí řádek a první znak
  MojeLCD1.print("t = ");           // napíše text t =
  MojeLCD1.print(hodnota);          // napíše hodnotu teploty
  MojeLCD1.print(" oC");              // napíše oC
 
  MojeLCD1.setCursor(0,3);          // nastaví kurzor na čtvrtý řádek a první znak
  MojeLCD1.print("v = ");           // napíše text v =
  MojeLCD1.print(vlhkost);          // napíše hodnotu teploty
  MojeLCD1.print(" %   ");          // napíše %
   
  delay(1000);                       // čekej 1000ms                    
}
