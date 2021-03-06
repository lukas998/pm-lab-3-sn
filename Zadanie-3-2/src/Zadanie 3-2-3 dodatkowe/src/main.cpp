#include <Arduino.h>

int LED = 13;
char rxBuff[32];
int bytesNo = 0;
char paramStr[16];
char paramIn[16];
int paramVal = 0;


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(4000);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  bytesNo = Serial.readBytesUntil('\r', rxBuff, sizeof(rxBuff) - 1);
  sscanf(rxBuff, "%s %d", paramStr, &paramVal);
  sscanf(rxBuff, "%s %d", paramIn, &paramVal);
  if (bytesNo) {
    Serial.print("Wykonuje...");
    
    if (!strcmp(paramStr, "led")) {
      if(1) {
        digitalWrite(LED_BUILTIN, HIGH);
      } else {
        digitalWrite(LED_BUILTIN, LOW);}
      Serial.println("OK!");} 
      
      //uruchomienie led w pinie 13
     else if(!strcmp(paramIn, "on")){
        if(1) {
          digitalWrite(LED, HIGH);}
        Serial.println("OK!");}
        
      // wylaczenie led
     else if (!strcmp(paramIn, "off")) {
        if(1){
          digitalWrite(LED, LOW);}
        Serial.println("OK!");}

      else if (!strcmp(paramStr, "blink")) {
          for(int i = 0; i < paramVal; i++) {
            digitalWrite(LED_BUILTIN, HIGH); delay(500);
            digitalWrite(LED_BUILTIN, LOW); delay(500);}
            Serial.println("OK!");} 
            else {
              Serial.println("Blad!");}}

          for(int i = 0; i < Serial.available(); i++){
                Serial.read();}
              for(int i = 0; i < sizeof(rxBuff); i++){
                  rxBuff[i]=0;
                  }}
