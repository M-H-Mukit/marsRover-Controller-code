
void actBackUp(int mSpeed)
{
  actuatorF.forward(mSpeed);  // here forward function is calling for up
}

void actBackDown(int mSpeed)
{
  actuatorF.backward(mSpeed); // here backward is calling for down
}

/// servoControl Function ................................................................................
void bodyCamServoUp()
{
  currentPosbodyCamServoUD = currentPosbodyCamServoUD + 2; // here the sign of + may  nned to change to -
  bodyCamServoUD.write(currentPosbodyCamServoUD);
  delay (15);

}

void bodyCamServoDown()
{
  currentPosbodyCamServoUD = currentPosbodyCamServoUD - 2; // here the sign of - may  nned to change to +
  bodyCamServoUD.write(currentPosbodyCamServoUD);
  delay (15);

}

void bodyCamServoLeft()
{
  currentPosbodyCamServoLR = currentPosbodyCamServoLR + 2; // here the sign of + may  nned to change to -
  bodyCamServoLR.write(currentPosbodyCamServoLR);
  delay (15);

}

void bodyCamServoRight()
{
  currentPosbodyCamServoLR = currentPosbodyCamServoLR - 2; // here the sign of - may  nned to change to +
  bodyCamServoLR.write(currentPosbodyCamServoLR);
  delay (15);
}

void actCamServoLeft()
{
  currentPosActCamServo = currentPosActCamServo + 2; // here the sign of + may  nned to change to -
  actCamServo.write(currentPosActCamServo);
  delay (15);

}
void actCamServoRight()
{
  currentPosActCamServo = currentPosActCamServo - 2; // here the sign of - may  nned to change to +
  actCamServo.write(currentPosActCamServo);
  delay (15);

}
void baseServoAntiClock()
{
  currentPosBaseServo = currentPosBaseServo + 2; // here the sign of + may  nned to change to -
  baseServo.write(currentPosBaseServo);
  delay (15);

}
void baseServoClock()
{
  currentPosBaseServo = currentPosBaseServo - 2; // here the sign of - may  nned to change to +
  baseServo.write(currentPosBaseServo);
  delay (15);

}

void roverStop()
{
  l1.stopPulse();
  l2.stopPulse();
  l3.stopPulse();
  r1.stopPulse();
  r2.stopPulse();
  r3.stopPulse();
}

