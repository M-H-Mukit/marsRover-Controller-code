#include "grabber.h"


grabber::grabber(int PWM, int inA, int inB)
{
  this->PWM = PWM;
  this->inA= inA;
  this->inB = inB;
pinMode(PWM, OUTPUT);
pinMode(inA, OUTPUT);
pinMode(inB, OUTPUT);
}
void grabber::rotateClock(int _speed){
}
void grabber::rotateAntiClock(int _speed){
}
void grabber::stopPulse(){
}

