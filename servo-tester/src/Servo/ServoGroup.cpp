#include "ServoGroup.h"

ServoGroup::ServoGroup(): currentDegree(0), oldDegree(0), numberOfActiveSertvos(0) {
  // define servos
  servos[0] = new Servomotor(SERVO_ONE);
  servos[1] = new Servomotor(SERVO_TWO);
  servos[2] = new Servomotor(SERVO_THREE);
  servos[3] = new Servomotor(SERVO_FOUR);
}

int ServoGroup::getNumberOfActiveServos() {
  return numberOfActiveSertvos;
}

int ServoGroup::read() {
  int degree = 0;
  
  for(int i = 0; i < numberOfActiveSertvos; i++) {
    degree+= servos[activeServoIndices[i]]->read();
  }
  return degree / numberOfActiveSertvos;
}

void ServoGroup::write(int degree) {
  if(isNewDegree()) {
    uncheckedWrite(degree);
  }
}

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