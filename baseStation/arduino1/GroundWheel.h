#ifndef GroundWheel_h
#define GroundWheel_h

#include "Arduino.h"

class GroundWheel
{
  public:
    GroundWheel(int L, int R);
    void forward();
    void backward();
    void hang();
  private:
    int RPWM,LPWM;
};

#endif
