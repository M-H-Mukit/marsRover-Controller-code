#include "pinNumbers.h"
#include "Relay.h"
#include "roverMotor.h"
#include "constant.h"


roverMotor l1("left 1", 10, 9);
roverMotor l2("left 2", 8, 7);
roverMotor l3("left 3", 3, 2);
roverMotor r1("right 1", 45, 46);
roverMotor r2("right 2", 4, 44);
roverMotor r3("right 3", 11, 12);

//roverMotor frontActuator("Actuator Front", 1000 , 1000);
//roverMotor rearActuator("Actuator Rear", 1000 , 1000);
roverMotor temp[6] = {l1, l2, l3, r1, r2, r3};


void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  roverMotor::initRoverMotorList(6, temp);
  //test();
}
char c;
void loop()
{
  while (Serial2.available())
  {
    c = Serial2.read();
       // Serial.write(c);

    switch (c)
    {
      case moveF:
        moveForward(220);
        Serial.write(c);
        break;
      case moveB:
        moveBackward(220);
        Serial.write(c);
        break;
      case moveL:
        moveLeft(123);
        break;
      case moveR:
        moveRight();
        break;
      case STOP:
        roverStop();
        break;
        
      default:
        roverStop();
        break;
    }

  }
}


