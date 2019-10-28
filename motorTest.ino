#include <Stepper.h>
#include <ESP32Servo.h>

const int stepsPerRev = 2038;

Stepper myStepper(stepsPerRev, 32, 33, 25, 26);
Servo myServo;
int servoPos = 0;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  myStepper.setSpeed(10);
  myServo.attach(18);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  myStepper.step(stepsPerRev);
  myServo.write(servoPos);
  servoPos = servoPos + 10;
  if (servoPos == 180) {
      servoPos = 0;
  }
}
