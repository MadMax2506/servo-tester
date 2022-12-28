#include "./Servo.h";

/** 
 * write degree value to servo
 * @param degree in range from {@link EDGE_VALUE_LOW_VALUE} to {@link EDGE_VALUE_HIGH_VALUE}
*/
void Servo::write(int degree) {
  #ifdef ANALOG_SERVOS
    int pwm = (degree + 90 * 11) + 500;
    digitalWrite(pin, HIGH);
    delayMicroseconds(pwm);
    digitalWrite(pin, LOW);
    delay(50);
  #endif
  #ifndef ANALOG_SERVOS
    // Digital Servos
    int pwm = (degree * 11) + 500;
    digitalWrite(pin, HIGH);
    delayMicroseconds(pwm);
    digitalWrite(pin, LOW);
    delay(50);
  #endif
}