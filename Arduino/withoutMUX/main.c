#include <Arduino.h>

int pin0 = A0;
int pin1 = A1;
int pin2 = A2;
int pin3 = A3;
int pin4 = A4;

int analogPin[5] = {pin0, pin1, pin2, pin3, pin4}; // terminal do meio de um potênciometro conectado ao pino analógico 3
                    // terminais mais externos são conectados um no ground e o outro em +5V
int val = 0;        // variável para guardar o valor lido

void setup() {
  Serial.begin(9600);           // configura a porta serial
}

void loop() {
  Serial.println("Y0\tY1\tY2\tY3\tY4");
  Serial.println("---\t---\t---\t---\t---");
  for(int i = 0; i < 5; i++){
    val = analogRead(analogPin[i]);  // lê o pino de entrada
  	Serial.print(val);          // imprime o valor na porta serial
  	Serial.print("\t");
  }

  Serial.println("\n"); 
}