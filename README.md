# 🌡️ IoT Smart Environmental Monitor

An ESP32-based Smart Environmental Monitor that measures temperature and humidity using a DHT22 sensor. The system displays real-time readings on a 16x2 I2C LCD and the Serial Monitor while using Green, Yellow, and Red LEDs to indicate Normal, Warning, and Critical environmental conditions.

---

## 📌 Project Overview

This project is designed to monitor environmental conditions using an ESP32 microcontroller and a DHT22 temperature and humidity sensor. The measured values are displayed on both the I2C LCD and the Serial Monitor. Three LEDs provide a quick visual indication of the current environmental status.

---

## 🎯 Features

- Real-time Temperature Monitoring
- Real-time Humidity Monitoring
- 16x2 I2C LCD Display
- Serial Monitor Output
- Green LED for Normal Condition
- Yellow LED for Warning Condition
- Red LED for Critical Condition
- Sensor Error Detection

---

## 🛠 Components Used

- ESP32 Development Board
- DHT22 Temperature & Humidity Sensor
- 16x2 I2C LCD
- Green LED
- Yellow LED
- Red LED
- 220Ω Resistors
- Jumper Wires

---

## 🔌 Circuit Connections

| Component | ESP32 Pin |
|-----------|-----------|
| DHT22 Data | GPIO18 |
| Green LED | GPIO15 |
| Yellow LED | GPIO16 |
| Red LED | GPIO17 |
| LCD SDA | GPIO8 |
| LCD SCL | GPIO9 |
| LCD VCC | 5V |
| LCD GND | GND |

---

## ⚙️ Working Principle

1. The ESP32 reads temperature and humidity data from the DHT22 sensor every 2 seconds.
2. The sensor readings are displayed on the I2C LCD.
3. The same readings are printed on the Serial Monitor.
4. The LEDs indicate the environmental condition:
   - 🟢 Green LED → Normal
   - 🟡 Yellow LED → Warning
   - 🔴 Red LED → Critical
5. If the sensor fails to respond, an error message is displayed and the Red LED blinks.

---

## 📷 Project Images

### Circuit Diagram

> Add your Wokwi circuit screenshot here.

### LCD Output

> Add a screenshot of the LCD displaying temperature and humidity.

### Serial Monitor Output

> Add a screenshot of the Serial Monitor.


## 🚀 Future Improvements

- Wi-Fi Connectivity
- IoT Cloud Integration (ThingSpeak/Blynk)
- Mobile Notifications
- Data Logging
- Web Dashboard


## ⭐ If you found this project useful, don't forget to star the repository!
