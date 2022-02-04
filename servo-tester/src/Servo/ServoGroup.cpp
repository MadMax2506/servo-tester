#include "ServoGroup.h"

ServoGroup::ServoGroup(): currentDegree(0)  {
  // define servos
  servos[0] = new Servomotor(SERVO_ONE);
  servos[1] = new Servomotor(SERVO_TWO);
  servos[2] = new Servomotor(SERVO_THREE);
  servos[3] = new Servomotor(SERVO_FOUR);
}

/**
 * Write to all servos with check if it is a new degree.
 * @param degree
*/
void ServoGroup::write(int degree) {
  Serial.println(abs(currentDegree - degree));
  if(isNewDegree(degree)) {
    uncheckedWrite(degree);
  }
}

/**
 * Write to all servos without check if it is a new degree.
 * @param degree
*/
void ServoGroup::uncheckedWrite(int degree) {
  currentDegree = degree;
  for(int i = 0; i < COUNT_SERVOS; i++) {
    servos[i]->write(currentDegree);
  }
}

// private //

bool ServoGroup::isNewDegree(int degree) {
  return abs(currentDegree - degree) >= DEGREE_OFFSET;
}
