#ifndef _TASTER_H_
#define _TASTER_H_

#include <Arduino.h>
#include "../Servos/Servos.h"

#define ZERO_DEGREE_PIN 2
#define EDGE_VALUE_LOW_PIN 3
#define EDGE_VALUE_HIGH_PIN 4

#define TASTER_EMPTY "Keiner"
#define TASTER_ZERO_DEGREE "Mitte (0 Grad)"
#define TASTER_EDGE_VALUE_LOW "Randewert (-90 Grad)"
#define TASTER_EDGE_VALUE_HIGH "Randewert (90 Grad)"

class Taster {
  private:
    String lastTaster;
    Servos* servos;
  public:
    Taster(Servos* servos): lastTaster(TASTER_EMPTY), servos(servos) {}

    String getLastTaster();
    void setLastTaster(String);

    void executeTasterCommand();
};

#endif //_TASTER_H_
