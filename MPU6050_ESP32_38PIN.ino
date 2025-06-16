#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  // SDA = GPIO21, SCL = GPIO22

  byte status = mpu.begin();
  Serial.print("MPU6050 status: ");
  Serial.println(status);
  while (status != 0) {
    Serial.println("MPU6050 initialization failed!");
    delay(1000);
  }

  Serial.println("MPU6050 ready!");
  delay(1000);
  mpu.calcOffsets(); // calibrate
}

void loop() {
  mpu.update();

  Serial.print("Angle X: ");
  Serial.print(mpu.getAngleX());
  Serial.print(" | Angle Y: ");
  Serial.print(mpu.getAngleY());
  Serial.print(" | Angle Z: ");
  Serial.println(mpu.getAngleZ());

  delay(500);
}
