#include "ServoGroup.h"

ServoGroup::ServoGroup(): currentDegree(0), oldDegree(0), numberOfActiveSertvos(0) {
  // define servos
  servos[0] = new Servomotor(SERVO_ONE);
  servos[1] = new Servomotor(SERVO_TWO);
  servos[2] = new Servomotor(SERVO_THREE);
  servos[3] = new Servomotor(SERVO_FOUR);
}

/**
 * @return the number of active servos 
 */
int ServoGroup::getNumberOfActiveServos() {
  return numberOfActiveSertvos;
}

/** 
 * Read from all active servos
 * @return an avg degree from all active servos
*/
int ServoGroup::read() {
  int degree = 0;
  
  for(int i = 0; i < numberOfActiveSertvos; i++) {
    degree+= servos[activeServoIndices[i]]->read();
  }
  return degree / numberOfActiveSertvos;
}

/**
 * Write to all servos with check if it is a new degree.
 * @param degree
*/
void ServoGroup::write(int degree) {
  if(isNewDegree()) {
    uncheckedWrite(degree);
  }
}

/**
 * Write to all servos without check if it is a new degree.
 * @param degree
*/
void ServoGroup::uncheckedWrite(int degree) {
  checkActiveServos();

  oldDegree = currentDegree;
  currentDegree = degree;

  for(int i = 0; i < numberOfActiveSertvos; i++) {
    servos[activeServoIndices[i]]->write(currentDegree);
  }
}

// private //

bool ServoGroup::isNewDegree() {
  return abs(currentDegree - oldDegree) >= DEGREE_OFFSET;
}

void ServoGroup::checkActiveServos() {
  
}