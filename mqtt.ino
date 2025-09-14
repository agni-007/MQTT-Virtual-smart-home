#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ESP32Servo.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

// Pin definitions
const int redLedPin = 17;
const int greenLedPin = 5;
const int servoPin = 19;
const int dhtPin = 18;

// DHT sensor setup
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(dhtPin, DHTTYPE);

// Servo motor setup
Servo myServo;

// Define MQTT topics
const char* redLedTopic = "esp32/redled/control";
const char* greenLedTopic = "esp32/greenled/control";
const char* servoTopic = "esp32/servo/control";
const char* dhtTopic = "esp32/dht/data";

// Time for publishing sensor data
long lastMsg = 0;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);

  if (strcmp(topic, redLedTopic) == 0) {
    if (message == "ON") {
      digitalWrite(redLedPin, HIGH);
    } else if (message == "OFF") {
      digitalWrite(redLedPin, LOW);
    }
  } else if (strcmp(topic, greenLedTopic) == 0) {
    if (message == "ON") {
      digitalWrite(greenLedPin, HIGH);
    } else if (message == "OFF") {
      digitalWrite(greenLedPin, LOW);
    }
  } else if (strcmp(topic, servoTopic) == 0) {
    int pos = message.toInt();
    if (pos >= 0 && pos <= 180) {
      myServo.write(pos);
    }
  }
}

void setup_wifi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Subscribe to all control topics
      client.subscribe(redLedTopic);
      client.subscribe(greenLedTopic);
      client.subscribe(servoTopic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  myServo.attach(servoPin);
  
  dht.begin();
  
  setup_wifi();
  
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Publish sensor data every 5 seconds
  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    // Check if any reads failed
    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    // Prepare JSON payload
    String jsonPayload = "{\"temperature\": " + String(t) + ", \"humidity\": " + String(h) + "}";
    
    // Publish the JSON payload
    client.publish(dhtTopic, jsonPayload.c_str());
    Serial.print("Published DHT data: ");
    Serial.println(jsonPayload);
  }
}