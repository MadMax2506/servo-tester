#ifndef _SERVO_GROUP_H_
#define _SERVO_GROUP_H_

#include <Arduino.h>
#include "./Servomotor.h"

#define SERVO_ONE 6
#define SERVO_TWO 7
#define SERVO_THREE 8
#define SERVO_FOUR 10

#define DEGREE_OFFSET 5
#define COUNT_SERVOS 4

class ServoGroup {
  private:
    int currentDegree;

    Servomotor* servos[COUNT_SERVOS];

    bool isNewDegree(int);
  public:
    ServoGroup();

    void write(int);
    void uncheckedWrite(int);
};

#endif //_SERVO_GROUP_H_
