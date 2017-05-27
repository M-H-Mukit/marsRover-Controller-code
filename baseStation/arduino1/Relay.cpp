#include "Arduino.h"
#include "Relay.h"

Relay::Relay(int relayPin)
{
  rpin = relayPin;
  pinMode(rpin, OUTPUT);
  digitalWrite(rpin, LOW); 
  
}


void Relay::relayOn()
{
}

void Relay::relayOff()
{
 
}


