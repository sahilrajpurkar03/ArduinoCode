#include <Wire.h>  // Include the I2C library

int receive_value = 0;  // Variable to store received data

// Forward declaration of the receive callback
void receive_8(int numBytes);

void setup() {
  Wire.begin(8);                  // Start I2C as a slave with address 8
  Wire.onReceive(receive_8);     // Register the receive callback function
  Serial.begin(9600);            // Start Serial Monitor for debugging
}

void loop() {
  delay(100);  // Wait briefly; main work is done in receive callback
}

// Callback function triggered when master sends data
void receive_8(int numBytes) {
  while (Wire.available()) {             // Check if bytes are available
    receive_value = Wire.read();         // Read one byte
    Serial.println(receive_value);       // Print received value
  }
}
