#include "GoKartCan.h"
#include <mcp_can.h>
#include <SPI.h>

GoKartCan::GoKartCan(int INT_pin, int CS_pin){
  CAN0_INT=INT_pin;
  CS=CS_pin;
  Data[0] = 0;
  Data[1] = 0;
  Data[2] = 0;
  Data[3] = 0;
  Data[4] = 0;
  Data[5] = 0;
  Data[6] = 0;
  Data[7] = 0;

  CAN = new MCP_CAN(CS);

  Serial.begin(115200);

  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if (CAN->begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) Serial.println("MCP2515 Initialized Successfully!");
  else Serial.println("Error Initializing MCP2515...");

  CAN->setMode(MCP_NORMAL);  // Change to normal mode to allow messages to be transmitted

  pinMode(CAN0_INT, INPUT);  // Configuring pin for /INT input

}

void GoKartCan::receive(){
  long unsigned int rxId;
  unsigned char len = 0;
  char msgString[128];


  if (!digitalRead(CAN0_INT))  // If CAN0_INT pin is low, read receive buffer
  {
    CAN->readMsgBuf(&rxId, &len, Data);  // Read data: len = data length, buf = data byte(s)

    if ((rxId & 0x80000000) == 0x80000000)  // Determine if ID is standard (11 bits) or extended (29 bits)
      sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
    else
      sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);

    Serial.print(msgString);


    if ((rxId & 0x40000000) == 0x40000000) {  // Determine if message is a remote request frame.
      sprintf(msgString, " REMOTE REQUEST FRAME");
      Serial.print(msgString);
    }

    else {
      for (byte i = 0; i < len; i++) {
        sprintf(msgString, " 0x%.2X", Data[i]);
        Serial.print(msgString);
      }
    }

    Serial.println();
  }
}

void GokartCan::send(int ID, int CAN_FRAME,int data_length){
  CAN->sendMsgBuf(ID, CAN_FRAME, data_length, Data);
}




