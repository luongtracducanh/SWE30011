#include <dht11.h>

#include <Wire.h>

#include <LiquidCrystal.h>

// #include <LiquidCrystal_I2C_Hangul.h>

#define DHT11PIN 6

int tempSensor = A1;
dht11 DHT11;
// LiquidCrystal_I2C_Hangul lcd(0x3F, 16, 2);
const int rs = 12,
  en = 11,
  d4 = 5,
  d5 = 4,
  d6 = 3,
  d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int alert = 13;

void showAlert(bool hot, bool humid) {
  if (!hot && !humid) {
    digitalWrite(alert, LOW);
  } else if (hot || humid) {
    digitalWrite(alert, HIGH);
    delay(1000);
    digitalWrite(alert, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  // lcd.init();
  // lcd.backlight();

  // led to alert high temperature and high humidity
  pinMode(alert, OUTPUT);
}

void loop() {
  int check = DHT11.read(DHT11PIN);
  float readTemp = analogRead(tempSensor);
  float volt = readTemp * 5 / 1023;
  float temperature = volt * 100;
  // float temperature = DHT11.temperature;
  float humidity = DHT11.humidity;

  String data = Serial.readStringUntil('\n');

  Serial.print(temperature, 2);
  Serial.print(",");
  Serial.println(humidity, 2);

  // lcd to display current temperature
  String a = "Temp (C): " + String(temperature) + String(" ");
  String b = "Humid (%): " + String(humidity);
  String c = "HIGH TEMPERATURE";
  String d = "HIGH HUMIDITY   ";

  // alert node on Arduino
  bool highTemp = false;
  bool highHumid = false;

  if (temperature >= 30) {
    highTemp = true;
  }
  if (humidity >= 80) {
    highHumid = true;
  }

  if (data == "0") showAlert(false, false);
  else showAlert(highTemp, highHumid);

  if (highTemp) {
    lcd.setCursor(0, 0);
    lcd.print(c);
  } else if (!highTemp) {
    lcd.setCursor(0, 0);
    lcd.print(a);
  }

  if (highHumid) {
    lcd.setCursor(0, 1);
    lcd.print(d);
  } else if (!highHumid) {
    lcd.setCursor(0, 1);
    lcd.print(b);
  }

  delay(1000);
}