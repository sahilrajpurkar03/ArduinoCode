#include <Wire.h>  // Include the I2C library

int transmit_value = 0;  // Value to send to I2C master

void transmit(int x);    // Forward declaration of the transmit callback (optional)

void setup() {
  Wire.begin(8);                  // Initialize I2C as a slave with address 8
  Wire.onRequest(transmit);      // Register function to call when data is requested
  Serial.begin(9600);            // Start serial communication for debugging
}

void loop() {
  delay(500);                    // Wait for 500 milliseconds
  transmit_value++;              // Increment value to be sent
  Serial.println(transmit_value); // Print current value to Serial Monitor
}

// Callback function that runs when master requests data
void transmit(int x) {
  Wire.write(transmit_value);   // Send the current value to the master
}
