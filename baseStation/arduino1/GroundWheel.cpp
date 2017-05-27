#include "Arduino.h"
#include "GroundWheel.h"

GroundWheel::GroundWheel(int L, int R)
{
  RPWM = R;
  LPWM = L;
  pinMode(RPWM, INPUT);
  pinMode(LPWM, INPUT);
}


void GroundWheel::backward()
{
}

void GroundWheel::forward()
{
 
}


void GroundWheel::hang()
{
 
}
