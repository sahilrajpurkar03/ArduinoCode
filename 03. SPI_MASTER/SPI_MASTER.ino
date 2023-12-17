#include <SPI.h>
int transmit_value=0;

void setup (void) 
{
   Serial.begin(115200); //set baud rate to 115200 for usart
   digitalWrite(SS, HIGH); // disable Slave Select
   SPI.begin ();
   SPI.setClockDivider(SPI_CLOCK_DIV2);//divide the clock by 8
}

void loop (void) 
{
   digitalWrite(SS, LOW); // enable Slave Select
  for(int i=0;i<16;i++)
  {
      SPI.transfer (transmit_value);
      Serial.println(transmit_value);
      transmit_value++;
      delay(2000);
  }
  digitalWrite(SS, HIGH); // disable Slave Select
}
