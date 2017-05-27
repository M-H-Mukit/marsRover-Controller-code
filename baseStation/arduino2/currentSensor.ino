
int getCurrentSensor(int sensorNumber)
{
  switch(sensorNumber)
  {
    case '1':
    return   analogRead(CURRENT_SENSOR1);
    break;

    case '2':
    return  analogRead(CURRENT_SENSOR2);
    break;

    case '3':
    return   analogRead(CURRENT_SENSOR3);
    break;
    
    case '4':
    return   analogRead(CURRENT_SENSOR4);
    break;

    default:
    printf("sensor out of bound");
    break;
    
  }
 
  
}

