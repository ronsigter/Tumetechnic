#include <LiquidCrystal.h>
#include "DHT.h"

#define SOIL_SENSOR A1

#define DHTPIN      A0    // what pin we're connected to
#define DHTTYPE     DHT22 // type of Temperature Sensor

// Initialize library used
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int soilMoistureValue = 0;
const int AirValue = 520;
const int WaterValue = 260;
int intervals = (AirValue - WaterValue) / 3;

uint8_t cont = 100;

// Setup Timer for Display Changes
unsigned long previousMillis = 0;
const long interval = 3000;       // interval in milliseconds
int Display = 1;
 
void setup() {
  // set up LCD screen
  lcd.begin(16, 2);
  analogWrite(9, cont);

  // set up temperature sensor
  dht.begin();

  // set serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you change Display
    previousMillis = currentMillis;

    switch (Display) {
      case 1:
        DisplaySoilSensor();
        Display = 2;
        break;
      case 2:
        DisplayTempHumid();
        Display = 1;
        break;
    }
  }
}

void DisplaySoilSensor() {
  soilMoistureValue = analogRead(SOIL_SENSOR);

  lcd.setCursor(0, 0);
  lcd.print("SOIL IS");
  lcd.setCursor(0, 1);

  if (soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
  {
    lcd.println("Very Wet");
  }
  else if (soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
  {
    lcd.println("Wet");
  }
  else if (soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
  {
    lcd.println("Dry");;
  }
}

void DisplayTempHumid() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h))
  {
    lcd.println("Failed to read from DHT");
  }
  else
  { // Print data to the LCD.
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print((char)223);
    lcd.print("C");
  }
}



