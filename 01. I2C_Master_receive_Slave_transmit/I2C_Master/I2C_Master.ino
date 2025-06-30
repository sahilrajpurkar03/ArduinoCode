#include <Wire.h>  // Include the I2C communication library

int receive_value = 0;  // Variable to store received data

void setup() {
  Wire.begin();          // Initialize I2C communication as a master
  Serial.begin(9600);    // Start serial communication at 9600 baud
}

void loop() {
  Wire.requestFrom(8, 8);       // Request 8 bytes from the I2C slave device with address 8

  // Read the first available byte from the slave
  receive_value = Wire.read();  // Note: Only reads one byte here
  Serial.println(receive_value); // Print the received byte to the Serial Monitor

  delay(500);  // Wait for 500 milliseconds before the next request
}
