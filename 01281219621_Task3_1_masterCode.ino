
#include <Wire.h>

// Pin assignments for the buttons
int button1 = 4;
int button2 = 5;

// Variables to store button states
int x = 0;
int y = 0;

void setup() {
  // Initialize I2C communication
  Wire.begin();

  // Set button pins as inputs
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  // Start I2C transmission to the device with address 10
  Wire.beginTransmission(10);

  // Read the state of the buttons
  x = digitalRead(button1);
  y = digitalRead(button2);

  // Send button state data over I2C
  Wire.write(x);
  Wire.write(y);

  // End I2C transmission
  Wire.endTransmission();

  // Delay to control the rate of transmission
  delay(150);
}