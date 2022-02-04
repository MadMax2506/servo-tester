#include "Servomotor.h"

Servomotor::Servomotor(int pin) : pin(pin) {
  pinMode(pin, OUTPUT);
}

/** 
 * write degree value to servo
 * @param degree
*/
void Servomotor::write(int degree) {
  // TODO: check code
  int pwm = (convertDegreeForServo(degree) * 11) + 500;
  digitalWrite(pin, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(pin, LOW);
  delay(50);
}
