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

  /**
    0: portrait (tall)
    1: landscape (wide)
    2: portrait rotated 180°
    3: landscape rotated 180°
  */
  output->setRotation(2);
}

/**
 * @param modus which is displayed
 */
void Display::setModus(String modus) {
  output->print("Modus: ");
  output->println(modus);
  output->println("");
}

/**
 * @param degree which is displayed
 */
void Display::setDegree(int degree) {
  output->print("Grad: ");
  output->println(degree);
}

/**
 * @param lastTaster which is displayed
 */
void Display::setLastTaster(String lastTaster) {
  output->println("letzter Taster: ");
  output->print(" ");
  output->println(lastTaster);
}

/**
 * display a waiting text for the servo
 */
void Display::waitForServo() {
  output->println("Keinen Servo an den");
  output->print("Pins D");
  output->print(SERVO_ONE);
  output->print(", D");
  output->print(SERVO_TWO);
  output->print(", D");
  output->print(SERVO_THREE);
  output->println(" oder");
  output->print("D");
  output->print(SERVO_FOUR);
  output->println(" angeschlossen");
}

/**
 * show the content on the display
 */
void Display::show() {
  output->display();
}

/**
 * delete complete content from the display and set cursor to the start
 * @param showChanges display the changes directly if value is true
 */
void Display::reset() {
  output->setCursor(0, 0);
  output->clearDisplay();
}