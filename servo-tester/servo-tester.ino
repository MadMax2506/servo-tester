#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "src/Utils/Utils.h"
#include "src/Taster/Taster.h"
#include "src/Servos/Servos.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Servos* servos;
Taster* taster;

void setup() {
  Serial.begin(9600);

  // define pins
  pinMode(ZERO_DEGREE_PIN, INPUT_PULLUP);
  pinMode(EDGE_VALUE_LOW_PIN, INPUT_PULLUP);
  pinMode(EDGE_VALUE_HIGH_PIN, INPUT_PULLUP);
  pinMode(TOOGLE_MODI_PIN, INPUT_PULLUP);
  pinMode(ERROR_LED_PIN, OUTPUT);

  // dispaly
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    setError();
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  servos = new Servos();
  taster = new Taster(servos);
}

void loop() {
  const bool manuelModus = isManuelModus();

  display.setCursor(0, 0);
  display.clearDisplay();
  display.print("Modus: ");
  if(manuelModus) {
    const int degree = getDegreeFromPoti();
    servos->write(degree);

    // display
    display.println(MANUEL_MODUS);
    display.print("Grad: ");
    display.println(degree);
  } else {
    taster->executeTasterCommand();

    // display
    display.println(TASTER_MODUS);
    display.println("letzter Taster: ");
    display.print(" ");
    display.println(taster->getLastTaster());
  }

  display.display();
  delay(200);
}