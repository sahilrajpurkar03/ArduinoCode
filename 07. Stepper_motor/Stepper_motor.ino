const int stepPin = 3;  // Step pin connected to the stepper driver
const int dirPin = 4;   // Direction pin connected to the stepper driver

void setup() {
  pinMode(stepPin, OUTPUT);  // Set step pin as output
  pinMode(dirPin, OUTPUT);   // Set direction pin as output
}

void loop() {
  stepper_angle(90);   // Rotate 90 degrees clockwise
  delay(2000);         // Wait for 2 seconds
  stepper_angle(-90);  // Rotate 90 degrees counter-clockwise
  delay(2000);         // Wait for 2 seconds
}

void stepper_angle(int angle) {
  // Calculate the number of steps to move based on angle (assuming 200 steps per revolution)
  int steps = map(abs(angle), 0, 360, 0, 200);

  // Set direction: HIGH for positive angle (clockwise), LOW for negative (counter-clockwise)
  if (angle > 0)
    digitalWrite(dirPin, HIGH);
  else
    digitalWrite(dirPin, LOW);

  // Pulse the step pin 'steps' times to move the motor
  for (int x = 0; x < steps; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);  // Adjust speed by changing this delay
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}
