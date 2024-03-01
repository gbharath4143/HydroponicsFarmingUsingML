# Hydroponic Farming Project

![Hydroponic Farming](hydroponic_image.jpg)

## Overview

Hydroponic farming is a soilless method of cultivating plants in a nutrient-rich water solution. This project aims to create an automated hydroponic farming system that monitors various parameters such as turbidity, pH value, TDS (Total Dissolved Solids) value, temperature, and water level. By utilizing microcontrollers, sensors, actuators, and machine learning algorithms, this system ensures optimal growing conditions for plants and enables efficient management of resources.

## Features

### Real-time Monitoring
- **Turbidity**: Measures the clarity of water by detecting suspended particles.
- **pH Value**: Determines the acidity or alkalinity of the nutrient solution.
- **TDS Value**: Indicates the concentration of dissolved solids in the water.
- **Temperature**: Monitors the temperature of the nutrient solution.
- **Water Level**: Tracks the water level in the hydroponic system.

### Automatic Control
- **Actuators**: Controls pumps, fans, and other devices based on sensor readings to maintain ideal growing conditions.
- **Thresholds**: Adjustable thresholds for each parameter to trigger automated actions, ensuring plants receive optimal care.

### Data Logging and Visualization
- **ThingSpeak Integration**: Data from sensors can be logged and visualized in real-time using ThingSpeak, a cloud-based IoT platform.
- **Custom Dashboards**: Alternatively, data can be logged and visualized using custom dashboards built with libraries like matplotlib or Plotly.

### Machine Learning-based Prediction
- **Optimal Farming Conditions**: Utilizes machine learning algorithms to predict optimal farming conditions based on historical sensor data, helping optimize plant growth and resource utilization.

## Components

- **Microcontrollers**: Arduino Uno, ESP8266.
- **Sensors**: Turbidity sensor, pH sensor, TDS sensor, Temperature sensor, Distance sensor.
- **Actuators**: Pumps, Fans.
- **Machine Learning Libraries**: scikit-learn (Python).
- **Communication Modules**: WiFi module, Serial communication.

## Setup Instructions

1. **Hardware Setup**:
   - Connect sensors, actuators, and microcontrollers according to the circuit diagram provided in the project documentation.

2. **Software Installation**:
   - Install the necessary libraries for Arduino and Python (if applicable).
   - Upload the Arduino sketches to the respective microcontrollers.
   - Install required Python packages using `pip install -r requirements.txt`.

3. **Configuration**:
   - Set up WiFi credentials and ThingSpeak API key in the Arduino and Python scripts.
   - Adjust sensor calibration values and control thresholds as needed.

4. **Run the System**:
   - Power on the hardware components.
   - Run the Python script for data processing and prediction.
   - Monitor the system behavior and adjust parameters if necessary.

## Contributing

Contributions to this project are welcome! If you find any issues or have ideas for improvements, please feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

