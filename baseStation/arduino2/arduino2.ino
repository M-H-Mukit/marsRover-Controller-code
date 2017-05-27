/* must read...............
    for wipper and actuator change the pin to rotate
    and for servo change + or - to change the direction of the rotation
    default servo must be at 90 degree to cover both side it can't be change
*/

#include <Servo.h>

#include "pinNumbers.h"
#include "Relay.h"
#include "roverMotor.h"     // here motor class will be used for actuator and grabber
#include "constant.h"

//for motor .......................

roverMotor l1("left 1", 10, 9);
roverMotor l2("left 2", 8, 7);
roverMotor l3("left 3", 3, 2);
roverMotor r1("right 1", 45, 46);
roverMotor r2("right 2", 4, 44);
roverMotor r3("right 3", 11, 12);

//...............................

//////////// for actuator
roverMotor actuatorF("front actuator", 10, 9);   //pin number should be changed
roverMotor actuatorB("back actuator", 8, 7);     //pin number should be changed

//////////// for grabber
roverMotor grabberRotation ("grabber rotation", 10, 8);
roverMotor grabberOC  ("grabber openClose", 10, 5);

/////////// for armbase wipper motor
roverMotor armBaseMotor ("armBaseMotor", 10, 6); // pin number must need to change

/////////// defining the servo obje

Servo baseServo, bodyCamServoUD, bodyCamServoLR, actCamServo;

//change the pin of servo to get which one is used for up down direction and wichone for left right
// here servo pin is definnig
#define baseServoPin 7 //must change
#define bodyCamServoUDPin 7 //must change attach the servo which motion is upward and downward of body servo
#define bodyCamServoLRPin 7 //must change
#define actCamServoPin 7 //must change

#define defPos 90
int currentPosBaseServo = defPos;
int currentPosbodyCamServoUD = defPos;
int currentPosbodyCamServoLR = defPos;
int currentPosActCamServo = defPos;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);

  //////////servo on pin is attaching
  baseServo.attach(baseServoPin);
  bodyCamServoUD.attach(bodyCamServoUDPin);
  bodyCamServoLR.attach(bodyCamServoLRPin);
  actCamServo.attach(actCamServoPin);
  //........  no change in this block if alignment is not correct then change the hardware to set it in the middle ..........
  baseServo.write(defPos);
  bodyCamServoUD.write(defPos);
  bodyCamServoLR.write(defPos);
  actCamServo.write(defPos);

  /////////...........


}
char c;
void loop()
{
  while (Serial1.available())
  {
    c = Serial1.read();
    // Serial2.write(c);  // sending the data to anrduino 1 for locomotion control

    switch (c)
    {
      case actuatorBackU:
        ///////////may need to change the pin for this block
        actBackUp(220); // this function is in movement.ino
        ///////////////
        Serial.write(c);
        break;
      case actuatorBackD:
        actBackDown(220);
        Serial.write(c);
        break;
      case actuatorFrontU:
        ///////////may need to change the pin for this block
        actuatorF.forward(200); // directly calling forward funtion here instead of movement.ino
        ///////////////
        Serial.write(c);
        break;
      case actuatorFrontD:
        actuatorF.backward(220); // directly calling forward funtion here instead of movement file
        Serial.write(c);
        break;
      case armBaseL:  // anticlock rotation of arm base
        ///////////may need to change the pin for this block
        armBaseMotor.forward(220); // forward Using for left motion
        ///////////////
        Serial.write(c);
        break;
      case armBaseR:
        armBaseMotor.backward(220);
        Serial.write(c);
        break;
      case wristRotateL: //for anticlock wise wrist movemonet assuming from backside of rober
        grabberRotation.forward(220); // forward is using for lefft rotation
        Serial.write(c);
        break;
      case wristRotateR:
        grabberRotation.backward(220);
        Serial.write(c);
        break;
      case wristOpen: // assuming for clock rotation of motor wrist will open so used backward function here
        grabberOC.backward(220);
        Serial.write(c);
        break;
      case wristClose: // assuming for anticlock rotation of motor wrist will close so used forward function here
        grabberOC.forward(220);
        Serial.write(c);
        break;
      case bodyCamU:
        bodyCamServoUp();
        Serial.write(c);
        break;
      case bodyCamD:
        bodyCamServoDown();
        Serial.write(c);
        break;
      case bodyCamL:
        bodyCamServoLeft();
        Serial.write(c);
        break;
      case bodyCamR:
        bodyCamServoRight();
        Serial.write(c);
        break;
      case actuatorCamL:
        actCamServoLeft;
        Serial.write(c);
        break;
      case actuatorCamR:
        actCamServoRight();
        Serial.write(c);
        break;
      case SciTaskBaseL:  //left assumed as anti clock
        baseServoAntiClock;
        Serial.write(c);
        break;
      case SciTaskBaseR:
        baseServoClock;
        Serial.write(c);
        break;
      default:
        roverStop();
        Serial2.write(c); //if no case match sending the data to anrduino 1 for locomotion control
        break;
    }

  }
}


