#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "";  // Wi-Fi network name
const char* password = "";  // Wi-Fi network password
const char* serverName = "";  // URL of the server to send data to
const int soilSensorPin = A0;  // Analog pin connected to the soil moisture sensor
const int relayPin = D1;  // Digital pin connected to the relay
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

void setup() {
  pinMode(relayPin, OUTPUT);  // Set relay pin as an output
  digitalWrite(relayPin, LOW);  // Turn off the relay initially
  Serial.begin(115200);  // Initialize the serial communication

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);  // Start connecting to the specified Wi-Fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WIFI...");  // Display connection status while waiting for connection
  }
  Serial.println("WIFI connected");  // Wi-Fi connection successful

  pinMode(soilSensorPin, INPUT);  // Set soil moisture sensor pin as an input
}

void loop() {
  int soilMoisture = analogRead(soilSensorPin);  // Read the analog value from the soil moisture sensor
  
  int soilMoisturePercentage = map(soilMoisture, 0, 1023, 0, 100);  // Map the analog value to a percentage value

  Serial.print("soil value: ");
  Serial.print(soilMoisture);
  Serial.print(" (");
  Serial.print(soilMoisturePercentage);
  Serial.println("%)");  // Print the soil moisture value and percentage to the serial monitor
  
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, serverName);  // Specify the target server for HTTP requests
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");  // Add the content type header

    String postData = "soilMoisture=" + String(soilMoisture) + "&soilMoisturePercentage=" + String(soilMoisturePercentage);  // Create the POST data string with soil moisture values

    int httpResponseCode = http.POST(postData);  // Send the POST request with the data to the server
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);  // Print the HTTP response code to the serial monitor
    http.end();  // Close the HTTP connection
  }

  if (soilMoisturePercentage > 70) {
    digitalWrite(relayPin, HIGH);  // Turn on the relay to activate the pump
    Serial.println("Pump on");  // Print a message indicating the pump is turned on
    delay(6000);  // Wait for 6 seconds
    Serial.println("Pump off");  // Print a message indicating the pump is turned off
    digitalWrite(relayPin, LOW);  // Turn off the relay
  }

  delay(3600000);  // Delay for 60 minutes 
}

