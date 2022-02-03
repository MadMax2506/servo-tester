#ifndef _UTILS_H_
#define _UTILS_H_

#include <Arduino.h>
#include <Servo.h>

#define POTI_PIN A0
#define ERROR_LED_PIN 12
#define TOOGLE_MODI_PIN 5

#define MANUEL_MODUS "Manuel"
#define TASTER_MODUS "Taster"

void definePinModes();
void setErrorLed();
bool checkIfManuelModus();
int getDegreeFromPoti();

#endif //_UTILS_H_
