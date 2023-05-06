#include <Arduino.h>
#include <NewPing.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <string> 

#define TRIGGER_PIN  5
#define ECHO_PIN     18
#define MAX_DISTANCE 200

const char* ssid = "Cegal-Guest";
const char* password = "WorldClassService";
const char* endpoint = "http://Azure-Api.com";
const char* type = "Dual ultrasonic sensor module";
unsigned int id = rand();

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned int duration, distance; // variables for storing the ultrasonic sensor data



void setup() {
  Serial.begin(921600);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  
  distance = sonar.ping_cm();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 10){

    // POST the data to the endpoint
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(endpoint);

      // set content type to JSON
      http.addHeader("Content-Type", "application/json");
  
      // create JSON object and add the data
      String data = "{ \"Id\": " + String(id) + ", \n
                       \"Type\": " + type + "}";

      // send the data
      int httpResponseCode = http.POST(data);

      // check the response code
      if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
      }

      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      http.end();
    }
  }

    delay(500); // Wait half a second before taking next measurement
    
}