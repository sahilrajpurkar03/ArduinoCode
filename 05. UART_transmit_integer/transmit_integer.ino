int i = 0;  // Integer value to send

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
}

void loop() {
  Serial.println(i);   // Send current integer value followed by newline
  i++;                // Increment the integer
  if (i > 1000)       // Reset integer after reaching 1000 to avoid overflow
    i = 0;
  delay(1000);        // Wait for 1 second before sending next value
}
