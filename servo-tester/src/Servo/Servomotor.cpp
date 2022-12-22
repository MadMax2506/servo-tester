#include "./Servomotor.h"

AnalogServomotor::AnalogServomotor(int pin) : Servomotor(pin) {
  pinMode(pin, OUTPUT);
}

/** 
 * write degree value to servo
 * @param degree in range from {@link EDGE_VALUE_LOW_VALUE} to {@link EDGE_VALUE_HIGH_VALUE}
*/
void AnalogServomotor::write(int degree) {
  int pwm = (convertDegreeForServo(degree) * 11) + 500;
  digitalWrite(pin, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(pin, LOW);
  delay(50);
}

DigitalServomotor::DigitalServomotor(int pin) : Servomotor(pin) {
  servo = new Servo();
  servo->attach(pin);
}

/** 
 * write degree value to servo
 * @param degree in range from {@link EDGE_VALUE_LOW_VALUE} to {@link EDGE_VALUE_HIGH_VALUE}
*/
void DigitalServomotor::write(int degree) {
  servo->write(degree + EDGE_VALUE_HIGH_VALUE);
}
