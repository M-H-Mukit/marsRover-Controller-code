
void moveForward(int mSpeed)
{
  l1.forward(mSpeed);
  l2.forward(mSpeed);
  l3.forward(mSpeed);
  r1.forward(mSpeed);
  r2.forward(mSpeed);
  r3.forward(mSpeed);

}
void moveBackward(int mSpeed)
{
  l1.backward(mSpeed);
  l2.backward(mSpeed);
  l3.backward(mSpeed);
  r1.backward(mSpeed);
  r2.backward(mSpeed);
  r3.backward(mSpeed);

}
void moveLeft(int mSpeed)
{
  l1.backward(mSpeed-50);
  l2.backward(mSpeed-50);
  l3.backward(mSpeed-50);
  r1.forward(mSpeed);
  r2.forward(mSpeed);
  r3.forward(mSpeed);
  
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

