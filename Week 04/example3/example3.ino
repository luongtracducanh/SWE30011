// const int ledPin = 13;
// const int button = 2;

// void setup() {
//   // put your setup code here, to run once:
//   pinMode(ledPin, OUTPUT);
//   pinMode(button, INPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   if (digitalRead(button) == LOW) {
//     digitalWrite(ledPin, HIGH);
//   } else if (digitalRead(button) == HIGH) {
//     digitalWrite(ledPin, LOW);
//   }
//   delay(1000);
// }

void runInterrupt() {
  digitalWrite(13, 1);
}

void setup() {
  pinMode(13, OUTPUT);
  attachInterrupt(0, runInterrupt, LOW);
}

void loop() {
  digitalWrite(13, 0);
  // delay(10000);
}