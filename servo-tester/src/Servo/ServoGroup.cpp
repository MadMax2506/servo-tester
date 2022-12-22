#include "./ServoGroup.h"

ServoGroup::ServoGroup(bool isAnalog): currentDegree(0), isAnalog(isAnalog)  {
  recreateServos(isAnalog);
}

bool ServoGroup::getIsAnalog() const {
  return isAnalog;
}

/**
 * Write to all servos with check if it is a new degree.
 * @param degree
*/
void ServoGroup::write(int degree) {
  if(isNewDegree(degree)) uncheckedWrite(degree);
}

/**
 * Write to all servos without check if it is a new degree.
 * @param degree
*/
void ServoGroup::uncheckedWrite(int degree) {
  currentDegree = degree;
  for(int i = 0; i < COUNT_SERVOS; i++) servos[i]->write(currentDegree);
}

void ServoGroup::recreateServos(bool isAnalog) {
  ServoGroup::isAnalog = isAnalog;

  // define servos
  servos[0] = buildServomotor(isAnalog, SERVO_ONE);
  servos[1] = buildServomotor(isAnalog, SERVO_TWO);
  servos[2] = buildServomotor(isAnalog, SERVO_THREE);
  servos[3] = buildServomotor(isAnalog, SERVO_FOUR);
}

// private //

bool ServoGroup::isNewDegree(int degree) {
  return abs(currentDegree - degree) >= DEGREE_OFFSET;
}

Servomotor* ServoGroup::buildServomotor(bool isAnalog, int pin) {
  if(isAnalog) return new AnalogServomotor(pin);
  return new DigitalServomotor(pin);
}