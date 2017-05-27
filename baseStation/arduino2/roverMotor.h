#pragma once

#include <stdio.h>
#include <stdarg.h>

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define NUMBER_OF_MOTORS 6

#define LEFT_FRONT 0
#define LEFT_MIDDLE 1
#define LEFT_REAR 2
#define RIGHT_FRONT 3
#define RIGHT_MIDDLE 4
#define RIGHT_REAR 5

class roverMotor
{
  private:
    char* motorName;
    int forward_PWM;                            //RPWM
    int backward_PWM;                           //LPWM
    static roverMotor* roverMotorList;

  public:
    static void initRoverMotorList(int number, roverMotor list[NUMBER_OF_MOTORS]);
  
    roverMotor(char* mName, int forwardPin, int backwardPin);
    
    char* getName();
    
    void forward(int forwardSpeed);
    void backward(int backwardSpeed);
    void stopPulse();
    
    static void forwardSelective(int forwardSpeed, int numberOfMotors, ...);
    static void backwardSelective(int backwardSpeed, int numberOfMotors, ...);
        
    static void left();    //assuming full speed for differential drive
    static void right();   //assuming full speed for differential drive
};
