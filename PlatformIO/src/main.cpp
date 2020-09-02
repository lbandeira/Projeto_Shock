#include <Arduino.h>

const int selectPins[4] = {26, 25, 33, 32};
const int analogInput = 27;

void setup() 
{
  Serial.begin(9600);
  // Set up the select pins as outputs:
  for (int i=0; i<4; i++)
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], HIGH);
  }
  
  // Create header table
  Serial.println("Y0\tY1\tY2\tY3\tY4\tY5\tY6\tY7");
  Serial.println("---\t---\t---\t---\t---\t---\t---\t---");
}

void loop() 
{
  // Loop through all eight pins.
  for (byte pin=0; pin<6; pin++)
  {
      for (int i=0; i<4; i++) {
          digitalWrite(selectPins[i], pin & (1 << i)?HIGH:LOW);
      }
      int inputValue = analogRead(analogInput);
      Serial.print(String(inputValue) + "\t");
  }
  Serial.println();
  delay(1000);
}