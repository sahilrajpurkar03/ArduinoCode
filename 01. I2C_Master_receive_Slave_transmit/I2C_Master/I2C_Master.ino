#include<Wire.h>

int receive_value=0;

void setup() 
{
  Wire.begin();
  Serial.begin(9600);
}

void loop() 
{
  Wire.requestFrom(8,8);
  int receive_value=Wire.read();
  Serial.println(receive_value);
  delay(500);
}

