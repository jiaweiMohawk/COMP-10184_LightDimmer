#include <Arduino.h>

bool LightStatus = 0;
bool LastButtonValue = 0;

void setup()
{
  Serial.begin(115200);

  pinMode(D5, INPUT_PULLUP);
  pinMode(D4, OUTPUT);

  analogWrite(D4, 0); 
}

void loop() {
  
  // potentiometer
  int iVal;
  iVal = analogRead(A0);

  // button
  int iButton; 
  iButton = digitalRead(D5); 


  // if(LastButtonValue==1 && iButton==0){
  if(LastButtonValue==1 && iButton==0){
    // button status changed
    LightStatus = !LightStatus;

    if(LightStatus == 1){
      analogWrite(D4, iVal); 
    }
    Serial.println("Button Clicked." + String(LightStatus));
    Serial.println("iVal." + String(iVal));
  }

  LastButtonValue = iButton;

  if(LightStatus == 0){
    analogWrite(D4, HIGH); 
  }


  delay(1); 
}