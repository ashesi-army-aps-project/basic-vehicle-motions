#include Wire.h;
#include Adafruit_MotorShield.h; 
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_StepperMotor *myStepper = AFMS.getStepper(200, 2);

Adafruit_DCMotor myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor myMotor2 = AFMS.getMotor(2);

void setup() {
  AFMS.begin();  // Initialize the motor shield
  myStepper -> setSpeed(10);  // Set the speed of the motor (10 RPM)
  motor1->setSpeed(255);  // Full speed for Motor 1
  motor2->setSpeed(255);  // Full speed for Motor 2
}

void loop() {
  // Move forward 200 steps
  myStepper -> step(200, FORWARD, SINGLE);
  delay(500);

  // Move backward 200 steps
  myStepper -> step(200, BACKWARD, SINGLE);
  delay(500);

// Having both motors move forwards and backwards improves rotation.
  // Rotate the motors to the left 
  motor1->run(BACKWARD);
  motor2->run(FORWARD);
  delay(1000);  // Delay for 1 second

  // Stop the motors
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  delay(1000);  // Delay for 1 second

  // Rotate the motors to the right
  motor1->run(FORWARD);
  motor2->run(BACKWARD);
  delay(1000);  // Delay for 1 second

  // Stop the motors
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  delay(1000);  // Delay for 1 second
}
}
