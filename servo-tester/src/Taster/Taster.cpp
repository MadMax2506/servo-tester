#include "Taster.h"

Taster::Taster(ServoGroup* servoGroup): lastTaster(TASTER_EMPTY), servoGroup(servoGroup) {

}

/**
 * @param lastTaster which was pressed
*/
void Taster::setLastTaster(String value) {
  lastTaster = value;
}

/**
 * @return the last taster which was pressed
*/
String Taster::getLastTaster() {
  return lastTaster;
}

/**
 * check which taster is pressed an execute the command. Otherwise do nothing.
*/
void Taster::executeTasterCommand() {
  if(digitalRead(ZERO_DEGREE_PIN) == LOW) {
    // 0°
    servoGroup->uncheckedWrite(ZERO_DEGREE_VALUE);
    setLastTaster(TASTER_ZERO_DEGREE);
  } else if(digitalRead(EDGE_VALUE_LOW_PIN) == LOW) {
    // -90°
    servoGroup->uncheckedWrite(EDGE_VALUE_LOW_VALUE);
    setLastTaster(TASTER_EDGE_VALUE_LOW);
  } else if(digitalRead(EDGE_VALUE_HIGH_PIN) == LOW) {
    // 90°
    servoGroup->uncheckedWrite(EDGE_VALUE_HIGH_VALUE);
    setLastTaster(TASTER_EDGE_VALUE_HIGH);
  }
}

// private //
