#ifndef _SERVO_GROUP_H_
#define _SERVO_GROUP_H_

#include <Arduino.h>
#include "./Servomotor.h"

#define SERVO_ONE 7
#define SERVO_TWO 8
#define SERVO_THREE 9
#define SERVO_FOUR 10

#define DEGREE_OFFSET 5
#define COUNT_SERVOS 4

class ServoGroup {
  private:
    int currentDegree;
    int oldDegree;

    Servomotor* servos[COUNT_SERVOS];
    int activeServoIndices[COUNT_SERVOS];
    int numberOfActiveSertvos;

    bool isNewDegree();
    void checkActiveServos();
  public:
    ServoGroup();

    int getNumberOfActiveServos();

    int read();
    void write(int);
    void uncheckedWrite(int);
};

#endif //_SERVO_GROUP_H_
