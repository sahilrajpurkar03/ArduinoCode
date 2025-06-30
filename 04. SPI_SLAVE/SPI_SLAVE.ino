#include <SPI.h>

volatile int receive_value = 0;  // Store received byte (volatile for ISR use)
volatile boolean process = false;  // Flag to indicate data received

void setup() {
  Serial.begin(115200);          // Initialize serial communication
  pinMode(MISO, OUTPUT);         // Set MISO as output (slave sends data on this line)
  SPCR |= _BV(SPE);              // Enable SPI in slave mode
  SPI.attachInterrupt();         // Enable SPI interrupt
}

ISR(SPI_STC_vect) {              // SPI interrupt service routine
  receive_value = SPDR;          // Read received byte from SPI Data Register (SPDR)
  process = true;                // Set flag to process data in loop()
}

void loop() {
  if (process) {
    process = false;             // Reset flag
    Serial.println(receive_value);  // Print received byte to Serial Monitor
  }
}
