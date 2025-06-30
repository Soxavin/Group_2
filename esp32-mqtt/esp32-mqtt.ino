#include <Wire.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// I2C BMP280
Adafruit_BMP280 bmp;

const char* ssid = ""; // wifi name
const char* password = ""; //wifi pw

const char* mqtt_server = ""; // replace with your MQTT broker IP
const char* mqtt_user = ""; // Only if auth is required
const char* mqtt_pass = "";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");

    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println("connected");
    } else {
      Serial.print("failed: ");
      Serial.print(client.state()); 
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);

  if (!bmp.begin(0x77)) {  // 0x76 or 0x77 depending on your module
    Serial.println("Could not find BMP280 sensor!");
    while (1);
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure(); // hPa
  float altitude = bmp.readAltitude(); 

  String payload = "{\"temperature\": " + String(temperature, 2) +
                   ", \"pressure\": " + String(pressure, 2) + 
                   ", \"altitude\": " + String(altitude, 2) + "}";
  
  client.publish("sensor/bmp280", payload.c_str());
  Serial.println("Published: " + payload);

  delay(5000); // send every 5 seconds
}
