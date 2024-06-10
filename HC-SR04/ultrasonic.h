#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class UltraSonic {
  public:
    UltraSonic(int Trig, int Echo);
    void trigger();
    int dist();
    
  private:
    int TrigPin;
    int EchoPin;
};

#endif