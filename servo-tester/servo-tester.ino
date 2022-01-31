#include "src/Utils/Utils.h"
#include "src/Taster/Taster.h"
#include "src/Servo/ServoGroup.h"
#include "src/Display/Display.h"

ServoGroup* servoGroup;
Taster* taster;
Display* display;

void setup() {
  // define pins

  display = new Display();
  servoGroup = new ServoGroup();
  taster = new Taster(servoGroup);

  // dispaly
  if(display->connect()) {
    display->setup();
  } else {
    setError();
    for(;;);
  }
}

void loop() {
  const bool manuelModus = isManuelModus();
  
  display.print("Modus: ");
  if(manuelModus) {
    const int degree = getDegreeFromPoti();
    servoGroup->write(degree);

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

  display->show();
  delay(200);
}