#include "config.h"

extern int Can_interupt = 18; 
extern int CAN_CS = 19;
extern GoKartCan CanHandler(Can_interupt,CAN_CS);  

extern byte trigger1 = 11; 
extern byte echo1 = 12;
extern UltraSonic sonic1(trigger1,echo1);

extern byte trigger2 = 16;
extern byte echo2 = 17;
extern UltraSonic sonic2(trigger2,echo2);

extern int PotPin = A0;
extern StPot pot(PotPin);