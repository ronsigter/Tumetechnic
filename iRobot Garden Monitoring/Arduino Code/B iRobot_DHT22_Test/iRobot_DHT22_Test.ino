#include "DHT.h"

#define DHTPIN      A0    // what pin we're connected to
#define DHTTYPE     DHT22 // type of Temperature Sensor

// Initialize library used
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // set up temperature sensor
  dht.begin();

  // set serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  DisplayTempHumid();
}

void DisplayTempHumid() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  { // Print data to the Serial

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println();
    Serial.print("Temp: ");
    Serial.print(t);
    Serial.print("C");
  }
}





