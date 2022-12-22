#ifndef _SERVOMOTOR_H_
#define _SERVOMOTOR_H_

#include <Arduino.h>
#include <Servo.h>
#include "../Utils/Utils.h"

#define DEGREE_OFFSET 2

#define ZERO_DEGREE_VALUE 0
#define EDGE_VALUE_LOW_VALUE -90
#define EDGE_VALUE_HIGH_VALUE 90

class Servomotor {
  protected:
    const int pin;
    Servomotor(int pin) : pin(pin) {};
  public:
    void virtual write(int);
};

class AnalogServomotor : public Servomotor {
  public:
    AnalogServomotor(int);
    void write(int);
};

class DigitalServomotor : public Servomotor {
  private:
    Servo* servo;
  public:
    DigitalServomotor(int);
    void write(int);
};

#endif //_SERVOMOTOR_H_
