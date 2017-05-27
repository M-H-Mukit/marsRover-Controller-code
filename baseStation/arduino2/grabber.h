#pragma once

#include <stdio.h>
#include <stdarg.h>

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


class grabber
{
  private:
    int PWM;                           
    int inA;                           
    int inB;

  public:
    
    grabber(int PWM, int inA, int inB);
    void rotateClock(int _speed);
    void rotateAntiClock(int _speed);
    void stopPulse();
};
