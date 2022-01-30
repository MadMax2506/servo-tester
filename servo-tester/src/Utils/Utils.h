#ifndef _UTILS_H_
#define _UTILS_H_

#include <Arduino.h>
#include <Servo.h>

#define POTI_PIN A0
#define ERROR_LED_PIN 12
#define TOOGLE_MODI_PIN 5

#define MANUEL_MODUS "Manuel"
#define TASTER_MODUS "Taster"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

void setError();
bool isManuelModus();
int getDegreeFromPoti();

#endif //_UTILS_H_
