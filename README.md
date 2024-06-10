# Go-Kart
This repository is for the HSRW Electrical Go Kart project, aiming to connect various sensors to MicroAutoBox2 and establish a real-time system with CAN communication.

## Control System
The central control unit in the vehicle is a dSpace MicroAutoBox. The real-time system is used to control the communication between all components, receive the driver input, and control the motor torque at each wheel. The system is programmed in block-oriented programming using Matlab/Simulink. It is capable of running code for running the basic functions, as well as complex vehicle simulations and algorithms for control and energy optimization. The modular character of the program code allows for easy change and the extension of implemented functions, which enables the integration of various subsystems on the vehicle. To enhance modularity, two centralized ECUs are used, providing the physical interfaces to various sensors and systems in the vehicle. The SensorBox bundles all incoming sensor signals, like throttle, brake, and steering wheel angle in the basic setup. The HMIBox provides the information, which is displayed for the driver.

## Communication
For communication, CAN-bus is implemented which carries all signals and messages between the components.
- One central bus system prevents extensive wiring of each signal/sensor
- Flexible and quick integration of additional systems
- All Information available on for components
- High data integrity and bus availability
- Reduces complexity and fewer error sources

# External Sensors Integration

In our project, we utilize a customized version of the Arduino Mega for integrating external sensors. This custom board is tailored specifically for our needs, including built-in CAN communication capabilities. Its main feature lies in its seamless integration with the MicroAutoBox2, enabling the addition of various sensors to our system.
