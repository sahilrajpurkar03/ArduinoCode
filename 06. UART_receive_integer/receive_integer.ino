void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
String receive_value;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    Serial.println(Serial.readStringUntil('\n'));
  }
//Serial.println(receive_value);
}
