#include "Display.h"

Display::Display(): text("") {
  output = new Adafruit_SSD1306(DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire, -1);
}

/**
 * @return true if display is connected
 */
bool Display::connect() {
  return output->begin(SSD1306_SWITCHCAPVCC, DISPLAY_SLAVE_ADDRESS);
}

/**
 * initialize the display
 */
void Display::setup() {
  output->clearDisplay();
  output->setTextSize(1);
  output->setTextColor(WHITE);
}

/**
 * show the content on the display
 */
void Display::show() {
  output->display();
}

// private //

/**
 * delete complete content from the display and set cursor to the start
 * @param showChanges display the changes directly if value is true
 */
void Display::reset(bool showChanges = false) {
  output->setCursor(0, 0);
  output->clearDisplay();
  if(showChanges) {
    output->display();
  }
}