# iot-esp8266


### Introduction
The IoT Soil Moisture Monitoring and Pump Control system allows you to monitor the soil moisture level using an ESP8266-based microcontroller and control a pump based on the moisture level. This user manual provides an overview of the system, its components, and instructions on how to set it up and use it.

### System Components
1. ESP8266 Microcontroller: The ESP8266 microcontroller board is the main component of the system. It handles the soil moisture sensing, data transmission, and pump control.
2. Soil Moisture Sensor: The system uses an analog soil moisture sensor to measure the moisture level in the soil.
3. Relay: The relay is used to control the pump. It can be connected to the microcontroller to turn the pump on or off.
4. Wi-Fi Network: The system requires a Wi-Fi network to connect to the internet and send data to a server.

### Setup Instructions
Follow these steps to set up the IoT Soil Moisture Monitoring and Pump Control system:

1. Hardware Connections:
   - Connect the soil moisture sensor to the analog pin A0 on the ESP8266 microcontroller.
   - Connect the relay to the digital pin D1 on the microcontroller.

2. Software Setup:
   - Install the Arduino IDE software on your computer.
   - Open the Arduino IDE and go to "Sketch" -> "Include Library" -> "Manage Libraries."
   - Install the following libraries:
     - "ESP8266WiFi" library
     - "ESP8266HTTPClient" library
     - "WiFiClient" library

3. Configure Wi-Fi and Server Settings:
   - Open the code file provided in the Arduino IDE.
   - Modify the `ssid` and `password` variables to match your Wi-Fi network credentials.
   - Update the `serverName` variable to the URL of the server where you want to send the data.

4. Upload the Code:
   - Connect the ESP8266 microcontroller to your computer using a USB cable.
   - Select the appropriate board and port in the Arduino IDE.
   - Click on the "Upload" button to upload the code to the microcontroller.

5. Monitor Soil Moisture and Control Pump:
   - Open the serial monitor in the Arduino IDE to view the system's output.
   - The system will connect to the Wi-Fi network and display "WIFI connected" when connected successfully.
   - The serial monitor will show the soil moisture value and percentage.
   - The system will send the data to the specified server using an HTTP POST request.
   - If the soil moisture percentage is above 70%, the system will turn on the pump for 6 seconds and then turn it off.

### Troubleshooting
- If the Wi-Fi connection fails, ensure that the `ssid` and `password` variables are set correctly.
- If the server connection fails, verify that the `serverName` variable points to the correct server URL and that the server is accessible.
- If the pump control does not work, check the relay connection and make sure it is connected to the correct pin.

### Safety Precautions
- Ensure that the pump and its power source are suitable for the intended use and comply with safety regulations.
- Take caution when working with electrical connections to avoid electric shocks or short circuits.
- Follow local

 regulations and guidelines for using electronic devices and water pumps.

### Conclusion
The IoT Soil Moisture Monitoring and Pump Control system provides a convenient way to monitor and control soil moisture levels. By following the setup instructions and using the provided code, you can easily set up the system and automate the pump control based on the soil moisture conditions. Enjoy your smart gardening experience!

