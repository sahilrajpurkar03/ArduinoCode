#include <Wire.h>  // Include the I2C communication library

byte transmit_value = 0;  // Byte to send to the I2C slave (0–255)

void setup() {
  Wire.begin();            // Initialize I2C as a master
  Serial.begin(9600);      // Start serial communication at 9600 baud
}

void loop() {
  Wire.beginTransmission(8);     // Begin I2C transmission to slave at address 8
  Wire.write(transmit_value);    // Send one byte to the slave
  Wire.endTransmission();        // End transmission

  Serial.println(transmit_value); // Print the value sent for debugging

  transmit_value++;              // Increment the value (rolls over after 255)
  delay(1000);                   // Wait 1 second before sending next value
}
