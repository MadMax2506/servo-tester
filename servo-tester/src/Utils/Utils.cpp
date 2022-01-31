#include "Utils.h"
#include "../Taster/Taster.h"

void definePinModes() {
  pinMode(ZERO_DEGREE_PIN, INPUT_PULLUP);
  pinMode(EDGE_VALUE_LOW_PIN, INPUT_PULLUP);
  pinMode(EDGE_VALUE_HIGH_PIN, INPUT_PULLUP);
  pinMode(TOOGLE_MODI_PIN, INPUT_PULLUP);
  pinMode(ERROR_LED_PIN, OUTPUT);
}

bool isManuelModus() {
  return digitalRead(TOOGLE_MODI_PIN) == LOW;
}

int getDegreeFromPoti() {
  int value = analogRead(POTI_PIN);
  if(value <= 444) {
    return map(value, 0, 444, -90, -1);
  } else if(445 <= value && value <= 578) {
      return 0;
  } else {
    return map(value, 579, 1023, 1, 90);
  }
}

void setError() {
  digitalWrite(ERROR_LED_PIN, HIGH);
}
