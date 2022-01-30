#ifndef _SERVOS_H_
#define _SERVOS_H_

#include <Arduino.h>

#define SERVO_ONE 7
#define SERVO_TWO 8
#define SERVO_THREE 9
#define SERVO_FOUR 10

#define DEGREE_OFFSET 5

#define ZERO_DEGREE_VALUE 0
#define EDGE_VALUE_LOW_VALUE -90
#define EDGE_VALUE_HIGH_VALUE 90

class Servos {
  private:
    int currentDegree = 0;
    int oldDegree = 0;

    bool isNewDegree();
  public:
    void read();
    void write(int);
    void uncheckedWrite(int);
};

#endif //_SERVOS_H_
