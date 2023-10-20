#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


DHT dht(D4, DHT11);

LiquidCrystal_I2C lcd(0x27, 16, 2);  



void setup() {

 
  
  lcd.begin();
  dht.begin();
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(0,1);
  lcd.print("Humid:");
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();



  lcd.setCursor(7, 0);
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(7, 1);
  lcd.print(humidity);
  lcd.print(" %");

  delay(1000); 
}
