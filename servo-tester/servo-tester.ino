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
  
  if(manuelModus) {
    const int degree = getDegreeFromPoti();
    servoGroup->write(degree);

    // display
    display->setModus(MANUEL_MODUS);
    display->setDegree(degree);
  } else {
    taster->executeTasterCommand();

    // display
    display->setModus(TASTER_MODUS);
    display->setLastTaster(taster->getLastTaster());
  }

  display->show();
  delay(200);
}