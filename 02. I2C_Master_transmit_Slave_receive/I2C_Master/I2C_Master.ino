#include<Wire.h>

byte transmit_value=0;

void setup() 
{
  Wire.begin();
  Serial.begin(9600);
}

void loop() 
{
  Wire.beginTransmission(8);
  Wire.write(transmit_value);
  Serial.println(transmit_value);
  Wire.endTransmission();

  transmit_value++;
  delay(1000);
}
