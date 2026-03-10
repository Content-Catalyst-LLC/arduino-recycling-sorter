#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define METAL_SENSOR_PIN 7
#define SERVO_PIN 6

Servo sorterServo;

long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) {
    return -1;
  }

  return duration * 0.034 / 2;
}

bool isMetalDetected() {
  return digitalRead(METAL_SENSOR_PIN) == LOW;
}

void routeMetal() {
  sorterServo.write(30);
  delay(1000);
}

void routeNonMetal() {
  sorterServo.write(120);
  delay(1000);
}

void resetGate() {
  sorterServo.write(75);
  delay(500);
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(METAL_SENSOR_PIN, INPUT);

  sorterServo.attach(SERVO_PIN);
  resetGate();

  Serial.println("Arduino Recycling Sorter Starting");
}

void loop() {
  long distance = measureDistance();

  if (distance > 0 && distance < 10) {
    Serial.print("Object detected at distance: ");
    Serial.println(distance);

    if (isMetalDetected()) {
      Serial.println("Metal object detected. Routing to metal bin.");
      routeMetal();
    } else {
      Serial.println("Non-metal object detected. Routing to general recycling bin.");
      routeNonMetal();
    }

    resetGate();
    delay(1000);
  }

  delay(200);
}
