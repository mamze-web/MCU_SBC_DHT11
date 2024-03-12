#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2      
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C 주소는 0x27인 경우, 16x2 LCD 모듈

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  delay(2000);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error reading DHT!");
    return;
  }

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Temperature: ");
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0, 2);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");
}
