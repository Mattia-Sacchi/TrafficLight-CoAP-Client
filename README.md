# 🚦 Traffic Light Controller

## 📝 Overview

This is a desktop application built using Qt that controls a traffic light system via WiFi. It communicates with an Arduino Uno R4 WiFi using the CoAP (Constrained Application Protocol) to send commands and configure timing parameters.

## 📌 Requirements  
This project interface to **Traffic Light Project** on Arduino:  
➡ [Download Traffic Light Project](https://github.com/Mattia-Sacchi/TrafficLights-Project/)

## ✨ Features

- 📡 Connects to an Arduino traffic light system via CoAP.
- 🔄 Supports manual and automatic control modes.
- ⏳ Adjustable red, yellow, and green light durations.
- ⚙️ Configurable communication settings, including frequency.
- 📊 Random and strobe behavior command (just for fun)

## 📋 Requirements

### 🖥️ Software Dependencies

- Qt 6 (or Qt 5 with networking support)
- CoAP library for Qt
- You need to build locally Qt from source because CoAP module isn't installed by default
- Arduino IDE (for firmware updates)

### 🔌 Hardware Requirements

- Arduino Uno R4 WiFi
- Traffic light system (LEDs and appropriate circuitry)
- WiFi network for communication

## 🔧 Installation

1. Clone the repository:
   ```sh
   git clone git@github.com:Mattia-Sacchi/TrafficLight-CoAP-Client.git
   ```
2. Open the project in Qt Creator
3. Run the application

## ⚙️ Configuration

- **📡 Address**: IP address of the Arduino device (default: `192.168.4.1`).
- **🛠️ Command Mode**: Select manual or automatic operation.
- **📶 Frequency**: Set time in ms for Blinking/Strobe state.
- **🚦 Red, Yellow, Green Time**: Adjust individual light durations.

## 📡 Communication Protocol

- Uses CoAP to send control commands to the Arduino.
- Example CoAP message:
  ```json
  "CoAP put --> {\"cmd\":2,\"timings\":[5000,1000,7000]}"
  ```
- The Arduino processes these values and updates the traffic light sequence accordingly.

## 🚀 Usage

1. Start the application.
2. Enter the IP address of the Arduino Uno R4 WiFi.
3. Select the control mode (Manual/Automatic/Blinking/Strobe/Random).
4. Adjust the traffic light timing as needed.
5. Click **Send** to apply settings.
6. In Manual and blinking mode, send button is not needed just click on the lights

# Proof of Concept:
You can find a video in the docs folder showing the functioning of the project
![Image](https://github.com/Mattia-Sacchi/TrafficLight-CoAP-Client/blob/master/Docs/Screenshot%20from%202025-02-21%2022-03-06.png)
