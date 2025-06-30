#include <SPI.h>

int transmit_value = 0;  // Data byte to send via SPI

void setup() {
  Serial.begin(115200);        // Initialize serial communication at 115200 baud
  pinMode(SS, OUTPUT);         // Ensure SS pin is configured as output
  digitalWrite(SS, HIGH);      // Disable Slave Select (active LOW)
  
  SPI.begin();                 // Initialize SPI as master
  SPI.setClockDivider(SPI_CLOCK_DIV2);  // Set SPI clock speed: CPU clock divided by 2 (fast)
  // Note: SPI_CLOCK_DIV2 means clock is divided by 2, NOT 8.
}

void loop() {
  digitalWrite(SS, LOW);       // Enable Slave Select to start communication

  for (int i = 0; i < 16; i++) {
    SPI.transfer(transmit_value);       // Send the current byte via SPI
    Serial.println(transmit_value);     // Print the sent value to Serial Monitor
    transmit_value++;                    // Increment the byte to send
    delay(2000);                        // Wait 2 seconds between sends
  }

  digitalWrite(SS, HIGH);      // Disable Slave Select after transmission
}
