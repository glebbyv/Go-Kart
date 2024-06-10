# HSRW GoKart Ultrasonic Sensor Library

This library provides software for reading distance measurements from an ultrasonic sensor and sending the data via BusCAN to MicroAutoBox 2

### Class Members
- `TrigPin`: An integer representing the Arduino pin connected to the trigger pin of the ultrasonic sensor.
- `EchoPin`: An integer representing the Arduino pin connected to the echo pin of the ultrasonic sensor.

### Public Methods
- `UltraSonic(int Trig, int Echo)`: Constructor method for initializing the ultrasonic sensor with specified trigger and echo pins.
- `void trigger()`: Method for triggering the ultrasonic sensor to send out a pulse.
- `int dist()`: Method for measuring the distance to an object using the ultrasonic sensor and returning the distance in centimeters.

## Usage
To use the Ultrasonic Sensor Library in your Arduino project, include the `ultrasonic.h` header file and `ultrasonic.cpp` source file in your project directory. Then, create an instance of the `UltraSonic` class with the appropriate trigger and echo pins. You can then call the `dist()` method to measure the distance to an object.

```cpp
#include "ultrasonic.h"
#include <Arduino.h>

UltraSonic sensor(9, 10); // Trigger pin: 9, Echo pin: 10

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = sensor.dist();
  Serial.print("Distance: ");
  if (distance == -1) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
