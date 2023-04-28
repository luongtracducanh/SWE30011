void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    Serial.print("Arduino received: ");
    Serial.println(data);
    delay(1000);
  }
}

// float vout;
// float tempc;
// void setup() {
//   Serial.begin(9600);
// }
// void loop() {
//   vout = analogRead(A0); // reading from the sensor
//   vout *= 5/1024.0;
//   tempc = vout * 100.0; // storing the value in Degree Celsius
//   Serial.println(tempc);
//   delay(1000);
// }