#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHT_PIN      18
#define DHT_TYPE     DHT22

#define GREEN_LED    15
#define YELLOW_LED   16
#define RED_LED      17

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(8, 9);     // Same as original
  lcd.init();
  lcd.backlight();

  dht.begin();

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Smart Env Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");

  delay(3000);
  lcd.clear();
}

void loop() {

  delay(2000);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (isnan(temperature) || isnan(humidity)) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    lcd.setCursor(0, 1);
    lcd.print("Check DHT22");

    for (int i = 0; i < 3; i++) {
      digitalWrite(RED_LED, HIGH);
      delay(200);
      digitalWrite(RED_LED, LOW);
      delay(200);
    }

    return;
  }

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print("C H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  if (temperature >= 40.0 || humidity >= 90.0) {

    lcd.print("Status: CRITICAL");
    digitalWrite(RED_LED, HIGH);

  }
  else if (temperature >= 35.0 || humidity >= 80.0) {

    lcd.print("Status: WARNING");
    digitalWrite(YELLOW_LED, HIGH);

  }
  else {

    lcd.print("Status: NORMAL");
    digitalWrite(GREEN_LED, HIGH);

  }
}
