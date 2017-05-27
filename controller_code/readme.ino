/* total number of sending signals-
    1.motor base (4 types  f b l r)
    2. actuator back (u d)
    3. arm base (l r)
    4. actuator cam (u d)
    5. Sensor servo  ( u d)
    6. actuator front (u d)
    7.

*/

///////////////////////////////////////////////////
/* threshold for the joystick 0 or greater then 700

*/



void buttonPressed()
{
  for (int i = 0; i < 10; i++)
  {
    controller[i] = analogRead(i);
  }
  actCamLeft = digitalRead(33);
  actCamRight = digitalRead(47);
  sciTaskBaseLeft = digitalRead(23);
  sciTaskBaseRight = digitalRead(37);
  sensorServoUp = digitalRead(31);
  sensorServoDown = digitalRead(45);


}


void Send( char x)
{
  Serial1.print(x);
}
void Print( String x)
{
  Serial.println(x);
}
