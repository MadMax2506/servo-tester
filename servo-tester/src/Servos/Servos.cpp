#include "Servos.h"

bool Servos::isNewDegree() {
  return abs(currentDegree - oldDegree) >= DEGREE_OFFSET;
}

void Servos::read() {
  // TODO: read from servos
}

void Servos::write(int degree) {
  if(isNewDegree()) {
    uncheckedWrite(degree);
  }
}

void Servos::uncheckedWrite(int degree) {
  oldDegree = currentDegree;
  currentDegree = degree;

  // TODO: write to servos
}