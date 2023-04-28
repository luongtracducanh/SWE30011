void setup() {
  // put your setup code here, to run once:
  for (int i = 7; i <= 13; i++)
    pinMode(i,OUTPUT);
  
  Serial.begin(9600);
}

String Number[] = {"1000000", "1111001", "0100100", "0110000", "0011001", "0010010", "0000010", "1111000", "0000000", "0010000"};
int a = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (a == 10)
    a = 0;

  for (int i = 7; i <= 13; i++)
    digitalWrite(i, String(Number[a][i - 7]).toInt());
    delay(300);
    a++;

  float pot = analogRead(A0);
  float vol = pot * 5 / 1024;

  float lm35 = analogRead(A1);
  float vol_lm35 = lm35 * 5 /1024;
  float temp_lm35 = vol_lm35 * 100;

  Serial.println("POT = " + String(vol) + " V; " + "Temperature = " + String(temp_lm35));
  delay(1000);
}
