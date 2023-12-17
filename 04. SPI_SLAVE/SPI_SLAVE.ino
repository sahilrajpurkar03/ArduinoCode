#include <SPI.h>
int receive_value=0;
volatile boolean process;

void setup (void) 
{
   Serial.begin (115200);
   pinMode(MISO, OUTPUT); // have to send on master in so it set as output
   SPCR |= _BV(SPE); // turn on SPI in slave mode
   process = false;
   SPI.attachInterrupt(); // turn on interrupt
}

ISR (SPI_STC_vect) // SPI interrupt routine 
{ 
   int receive_value = SPDR; // read byte from SPI Data Register
   process = true;
}

void loop (void) 
{
   if (process) 
   {
      process = false; //reset the process
      Serial.println (receive_value); //print the array on serial monitor
   }
}
