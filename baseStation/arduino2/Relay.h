#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay
{
  public:
    Relay(int relayPin);
    void relayOn();
    void relayOff();
   
  private:
    int rpin;
};

#endif
