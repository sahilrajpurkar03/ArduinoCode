const int stepPin = 3; 
const int dirPin = 4; 

void setup() 
{
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}

void loop() 
{
  stepper_angle(90);               //positive angle for clockwise direction 
  delay(2000);
  stepper_angle(-90);              //negative angle for anti-clockwise direction
  delay(2000);
}

void stepper_angle(int angle)
{ 
  int actual_angle=map(angle,0,360,0,200);
  if(angle>0)
  digitalWrite(dirPin,HIGH);
  else
  digitalWrite(dirPin,LOW); 
  for(int x = 0; x <actual_angle; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 
  }
}
