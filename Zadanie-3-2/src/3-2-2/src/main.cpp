#include <Arduino.h>

#define BUTTON 2

int stanPrzycisku;
int poprzedniStanPrzycisku = LOW;
unsigned long poprzedniCzas = 0;
unsigned int liczba_nacisniec = 0;
unsigned long czas;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
}

void loop() {
  int odczyt = digitalRead(BUTTON);
  //Serial.println(odczyt);
  
  if (odczyt != poprzedniStanPrzycisku) {
    czas = poprzedniCzas = millis();
  }
  
  if (czas > 50) {
    if (odczyt != stanPrzycisku){
      stanPrzycisku = odczyt;
      if(stanPrzycisku == HIGH){
    //Serial.println(millis() - poprzedniCzas);
		liczba_nacisniec++;
        Serial.println("Liczba nacisniec przycisku: ");
    	Serial.println(liczba_nacisniec);
      }}}
  poprzedniStanPrzycisku - odczyt;
}