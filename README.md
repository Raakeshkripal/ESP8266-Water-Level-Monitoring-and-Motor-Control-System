#  ESP8266 Water Level Monitoring and Motor Control System

This project demonstrates how to use **three ultrasonic sensors** with an **ESP8266** to monitor water levels and automatically **control motors via relays**. The system is integrated with the **Blynk App** to allow **real-time monitoring and remote control**.

---

## 📌 Problem Statement

To monitor water levels using three ultrasonic sensors. If the water level drops below a predefined threshold, the corresponding motor is automatically turned on using a relay. The status is visualized and controlled using the **Blynk IoT Platform**.

---

## 🧰 Components Required

| Hardware              | Quantity |
|-----------------------|----------|
| Ultrasonic Sensor (HC-SR04) | 3        |
| ESP8266 (NodeMCU)     | 1        |
| 5V Relay Module       | 3        |
| Breadboard            | 1        |
| Jumper Wires          | As needed |
| Power Supply          | 1        |

---

## 💻 Software Used

- **Arduino IDE** – For coding and uploading the firmware to ESP8266.
- **Blynk App** – For IoT integration and monitoring (Template ID & Auth Token required).

---

## 🔌 Circuit Connections

Each ultrasonic sensor is connected to the ESP8266 as follows:

| Sensor | Trigger Pin | Echo Pin | Relay Pin | Threshold (cm) |
|--------|-------------|----------|-----------|----------------|
| 1      | D1          | D2       | D7        | 10             |
| 2      | D3          | D4       | D8        | 15             |
| 3      | D5          | D6       | D9        | 20             |

*Note: Update your Blynk `auth`, `ssid`, and `password` in the code.*

---

## 🧠 How It Works

1. **Measure Distance**: Each ultrasonic sensor continuously measures the water level (distance to surface).
2. **Threshold Check**: If the distance is **below the threshold**, the corresponding **motor turns ON** via the relay.
3. **Remote Monitoring**: The water levels and motor status can be monitored via the **Blynk App**.

---

## 🔧 Setup Instructions

1. Open the Arduino IDE and install the following libraries:
   - Blynk
   - ESP8266WiFi
   - SimpleTimer

2. Connect your ESP8266 to your PC and upload the code provided.

3. Open the **Blynk App**:
   - Create a new project.
   - Select **ESP8266** as the device.
   - Use the **Template ID** and **Auth Token** from the code.

4. Connect your relays and ultrasonic sensors as per the model circuit.

---

## 📱 Blynk Integration

- Monitor distance readings for each tank.
- Check the relay/motor status.
- Optionally, add switches or indicators in the app UI for manual override.

---

## 📦 Code Overview

- `getDistance()`: Measures distance using ultrasonic sensor.
- `checkWaterLevel()`: Called every second to decide whether to turn ON/OFF each motor.
- `Blynk.run()` & `timer.run()`: Ensures continuous monitoring and Blynk communication.

---

## 📈 Future Scope

- Add **notification alerts** on low water levels via Blynk.
- Visualize historical data with **graphs** in Blynk.
- Upgrade to **ESP32** for better performance and more IO pins.

---
