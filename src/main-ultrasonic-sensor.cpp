#include <Arduino.h>
#include <NewPing.h>


 
#define TRIGGER_PIN  5
#define ECHO_PIN     18
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.print("Tester");
  Serial.begin(921600);
  Serial.print("G1");
}

void loop() {
  
  unsigned int distance = sonar.ping_cm();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 10){
    
  }

  delay(500); // Wait half a second before taking next measurement
}

