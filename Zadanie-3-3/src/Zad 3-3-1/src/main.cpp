#include <Arduino.h>

float ADC_RESOLUTION_DEFAULT = 5.0/1023.0;
float voltage;

void setup(){
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(A0, INPUT);
}

void loop(){
  int digital = analogRead(A0);
  voltage = ADC_RESOLUTION_DEFAULT * digital;
  Serial.println("A0 = ");
  Serial.print(digital);
  Serial.println(" V(0) = ");
  Serial.print(voltage);
  //Serial.print(" [V] ");
  delay(1000);
}