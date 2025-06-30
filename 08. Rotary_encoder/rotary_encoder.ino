#define en_in A0  // Encoder input pin (no semicolon here)

int curA = 0, preA = 0;
int disp1 = 0;  // Variable to store encoder count/display value

void encoder_start();

void setup() {
  pinMode(en_in, INPUT);      // Set encoder input pin as input
  Serial.begin(9600);         // Initialize serial communication at 9600 baud
}

void loop() {
  encoder_start();            // Read encoder and update disp1
  Serial.println(disp1);      // Print current encoder count
  delay(100);                 // Add a small delay for readability
}

void encoder_start() {
  curA = analogRead(en_in);  // Read current analog value from encoder

  disp1 += curA - preA;      // Update disp1 by difference between current and previous reading

  // Handle wrap-around when difference is large negative (encoder moved forward past max)
  if (curA - preA <= -150) {
    disp1 -= (curA - preA);
    disp1++;
  }
  // Handle wrap-around when difference is large positive (encoder moved backward past min)
  if (curA - preA >= 150) {
    disp1 -= (curA - preA);
    disp1--;
  }
  preA = curA;               // Save current reading for next iteration
}
