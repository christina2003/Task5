#include <Wire.h>

// LED pin assignment
int LED = 6;

// Variables to store received button state data
int x = 0;
int y = 0;

// Function declaration for receiving button state data
void receiveCondition(int);

void setup() {
  // Initialize I2C communication as a slave with address 10
  Wire.begin(10);

  // Register the receiveCondition() function as the callback for I2C data reception
  Wire.onReceive(receiveCondition);

  // Initialize Serial communication for debugging
  Serial.begin(9600);

  // Set LED pin as an output
  pinMode(LED, OUTPUT);
}

void loop() {
  // Delay to allow the main loop to run smoothly
  delay(50);
}

// Callback function for receiving button state data over I2C
void receiveCondition(int) {
  // Read the received button state data
  x = Wire.read();
  y = Wire.read();

  // Control the LED intensity based on the received button state
  if (x == 1 && y == 0) {
    analogWrite(LED, 128);
    Serial.println("Vector Focused");
  } 
  else if (x == 0 && y == 1) {
    analogWrite(LED, 192);
    Serial.println("Vector distracted");
  }
  else if (x == 1 && y == 1) {
    analogWrite(LED, 255);
    Serial.println("Glitch");
  }
  else {
    analogWrite(LED, 0);
  }
}