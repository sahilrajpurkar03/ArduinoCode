String receive_value;  // String to store incoming data

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
}

void loop() {
  if (Serial.available() > 0) {                      // Check if data is available
    receive_value = Serial.readStringUntil('\n');    // Read incoming data until newline
    int received_int = receive_value.toInt();        // Convert received string to integer
    Serial.print("Received integer: ");              
    Serial.println(received_int);                     // Print the received integer
  }
}
