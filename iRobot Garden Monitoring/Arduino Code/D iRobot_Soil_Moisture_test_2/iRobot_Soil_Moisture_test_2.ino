#define SOIL_SENSOR A1

int soilMoistureValue = 0;
const int AirValue = 520; // USE VALUE FROM TEST 1
const int WaterValue = 260; // USE VALUE FROM TEST 2
int intervals = (AirValue - WaterValue) / 3;


void setup() {
  // set serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  DisplaySoilSensor();
}

void DisplaySoilSensor() {
  soilMoistureValue = analogRead(SOIL_SENSOR);

  Serial.print("SOIL IS: ");

  if (soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals))
  {
    Serial.println("Very Wet");
  }
  else if (soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
  {
    Serial.println("Wet");
  }
  else if (soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
  {
    Serial.println("Dry");;
  }
}




