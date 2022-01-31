#include "Servomotor.h"

Servomotor::Servomotor(int pin): pin(pin) {
  
}

/** 
 * read from servo if servo is active
 * @return degree value from servo
*/
int Servomotor::read() {
  // TODO: read from servos
}

/** 
 * write degree value to servo
 * @param degree
*/
void Servomotor::write(int degree) {
  if(isActive()) {

  }
}

// private //

bool Servomotor::isActive() {
  return true;
}