#include <Arduino.h>
#include <NewPing.h>

////////////// color sensor
// // Define the GPIO pins for the TCS3200 color sensor
// #define S0_PIN 12
// #define S1_PIN 14
// #define S2_PIN 27
// #define S3_PIN 26
// #define OUT_PIN 25

// void setup() {
//   // Set the GPIO pins for the TCS3200 color sensor as outputs
//   Serial.begin(921600);
//   delay(1000);
//   Serial.println("enter setup");
//   pinMode(S0_PIN, OUTPUT);
//   pinMode(S1_PIN, OUTPUT);
//   pinMode(S2_PIN, OUTPUT);
//   pinMode(S3_PIN, OUTPUT);

//   // Set the GPIO pin for the TCS3200 color sensor output as input
//   pinMode(OUT_PIN, INPUT);
// }

// void loop() {
//   Serial.println("enter loop");
//   // Set the frequency scaling of the TCS3200 color sensor to 20%
//   digitalWrite(S0_PIN, LOW);
//   digitalWrite(S1_PIN, HIGH);

//   // Set the color sensing mode of the TCS3200 color sensor to blue
//   digitalWrite(S2_PIN, LOW);
//   digitalWrite(S3_PIN, HIGH);

//   // Read the color value from the TCS3200 color sensor output pin
//   int colorValue = digitalRead(OUT_PIN);

//   // Do something with the color value...
//   Serial.println("color: " + colorValue);
//   delay(1000);







// Set the GPIO pins for the TCS3200
const int S0 = 26;
const int S1 = 27;
const int S2 = 14;
const int S3 = 12;
const int OUT = 13;

void setup() {
  // Set the GPIO pins as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  
  // Set the frequency scaling to 20%
  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH);

  // Set the color sensing mode to blue
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  Serial.begin(921600);
}

// endrer noe
void loop() {
  // Read the color value
  int red = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  int green = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);
  int blue = pulseIn(OUT, digitalRead(OUT) == HIGH ? LOW : HIGH);

  // Print the color value
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" Green: ");
  Serial.print(green);
  Serial.print(" Blue: ");
  Serial.println(blue);
  
  delay(5000);
}





//////////////// ultrasonic sensor
// Define the pins
// const int trigPin = 12;
// const int echoPin = 14;

 

// void setup() {
//   // Initialize serial communication
//   Serial.begin(921600);

 

//   // Define the pins as input/output
//   pinMode(trigPin, OUTPUT);
//   pinMode(echoPin, INPUT);
// }

 

// void loop() {
//   // Send a pulse to the sensor
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

 

//   // Calculate the distance based on the time it takes for the echo to return
//   long duration = pulseIn(echoPin, HIGH);
//   int distance = duration * 0.034 / 2;

 

//   // Print the distance to the serial monitor
//   Serial.print("Distance: ");
//   Serial.print(distance);
//   Serial.println(" cm");

 

//   // Wait a short time before taking another measurement
//   delay(100);



// #include <NewPing.h>

 

// #define TRIGGER_PIN  5
// #define ECHO_PIN     18
// #define MAX_DISTANCE 200
// NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

 

 

// void setup() {
//   Serial.print("Tester");
//   Serial.begin(921600);
//   Serial.print("G1");
// }

 

// void loop() {
  
//   unsigned int distance = sonar.ping_cm();

//   Serial.print("Distance: ");
//   Serial.print(distance);
//   Serial.println(" cm");

//   delay(500); // Wait half a second before taking next measurement
// }

