#ifndef CONFIG_H
#define CONFIG_H

#include "steering_angle.h"
#include <stdint.h> 
#include <math.h>
#include "ultrasonic.h"
#include "GoKartCan.h"
#include <Arduino.h>

//Can Communication
extern int Can_interupt ;
extern int CAN_cs;
extern GoKartCan CanHandler;

//HC-SR04 UltraSonic sensor
extern byte trigger1 ;
extern byte echo1 ;
extern byte trigger2 ;
extern byte echo2 ;

extern UltraSonic sonic1;
extern UltraSonic sonic2;

//Steering Potentiometer
extern int PotPin ;
extern StPot pot;

#endif