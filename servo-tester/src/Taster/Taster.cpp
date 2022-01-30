#include "Taster.h"

String Taster::getLastTaster() {
  return lastTaster;
}

void Taster::setLastTaster(String value) {
  lastTaster = value;
}

void Taster::executeTasterCommand() {
  bool isZeroDegreeActive = digitalRead(ZERO_DEGREE_PIN) == LOW;
  bool isEdgeValueLowActive = digitalRead(EDGE_VALUE_LOW_PIN) == LOW;
  bool isEdgeValueHighActive = digitalRead(EDGE_VALUE_HIGH_PIN) == LOW;

  if(isZeroDegreeActive) {
    servos->uncheckedWrite(ZERO_DEGREE_VALUE);
    setLastTaster(TASTER_ZERO_DEGREE);
    return;
  }
  if(isEdgeValueLowActive) {
    servos->uncheckedWrite(EDGE_VALUE_LOW_VALUE);
    setLastTaster(TASTER_EDGE_VALUE_LOW);
    return;
  }
  if(isEdgeValueHighActive) {
    servos->uncheckedWrite(EDGE_VALUE_HIGH_VALUE);
    setLastTaster(TASTER_EDGE_VALUE_HIGH);
    return;
  }
}
