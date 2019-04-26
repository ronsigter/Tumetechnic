/* THIS CODE IS FOR CALIBRATION OF SOIL MOISTURE SENSOR
 * 
 * 1. Open the serial port monitor and set the baud rate to 9600
 * 2. Record the sensor value when the probe is exposed to the air 
 *    as "Value 1". This is the boundary value of dry soil “Humidity: 0%RH”
 * 3. Take a cup of water and insert the probe into it 
 *    no further than the red line in the diagram  
 * 4. Record the sensor value when the probe is exposed to the water 
 *    as "Value 2". This is the boundary value of moist soil “Humidity: 100%RH”
 */
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
}
void loop() {
  int val;
  val = analogRead(0); //connect sensor to Analog 0
  Serial.print(val); //print the value to serial port
  delay(100);
}




