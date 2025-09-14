<img width="750" height="350" align="center" alt="Image" src="https://github.com/user-attachments/assets/9a6cd590-4368-4e06-9685-4e7d2b400ef4" />


# 🏡 Virtual Smart Home with MQTT

This project creates a **simulated smart home system** using a virtual ESP32 microcontroller within the **Wokwi online simulator**.  
It demonstrates the **MQTT (Message Queuing Telemetry Transport)** protocol with **bidirectional communication** between a microcontroller, a web dashboard, and a mobile app.

---

## 💡 Project Highlights

- **Virtual Prototyping**  
  Designed and simulated entirely online using **Wokwi**, eliminating the need for physical hardware.

- **Bidirectional Communication**  
  Uses the **MQTT protocol** to allow a Node-RED dashboard and a mobile app to **remotely control actuators** (LEDs, servo motor) and **monitor sensor data** in real-time.

- **Platform-Independent Control**  
  Integrated with a **mobile MQTT client app**, enabling monitoring and control from a smartphone.

- **Hands-on IoT Experience**  
  Practical exposure to the **complete IoT stack**, from embedded programming to user interface design.

---

## ⚙️ System Architecture

The system is built around a **central MQTT broker** that connects three main clients:

- **ESP32 Microcontroller**
  - Publishes sensor data (e.g., DHT22).
  - Subscribes to control commands (LEDs, servo motor).
  - Acts as the interface to virtual hardware.

- **Node-RED Dashboard**
  - Web-based interface for monitoring and control.
  - Publishes commands via switches and sliders.
  - Subscribes to sensor topics for real-time display.

- **Mobile MQTT Client App**
  - Provides remote access from a smartphone.
  - Performs the same functions as Node-RED.
 
  <img width="850" height="300" alt="Image" src="https://github.com/user-attachments/assets/d63ce600-3c02-4cbe-a5cf-96f183179590" />

### 🔄 Communication Flow (Publish-Subscribe Model)

- Example:  
  - **Node-RED Switch** → Publishes MQTT message → **ESP32** receives and executes action.  
  - **ESP32 Sensor Data** → Publishes to topic → Subscribed by **Node-RED & Mobile App** → Displayed in real-time.

---

<img width="350" height="250" alt="Image" src="https://github.com/user-attachments/assets/5dd5b51f-55e4-4dad-bb2c-55499a3b5c80" />

## 💻 Tools & Technologies

- **Wokwi** – ESP32 simulation platform.  
- **Arduino IDE** – For writing ESP32 C++ code.  
- **Node-RED** – Drag-and-drop visual dashboard.  
- **MQTT Client App (Android)** – Remote control and monitoring.  
- **MQTT Protocol** – Core communication model.  
- **HiveMQ Broker** – Public MQTT broker used.

---

## 🔌 Virtual Hardware Components

- **ESP32** – Central processing & Wi-Fi module.  
- **Green & Red LEDs** – Remotely controlled output devices.  
- **Servo Motor** – Simulates door/window control.  
- **DHT22 Sensor** – Provides temperature & humidity data.  

---
# The circuit diagram is shown below

<img width="500" height="350" alt="Image" src="https://github.com/user-attachments/assets/61de8534-1aac-49ab-95b0-a61138ea0e24" />

