#include "roverMotor.h"
#include <stdio.h>
#include <stdarg.h>

roverMotor* roverMotor::roverMotorList = (roverMotor*)malloc(NUMBER_OF_MOTORS*sizeof(roverMotor));

void roverMotor::initRoverMotorList(int number, roverMotor list[NUMBER_OF_MOTORS])
{
  int i;

  for (i = 0; i < number; i++)
  {
    roverMotorList[i] = list[i];
  }
}

roverMotor::roverMotor(char* mName, int forwardPin, int backwardPin)
{
  motorName = mName;

  forward_PWM = forwardPin;
  backward_PWM = backwardPin;

  pinMode(forward_PWM, OUTPUT);
  pinMode(backward_PWM, OUTPUT);
}

char* roverMotor::getName()
{
  return motorName;
}

void roverMotor::forward(int forwardSpeed)
{
  if (forwardSpeed >= 0 && forwardSpeed <= 250)
  {
    analogWrite(forward_PWM, forwardSpeed);
    analogWrite(backward_PWM, 0);
  }
}
void roverMotor::backward(int backwardSpeed)
{
  if (backwardSpeed >= 0 && backwardSpeed <= 250)
  {
    analogWrite(forward_PWM, 0);
    analogWrite(backward_PWM, backwardSpeed);
  }
}
void roverMotor::stopPulse()
{
  analogWrite(forward_PWM, 0);
  analogWrite(backward_PWM, 0);
}

void roverMotor::forwardSelective(int forwardSpeed, int numberOfMotors, ...)
{
  int i;
  int* temp;

  va_list variableMotorList;

  va_start(variableMotorList, numberOfMotors);
  for (i = 0; i < numberOfMotors; i++)
  {
    temp[i] = va_arg(variableMotorList, int);
  }
  va_end(variableMotorList);

  for (i = 0; i < numberOfMotors; i++)
  {
    //Serial.println(roverMotorList[temp[i]].getName());
    roverMotorList[temp[i]].forward(forwardSpeed);
  }
}
void roverMotor::backwardSelective(int backwardSpeed, int numberOfMotors, ...)
{
  int i;
  int* temp;

  va_list variableMotorList;

  va_start(variableMotorList, numberOfMotors);
  for (i = 0; i < numberOfMotors; i++)
  {
    temp[i] = va_arg(variableMotorList, int);
  }
  va_end(variableMotorList);

  for (i = 0; i < numberOfMotors; i++)
  {
    //Serial.println(roverMotorList[temp[i]].getName());
    roverMotorList[temp[i]].backward(backwardSpeed);
  }
}

void roverMotor::left()
{
  forwardSelective(255, 3, RIGHT_FRONT, RIGHT_MIDDLE, RIGHT_REAR);
  backwardSelective(255, 3, LEFT_FRONT, LEFT_MIDDLE, LEFT_REAR);
}
void roverMotor::right()
{
  forwardSelective(255, 3, LEFT_FRONT, LEFT_MIDDLE, LEFT_REAR);
  backwardSelective(255, 3, RIGHT_FRONT, RIGHT_MIDDLE, RIGHT_REAR);
}
