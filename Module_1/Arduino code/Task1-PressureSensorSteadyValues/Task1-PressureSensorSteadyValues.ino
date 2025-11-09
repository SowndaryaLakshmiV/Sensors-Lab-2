#include "Arduino_BHY2.h"
Sensor pressure(SENSOR_ID_BARO);

int count = 0;
unsigned long prev_timestamp = 0;

void setup() {
  Serial.begin(115200);
  BHY2.begin();
  pressure.begin();
}

void loop() {
  BHY2.update();
  unsigned long current_timestamp = millis();

  if (current_timestamp - prev_timestamp >= 100) {
    prev_timestamp = current_timestamp;

    Serial.print("Timestamp: ");
    Serial.print(current_timestamp);
    Serial.print(" Pressure:");
    Serial.println(pressure.value());

    count++;
    if(count >= 1000) {
      exit(0);
    }
  }
}
