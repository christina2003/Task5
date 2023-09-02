#include <NewPing.h> //library allow interface between ultrasonic sensors

// Pin configurations for ultrasonic sensors
const int trigPin1 = 2;  // Trigger pin for sensor 1 (forward)
const int echoPin1 = 3;  // Echo pin for sensor 1 (forward)
const int trigPin2 = 4;  // Trigger pin for sensor 2 (right)
const int echoPin2 = 5;  // Echo pin for sensor 2 (right)
const int trigPin3 = 6;  // Trigger pin for sensor 3 (backward)
const int echoPin3 = 7;  // Echo pin for sensor 3 (backward)
const int trigPin4 = 8;  // Trigger pin for sensor 4 (left)
const int echoPin4 = 9;  // Echo pin for sensor 4 (left)
const int gun_x = 3;     // X-coordinate for the shrink ray gun
const int gun_y = 5;     // Y-coordinate for the shrink ray gun

// Maximum distance to measure (in centimeters)
const int maxDistance = 800;

// Object coordinates
float objectX = 0;
float objectY = 0;

// Ultrasonic sensor objects
NewPing sonar1(trigPin1, echoPin1, maxDistance);
NewPing sonar2(trigPin2, echoPin2, maxDistance);
NewPing sonar3(trigPin3, echoPin3, maxDistance);
NewPing sonar4(trigPin4, echoPin4, maxDistance);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // Measure distances from the sensors
  int distance1 = sonar1.ping_cm();
  int distance2 = sonar2.ping_cm();
  int distance3 = sonar3.ping_cm();
  int distance4 = sonar4.ping_cm();

  // Calculate object coordinates based on distance measurements
  calculateCoordinates(distance1, distance2, distance3, distance4);

  // Print object coordinates
  Serial.print("Object Coordinates (X, Y): ");
  Serial.print(objectX);
  Serial.print(", ");
  Serial.println(objectY);

  if (gun_x==objectX && gun_y==objectY){
    Serial.println ("shrink ray gun is found");
    }

  delay(100);
}

void calculateCoordinates(int distance1, int distance2, int distance3, int distance4) {
  
  // Calculate the X-coordinate of cookiebot
  if (distance2 < maxDistance && distance4 < maxDistance) {
    objectX = 5 - (distance3 / 100.0);
  } else {
    objectX = 0;
  }

  // Calculate the Y-coordinate of cookiebot
  if (distance1 < maxDistance && distance3 < maxDistance) {
    objectY = 6 - (distance4 / 100.0);
  } else {
    objectY = 0;
  }
}
