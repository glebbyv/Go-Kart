#include "ultrasonic.h"
#include <Arduino.h>

UltraSonic::UltraSonic(int Trig, int Echo){
  TrigPin=Trig;
  EchoPin=Echo;
  pinMode(TrigPin, OUTPUT);  // Set trigger pins as output
  pinMode(EchoPin, INPUT);      // Set echo pins as input

  Serial.print("Inisialisation succeful");
}

void UltraSonic::trigger(){
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
} 

int UltraSonic::dist() {
  trigger();

  long duration = pulseIn(EchoPin, HIGH);
  if (duration > 38000) {
    return -1.0;  // Indicating an out-of-range value
  } else {
    return round(duration * 0.034 / 2.0);
  }
}