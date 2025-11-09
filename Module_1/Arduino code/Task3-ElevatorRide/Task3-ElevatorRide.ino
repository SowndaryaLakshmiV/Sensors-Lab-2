#include "Arduino_BHY2.h"

#define sensitivity_accel 4096/9.81 
#define interval 100 // in milliseconds

Sensor pressure(SENSOR_ID_BARO);
SensorXYZ accel(SENSOR_ID_ACC_PASS);

unsigned long prev_timestamp = 0;

void setup() {
  Serial.begin(115200);
  BHY2.begin();
  pressure.begin();
  accel.begin();
}

void loop() {
  BHY2.update();
  unsigned long current_timestamp = millis();

  if (current_timestamp - prev_timestamp >= interval) {
    prev_timestamp = current_timestamp;  

    float accel_valueZ = accel.z() / sensitivity_accel;

    Serial.print("Timestamp: ");
    Serial.print(current_timestamp);
    Serial.print(" Acceleration in z-axis:");
    Serial.print(accel_valueZ);
    Serial.print(" Pressure:");
    Serial.println(pressure.value());
  }
}
