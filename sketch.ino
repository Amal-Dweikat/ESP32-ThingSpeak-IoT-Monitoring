
#include <WiFi.h>
#include "ThingSpeak.h"
#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22

const char* WIFI_Name = "Wokwi-GUEST";
const char* WIFI_Pass = "";

const int channelNumber = 3549872;
const char* apikey = "OW2EC9KU8MROTJ9B";
const char* universityID = "12323876";

WiFiClient clientObject;
DHT sensorDHT(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  sensorDHT.begin();

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_Name, WIFI_Pass);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println();
  Serial.println("Status: Connected");

  ThingSpeak.begin(clientObject);

  Serial.print("University ID: ");
  Serial.println(universityID);
}

void loop() {
  float temperature = sensorDHT.readTemperature();
  float humidity = sensorDHT.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT22!");
    delay(15000);
    return;
  }

  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);

  Serial.println("Sending data to ThingSpeak...");

  int status = ThingSpeak.writeFields(channelNumber, apikey);

  if (status == 200) {
    Serial.println("Data Sent to ThingSpeak");
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
  } else {
    Serial.print("Problem updating channel. HTTP error code: ");
    Serial.println(status);
  }

  delay(15000);
}
