# ESP8266 Wi-Fi Data Logging to ThingSpeak

## Overview
This project demonstrates a method for utilizing an ESP8266 microcontroller to collect sensor data and transmit it to the ThingSpeak IoT platform via Wi-Fi. The provided code establishes a connection to a Wi-Fi network, reads incoming data from the serial port, parses it, and sends it to ThingSpeak using HTTP POST requests.

## Hardware Requirements
- **ESP8266 Microcontroller**: Any ESP8266 board such as NodeMCU.
- **Sensors**: Sensors capable of data acquisition (e.g., temperature, humidity, etc.).
- **USB Cable**: For programming the ESP8266 and supplying power.

## Software Requirements
- **Arduino IDE (or Compatible Development Environment)**: Required for programming the ESP8266.
- **ESP8266WiFi Library**: To enable Wi-Fi communication with the ESP8266.

## Installation Steps
1. **Connect ESP8266**: Connect the ESP8266 microcontroller to your computer using a USB cable.
2. **Open Arduino IDE**: Open the Arduino IDE (or any compatible development environment).
3. **Install ESP8266 Board Package**: If not already installed, install the ESP8266 board package via the Arduino IDE's Board Manager.
4. **Download Required Libraries**: Download and install the ESP8266WiFi library from the Arduino Library Manager.
5. **Copy Code**: Copy the provided code (`ESP8266_Data_Logging.ino`) into a new sketch in the Arduino IDE.
6. **Configure Settings**: Modify the `apiKey`, `ssid`, and `pass` variables in the code to match your ThingSpeak API key and Wi-Fi credentials.
7. **Upload Sketch**: Upload the modified sketch to the ESP8266 microcontroller.

## Usage Instructions
1. **Sensor Connection**: Ensure that your sensors are correctly connected to the ESP8266 microcontroller and configured as per your requirements.
2. **Monitor Serial Data**: Open the serial monitor in the Arduino IDE (or any serial communication tool) to monitor the data being sent to the ESP8266.
3. **Send Data to ESP8266**: Send data over the serial port to the ESP8266 microcontroller in the following format: `aValue1bValue2cValue3dValue4`, where `Value1`, `Value2`, `Value3`, and `Value4` represent the sensor readings.
4. **Data Transmission**: The ESP8266 microcontroller will receive, format, and transmit the data to ThingSpeak using HTTP POST requests.
5. **View Data on ThingSpeak**: Check your ThingSpeak channel dashboard to visualize and analyze the transmitted data.

## Configuration Parameters
- **`apiKey`**: Your ThingSpeak API key.
- **`ssid`**: SSID (name) of the Wi-Fi network.
- **`pass`**: Password of the Wi-Fi network.

## Troubleshooting
- **Wi-Fi Connection**: If the ESP8266 fails to connect to the Wi-Fi network, double-check the SSID and password settings.
- **Data Format**: Ensure that the serial data sent to the ESP8266 adheres to the correct format and delimiter for successful parsing.

## Contributing
Contributions to this project are encouraged. Feel free to fork this repository, implement improvements, and submit pull requests to enhance the functionality.

## License
This project is licensed under the [MIT License](LICENSE).
