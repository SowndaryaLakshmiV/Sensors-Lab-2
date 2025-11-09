#include "Arduino_BHY2.h"
#include "Arduino.h"

#define sensitivity_accel 9.81/4096 
#define interval 100

SensorXYZ accel(SENSOR_ID_ACC_PASS);

unsigned long previous_timestamp = 0;
int count = 0;

void setup() {
  Serial.begin(115200);
  BHY2.begin();
  accel.begin();
}

void loop() {
  BHY2.update();
  unsigned long current_timestamp = millis();

  float accel_valueX = accel.x() * sensitivity_accel;
  float accel_valueY = accel.y() * sensitivity_accel;
  float accel_valueZ = accel.z() * sensitivity_accel;

  if (current_timestamp - previous_timestamp >= interval) {
    previous_timestamp = current_timestamp;
    
    Serial.print("Timestamp: ");
    Serial.print(current_timestamp);
    Serial.print(" Accel X:");
    Serial.print(accel_valueX);
    Serial.print(" Accel Y:");
    Serial.print(accel_valueY);
    Serial.print(" Accel Z:");
    Serial.println(accel_valueZ);

    count++;
    if (count >= 1000) {
      exit(0);
    }
  }
}
