#include "Servomotor.h"

Servomotor::Servomotor(int pin): pin(pin) {
  
}

int Servomotor::read() {
  // TODO: read from servos
}

void Servomotor::write(int degree) {
  if(isAcive()) {

  }
}

// private //

bool Servomotor::isAcive() {
  return true;
}