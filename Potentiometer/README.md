# Introduction
This module is a component of the GoKart Project at Hochschule Rhein-Waal.

This library provides a simple interface for reading the steering angle from a potentiometer connected to an Arduino board. Additionally, it prepares the steering angle as two bytes to be sent via BusCAN to MicroAutoBox 2.

# Transmitting Analog Value with CAN BUS
To transmit data via CAN communication, the 10-bit ADC is utilized to receive data from the potentiometer, producing an integer number ranging from 0 to 1023. Given that the CAN bus can include 8 data bytes for transmission, only 2 bytes are used to transmit the analog value.


- **Most Significant Byte (MSB)**:
    The MSB represents the largest place value in the binary number, significantly contributing to the total value. It's extracted using bitwise operations.
  
  <b>MSB:</b> Obtained through bitwise right shift operation.
  <p><code>msb = angle >> 2;</code></p>
  <p>Each bit is shifted two positions to the right. Consequently, only the first (leftmost) 8 bits are retained and stored in the variable <code>msb</code>.</p>
  
- **Least Significant Byte (LSB)**:
    The LSB is obtained by applying a mask, ensuring only the last two bits remain unchanged while others are set to 0
  
  <b>LSB:</b> Obtained by applying a bit mask.
      <p><code>lsb = angle & 3;</code></p>
  Alternatively represented in binary as: 
     <p><code>lsb = angle & 0b00000011;</code></p>
  <p>As a result, only the two rightmost bits remain unchanged, while all other bits are set to 0.</

  
Both MSB and LSB variables are declared as **uint8_t**:
- **Size**: Guaranteed to be 8 bits.
- **Range**: Can represent values from 0 to 255.
- **Signedness**: Represents only non-negative numbers.
- **Platform Independence**: Maintains a consistent size across different architectures.
- **Header**: Defined in the <stdint.h> or <cstdint> header files in C, and in the <cstdint> header file in C++.


### Class Members
- `TrigPin`: An integer representing the Arduino pin connected to the trigger pin of the potentiometer.

### Public Methods
- `StPot(int Pin)`: Constructor method for initializing the potentiometer with the specified pin.
- `int angleRead()`: Method for reading the current angle of the potentiometer.
- `void conv2bytes(int angle)`: Converts the potentiometer's angle into two bytes (MSB and LSB) for transmission via BusCAN to MicroAutoBox 2. The data is stored in the instance's attributes.

### Usage

```cpp
#include "steering_angle.h"
#include <Arduino.h>

StPot steeringPot(A0); // Potentiometer connected to analog pin A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int angle = steeringPot.angleRead();
  Serial.print("Steering Angle: ");
  Serial.println(angle);
  delay(500);
}
