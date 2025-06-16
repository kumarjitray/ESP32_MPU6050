# MPU6050 with ESP32 Wroom (38 Pin) – Angle Measurement Project

This project demonstrates how to interface an **MPU6050 (6-axis accelerometer and gyroscope)** with an **ESP32 Wroom (38-pin)** board using the **MPU6050_light** library to read orientation angles (X, Y, Z).

---

## 📦 Required Hardware

- ESP32 Dev Module (38-pin version)
- MPU6050 IMU sensor module
- Jumper wires
- Arduino IDE (with ESP32 board support installed)

---

## 🔌 Pin Connections

| MPU6050 Pin | ESP32 Wroom Pin | Description     |
|-------------|------------------|-----------------|
| VCC         | 3.3V             | Power supply    |
| GND         | GND              | Ground          |
| SDA         | GPIO21           | I2C Data line   |
| SCL         | GPIO22           | I2C Clock line  |

> ⚠️ Ensure your MPU6050 is **3.3V-compatible**, or use a **logic level shifter**.

---

## 📚 Required Libraries

Install the following library via the Arduino Library Manager:

- [`MPU6050_light` by Richard Feliciano (rfetick)](https://github.com/rfetick/MPU6050_light)

To install:
1. Go to **Arduino IDE → Tools → Manage Libraries**.
2. Search for `MPU6050_light`.
3. Click **Install**.

---

## 🔧 ESP32 Board Setup in Arduino IDE

1. Go to **File > Preferences**, and add this to the "Additional Board URLs":
```https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json```

2. Go to **Tools > Board > Board Manager**, search for `esp32`, and install the **ESP32 by Espressif Systems** package.

3. Select your board: **ESP32 Dev Module**

---

## 🧠 How It Works

- The MPU6050 is initialized via I2C communication.
- The sensor is calibrated during startup.
- The code continuously reads orientation angles (X, Y, Z) from the MPU6050.

---

## 📄 Working Code

```cpp
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
```

