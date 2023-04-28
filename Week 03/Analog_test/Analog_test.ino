void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float a = analogRead(A1);
  float vol = a * 5 / 1023;
  float temp = vol * 100;
  // Serial.println(String(vol) + "V");
  Serial.println(String(temp) + " degree");
  delay(500);
}