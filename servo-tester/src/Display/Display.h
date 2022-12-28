#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 32
#define DISPLAY_SLAVE_ADDRESS 0x3C

class Display {
  private:
    Adafruit_SSD1306* output;
    String text;
  public:
    Display();
    ~Display() = default;

    bool connect();
    void setup();
    
    void setModus(String);
    void setDegree(int);
    void setLastTaster(String);
    void show();
    void reset();
};

#endif //_DISPLAY_H_
