# ESP32-Based Temperature and Humidity Monitoring System

## 1. Project Description

This project is an IoT-based temperature and humidity monitoring system using an ESP32 microcontroller and a DHT22 sensor. The system reads temperature and humidity values and sends them to ThingSpeak, an IoT cloud platform, where the collected data is displayed using graphs.

The project is implemented and tested using the Wokwi online simulator.

## 2. Project Objectives

- Measure temperature in degrees Celsius (°C).
- Measure relative humidity as a percentage (%).
- Connect the ESP32 to Wi-Fi.
- Send sensor readings to ThingSpeak every 15 seconds.
- Display temperature and humidity data using ThingSpeak charts.

## 3. Components Used

- ESP32 microcontroller.
- DHT22 temperature and humidity sensor.
- Wokwi online simulator.
- ThingSpeak IoT cloud platform.
- Wi-Fi connection.

## 4. Circuit Connections

The DHT22 sensor is connected to the ESP32 as follows:

| DHT22 Pin | ESP32 Pin |
|---|---|
| VCC | 3V3 |
| DATA | GPIO 15 |
| GND | GND |

## 5. Software and Libraries

The project uses the following libraries:

- WiFi.h
- ThingSpeak.h
- DHT.h
- Adafruit Unified Sensor

## 6. How the System Works

1. The ESP32 initializes the DHT22 sensor.
2. The ESP32 connects to the Wi-Fi network.
3. The sensor measures temperature and humidity.
4. The ESP32 sends the readings to ThingSpeak.
5. ThingSpeak stores the received values and displays them in two charts.
6. The process repeats every 15 seconds.

Field 1 is used for temperature, and Field 2 is used for humidity.

## 7. Simulation and Results

**Wokwi Simulation:**  
https://wokwi.com/projects/478866576960140289

**ThingSpeak Public Channel:**  
https://thingspeak.mathworks.com/channels/3549872

The Serial Monitor confirms that the ESP32 connects to Wi-Fi and successfully sends sensor readings to ThingSpeak.

The simulated sensor currently reports approximately 24°C and 40% humidity. The charts may appear nearly horizontal while the simulated sensor values remain unchanged.

## 8. Screenshots

Screenshots showing the simulation, Serial Monitor output, and ThingSpeak charts are included in the project repository.

## 9. Student Information

Student Name: amal dwekat

University ID: 12323876



