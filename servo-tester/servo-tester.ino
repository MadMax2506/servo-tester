#include "src/Utils/Utils.h"
#include "src/Taster/Taster.h"
#include "src/Servo/ServoGroup.h"
#include "src/Display/Display.h"

ServoGroup* servoGroup;
Taster* taster;
Display* display;

void setup() {
  Serial.begin(9600);
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

  const bool isAnalog = checkIfAnalogModus();
  Serial.println(isAnalog ? "analog" : "digital");
  if(isAnalog != servoGroup->getIsAnalog()) {
    servoGroup->recreateServos(isAnalog);
  }

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

  display->show();
  delay(200);
}