#include <BlynkSimpleEsp8266.h>  // Include the Blynk library
#include <ESP8266WiFi.h>         // Include the ESP8266 WiFi library
#include <SimpleTimer.h>         // Include the SimpleTimer library

#define BLYNK_TEMPLATE_ID "TMPL3WCOpA40z"
#define BLYNK_TEMPLATE_NAME "ESP8266 WATER LEVEL INDICATOR"

#define TRIGGER_PIN_1 D1  // Define the trigger pin for sensor 1
#define ECHO_PIN_1 D2     // Define the echo pin for sensor 1

#define TRIGGER_PIN_2 D3  // Define the trigger pin for sensor 2
#define ECHO_PIN_2 D4     // Define the echo pin for sensor 2

#define TRIGGER_PIN_3 D5  // Define the trigger pin for sensor 3
#define ECHO_PIN_3 D6     // Define the echo pin for sensor 3

#define RELAY_PIN_1 D7   // Define the relay pin for motor 1
#define RELAY_PIN_2 D8   // Define the relay pin for motor 2
#define RELAY_PIN_3 D9   // Define the relay pin for motor 3

#define WATER_LEVEL_THRESHOLD_1 10  // Define water level threshold for tank 1
#define WATER_LEVEL_THRESHOLD_2 15  // Define water level threshold for tank 2
#define WATER_LEVEL_THRESHOLD_3 20  // Define water level threshold for tank 3

SimpleTimer timer;

char auth[] = "RCfey0QJ-MK2XBhNOmJjEa84BoNFFiMa";  // Blynk authentication token
char ssid[] = "YourSSID";        // Your WiFi network SSID
char pass[] = "YourPassword";    // Your WiFi network password

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);  // Initialize Blynk with authentication token and WiFi credentials
  
  pinMode(RELAY_PIN_1, OUTPUT);  // Set motor relay pin as output
  pinMode(RELAY_PIN_2, OUTPUT);  // Set motor relay pin as output
  pinMode(RELAY_PIN_3, OUTPUT);  // Set motor relay pin as output
  
  timer.setInterval(1000L, checkWaterLevel);  // Check water level every 1 second
}

void loop() {
  Blynk.run();
  timer.run();
}

void checkWaterLevel() {
  float distance_1 = getDistance(TRIGGER_PIN_1, ECHO_PIN_1);
  float distance_2 = getDistance(TRIGGER_PIN_2, ECHO_PIN_2);
  float distance_3 = getDistance(TRIGGER_PIN_3, ECHO_PIN_3);

  // Check water level for tank 1
  if (distance_1 <= WATER_LEVEL_THRESHOLD_1) {
    digitalWrite(RELAY_PIN_1, HIGH);  // Turn on motor 1
  } else {
    digitalWrite(RELAY_PIN_1, LOW);   // Turn off motor 1
  }

  // Check water level for tank 2
  if (distance_2 <= WATER_LEVEL_THRESHOLD_2) {
    digitalWrite(RELAY_PIN_2, HIGH);  // Turn on motor 2
  } else {
    digitalWrite(RELAY_PIN_2, LOW);   // Turn off motor 2
  }

  // Check water level for tank 3
  if (distance_3 <= WATER_LEVEL_THRESHOLD_3) {
    digitalWrite(RELAY_PIN_3, HIGH);  // Turn on motor 3
  } else {
    digitalWrite(RELAY_PIN_3, LOW);   // Turn off motor 3
  }
}

float getDistance(int triggerPin, int echoPin) {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicrosecond(10);
    digitalWrite(triggerPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    float distance = duration * 0.034 / 2;
    return distance;
}
