#include<Wire.h>

int receive_value=0;

void receive_8(int x);
void setup() 
{
  Wire.begin(8);
  Wire.onReceive(receive_8);
  Serial.begin(9600);
}

void loop() 
{
  delay(100);
}

void receive_8(int x)
{
  int receive= Wire.read();
  Serial.println(receive);
}


