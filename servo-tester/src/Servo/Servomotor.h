#ifndef _SERVOMOTOR_H_
#define _SERVOMOTOR_H_

#include <Arduino.h>

#define DEGREE_OFFSET 2

#define ZERO_DEGREE_VALUE 0
#define EDGE_VALUE_LOW_VALUE -90
#define EDGE_VALUE_HIGH_VALUE 90

class Servomotor {
  private:
    const int pin;

    bool isAcive();
  public:
    Servomotor(int);

    /** 
     * read from servo if servo is active
     * @return degree value from servo
    */
    int read();
    
    /** 
     * write degree value to servo
     * @param degree
    */
    void write(int);
};

#endif //_SERVOMOTOR_H_
