#include "src/Utils/Utils.h"
#include "src/Taster/Taster.h"
#include "src/Servo/ServoGroup.h"
#include "src/Display/Display.h"

ServoGroup* servoGroup;
Taster* taster;
Display* display;

void setup() {
  definePinModes();

  display = new Display();
  servoGroup = new ServoGroup();
  taster = new Taster(servoGroup);

  if(display->connect()) {
    display->setup();
  } else {
    setErrorLed();
    for(;;);
  }
}

void loop() {
  display->reset();

  // check if any servo is connected
  if(false) {
    // any servo is connected
    
    // check if it is a manuel modus
    if(checkIfManuelModus()) {
      // manuel modus
      const int degree = getDegreeFromPoti();
      servoGroup->write(degree);

      display->setModus(MANUEL_MODUS);
      display->setDegree(degree);
    } else {
      // taster modus
      taster->executeTasterCommand();

      display->setModus(TASTER_MODUS);
      display->setLastTaster(taster->getLastTaster());
    } 
  } else {
    // no servo is connected
    display->waitForServo();
  }

  display->show();
  delay(200);
}