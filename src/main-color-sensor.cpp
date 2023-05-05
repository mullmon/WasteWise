#include <Arduino.h>

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