#include "src/Servo/Servo.h"
#include "src/Display/Display.h"
#include "src/Constants.h"

// Define global variables
String lastTaster{TASTER_EMPTY};
int currentDegree{-1};

Servo servo_one{SERVO_ONE_PIN};
Servo servo_two{SERVO_TWO_PIN};
Servo servo_three{SERVO_THREE_PIN};
Servo servo_four{SERVO_FOUR_PIN};

Display display{};

void setup() {
  Serial.begin(9600);
  
  // Setup pins
  pinMode(ZERO_DEGREE_PIN, INPUT_PULLUP);
  pinMode(EDGE_VALUE_LOW_PIN, INPUT_PULLUP);
  pinMode(EDGE_VALUE_HIGH_PIN, INPUT_PULLUP);
  pinMode(TOOGLE_MODI_PIN, INPUT_PULLUP);
  pinMode(ERROR_LED_PIN, OUTPUT);

  // Setup display
  if(display.connect()) {
    display.setup();
  } else {
    digitalWrite(ERROR_LED_PIN, HIGH);
    for(;;);
  }
}

void loop() {
  display.reset();

  // check if it is a manuel modus
  if(digitalRead(TOOGLE_MODI_PIN) == LOW) {
    // manuel modus

    const int degree = getDegreeFromPoti();
    write(degree); // write degrees

    // refresh the display
    display.setModus(MANUEL_MODUS);
    display.setDegree(degree);
  } else { 
    // taster modus

    executeTasterCommand();

    // refresh the display
    display.setModus(TASTER_MODUS);
    display.setLastTaster(lastTaster);
  }

  display.show();
  delay(200);
}

int getDegreeFromPoti() {
  int value = analogRead(POTI_PIN);
  if(value <= 444) {
    return map(value, 0, 444, -90, -1);
  } else if(445 <= value && value <= 578) {
      return 0;
  } else {
    return map(value, 579, 1023, 1, 90);
  }
}

void executeTasterCommand() {
  if(digitalRead(ZERO_DEGREE_PIN) == LOW) { // 0°
    write(ZERO_DEGREE_VALUE);
    lastTaster = TASTER_ZERO_DEGREE;
  } else if(digitalRead(EDGE_VALUE_LOW_PIN) == LOW) { // -90°
    write(EDGE_VALUE_LOW_VALUE);
    lastTaster = TASTER_EDGE_VALUE_LOW;
  } else if(digitalRead(EDGE_VALUE_HIGH_PIN) == LOW) { // 90°
    write(EDGE_VALUE_HIGH_VALUE);
    lastTaster = TASTER_EDGE_VALUE_HIGH;
  }
}

/**
 * Write to all servos with check if it is a new degree.
 * @param degree
*/
void write(int newDegree) {
  if(currentDegree >= 0 && abs(currentDegree - newDegree) <= DEGREE_OFFSET) return;

  Serial.print("currentDegree ");
  Serial.println(currentDegree);
  Serial.print("newDegree ");
  Serial.println(newDegree);

  currentDegree = newDegree;

  servo_one.write(newDegree);
  servo_two.write(newDegree);
  servo_three.write(newDegree);
  servo_four.write(newDegree);
}