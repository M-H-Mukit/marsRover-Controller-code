#include "constant.h"
int MoveUp, MoveDown, MoveLeft, MoveRight, WristOpen, WristClose, WristLeft, WristRight;
int Actua1Up, Actua1Down, Actua1Left, Actua1Right, Actua2Up, Actua2Down, actCamLeft, actCamRight;
int BodycamUp, BodycamDown, BodycamLeft, BodycamRight;
int sciTaskBaseLeft, sciTaskBaseRight, sensorServoUp, sensorServoDown;

int controller[10];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(33, INPUT);
  pinMode(47, INPUT);
  pinMode(23, INPUT);
  pinMode(31, INPUT);
  pinMode(37, INPUT);
  pinMode(45, INPUT);
}

void loop() {

  buttonPressed(); // func to set the value for each variable inside the logic

  if (controller[0] == 0) {
    Send(moveR);
    Print("moveRight");
  }
  else if (controller[0] > 700) {
    Send(moveL);
    Print("moveLeft");
  }
  else if (controller[1] == 0) {
    Send(moveF);
    Print("moveUp");
  }
  else if (controller[1] > 700) {
    Send(moveB);
    Print("moveDown");
  }
  else if (controller[4] == 0) {
    Send(wristOpen);                  //send wristopen for shovel down
    Print("Wrist oper/shovel down");

  }
  else if (controller[4] > 700) {
    Send(wristClose);                  //send wristclose for shovel up
    Print("Wrist Close/shovel up");
  }
  if (controller[5] == 0) {
    Send(wristRotateL);
    Print("Wrist Left");
  }
  else if (controller[5] > 700) {
    Send(wristRotateR);
    Print("Wrist Right");
  }

  if (controller[6] == 0) {
    Send(bodyCamD);
    Print("BodyCam Down");
  }
  else if (controller[6] > 700) {
    Send(bodyCamU);
    Print("BodyCam Up");
  }
  else if (controller[7] == 0) {
    Send(bodyCamL);
    Print("BodyCam Left");
  }
  else if (controller[7] > 700) {
    Send(bodyCamR);
    Print("BodyCam Right");
  }

  else if (controller[9] == 0) {
    Send(actuatorFrontD);
    Print("actuatorFront Down");

  }
  else if (controller[9] > 700) {
    Send(actuatorFrontU);
    Print("actuatorFront Up");

  }
  else if (controller[8] == 0) {
    //Send();
    Print("Actuator2 Left");
  }
  else if (controller[8] > 700) {
    // Send();
    Print("Actuator2 Right");
  }

  else if (controller[3] == 0) {
    Send(actuatorBackU);
    Print("Actuator1 Up");
  }
  else if (controller[3] > 700) {
    Send(actuatorBackD);
    Print("Actuator1 Down");
  }
  else if (controller[2] == 0) {
    Send(armBaseR);
    Print("Actuator1 Right");
  }
  else if (controller[2] > 700) {
    Send(armBaseL);
    Print("Actuator1 Left");
  }
  else if (actCamLeft)
  {
    Send(actuatorCamL);
    Print("ActuatorCam left");
  }
  else if (actCamRight)
  {
    Send(actuatorCamR);
    Print("ActuatorCam Right");
  }
  else if (sciTaskBaseLeft)
  {
    Send(SciTaskBaseL);
    Print("SciTaskBase left");
  }
  else if (sciTaskBaseRight)
  {
    Send(SciTaskBaseR);
    Print("SciTaskBase Right");
  }
  else if (sensorServoUp)
  {
    Send(SensorServoU);
    Print("SensorServo Up");
  }
  else if (sensorServoDown)
  {
    Send(SensorServoD);
    Print("SensorServo Down");
  }
  else
  {
    Send (STOP);
    MoveUp = 0;
    MoveDown = 0;
    MoveLeft = 0;
    MoveRight = 0;
    WristOpen = 0;
    WristClose = 0;
    WristLeft = 0;
    WristRight = 0;
    Actua1Up = 0;
    Actua1Down = 0;
    Actua1Left = 0;
    Actua1Right = 0;
    Actua2Up = 0;
    Actua2Down = 0;
    sciTaskBaseLeft = 0;
    sciTaskBaseRight = 0;
    BodycamUp = 0;
    BodycamDown = 0;
    BodycamLeft = 0;
    BodycamRight = 0;
    sensorServoUp = 0;
    sensorServoDown = 0;
    actCamLeft = 0;
    actCamRight = 0;
  }
  delay(5);
}




