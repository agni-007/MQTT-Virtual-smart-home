<img width="1024" height="512" alt="Image" src="https://github.com/user-attachments/assets/9a6cd590-4368-4e06-9685-4e7d2b400ef4" />



🏡 Virtual Smart Home with MQTT
This project creates a simulated smart home system using a virtual ESP32 microcontroller within the Wokwi online simulator. It's a comprehensive demonstration of the MQTT (Message Queuing Telemetry Transport) protocol, showcasing bidirectional communication between a microcontroller, a web dashboard, and a mobile app.

💡 Project Highlights
Virtual Prototyping: The entire hardware and software system was designed and simulated online using the Wokwi platform, eliminating the need for physical components.

Bidirectional Communication: The system uses the MQTT protocol to allow a Node-RED dashboard and a mobile app to remotely control virtual actuators (LEDs and a servo motor) and monitor sensor data in real-time.

Platform-Independent Control: A mobile MQTT client app was integrated to prove the system's platform-independent nature, enabling control and monitoring from a smartphone.

Hands-on IoT Experience: This project provided a practical understanding of the full IoT stack, from embedded programming to user interface design.

⚙️ System Architecture
The system is built around a central MQTT broker that acts as a communication hub, connecting three main clients:

ESP32 Microcontroller: The device client that publishes sensor data and subscribes to control commands. It's the physical interface to the virtual hardware, like the DHT22 sensor, LEDs, and servo motor.

Node-RED Dashboard: A web-based user interface client that publishes commands from switches and sliders and subscribes to sensor data for display.

Mobile MQTT Client: A smartphone app that performs the same functions as the Node-RED dashboard, providing remote access to the system.

The project's communication relies on the publish-subscribe model of MQTT. For example, when you toggle a switch on the Node-RED dashboard, it publishes a message to a specific MQTT topic, which the ESP32 is subscribed to, triggering the action on the virtual hardware. Similarly, the ESP32 publishes sensor data to a topic that the dashboard and mobile app are subscribed to, allowing them to display the values in real-time.

💻 Tools & Technologies
Wokwi: The primary tool for simulating the ESP32 circuit and running the embedded code online.

Arduino IDE: Used for writing the C++ code for the ESP32 microcontroller.

Node-RED: A visual programming tool used to build the drag-and-drop web dashboard for control and monitoring.

MQTT Client App (on Android): Used to demonstrate platform independence and provide remote control via a smartphone.

MQTT Protocol: The core communication protocol for the entire system, enabling the publish-subscribe model.

HiveMQ Broker: The public MQTT broker used to facilitate communication between all clients.

🔌 Virtual Hardware Components
The Wokwi simulation included the following virtual components:

ESP32: The central processing unit and Wi-Fi module.

Green & Red LEDs: Virtual output devices controlled remotely.

Servo Motor: An actuator whose position is remotely controlled, simulating a door or window.

DHT22 Sensor: A sensor that provides virtual temperature and humidity data.
