#ifndef _SERVO_H_
#define _SERVO_H_

#include <Arduino.h>

// #define ANALOG_SERVOS

class Servo {
  public:
    const int pin;
  public:
    Servo(int pin) : pin(pin) {};
    void write(int);
};


#endif //_SERVO_H_
