#include<Wire.h>

int transmit_value=0;

void transmit(int x);

void setup() 
{
  Wire.begin(8);
  Wire.onRequest(transmit);
  Serial.begin(9600);
}

void loop() 
{
  delay(500);
  transmit_value++;
  Serial.println(9600);
}

void transmit(int x)
{
  Wire.write(transmit_value);
}
