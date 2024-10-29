#include <Keyboard.h>
#include <Mouse.h>
#include <Bounce2.h>
#include <SPI.h>

#define LEFT_LEG_PIN 4
#define RIGHT_LEG_PIN 6
#define LEFT_REIN_PIN 26
#define RIGHT_REIN_PIN 3
#define SEAT_FORWARD_PIN 28
#define SEAT_REAR_PIN 27

Bounce leftLeg = Bounce(LEFT_LEG_PIN, 5);
Bounce rightLeg = Bounce(RIGHT_LEG_PIN, 5);
Bounce leftRein = Bounce(LEFT_REIN_PIN, 5);
Bounce rightRein = Bounce(RIGHT_REIN_PIN, 5);
Bounce seatForward = Bounce(SEAT_FORWARD_PIN, 5);
Bounce seatRear = Bounce(SEAT_REAR_PIN, 5);

void setup() {
  // initialize the buttons' inputs:
  pinMode(LEFT_LEG_PIN, INPUT_PULLUP);
  pinMode(RIGHT_LEG_PIN, INPUT_PULLUP);
  pinMode(LEFT_REIN_PIN, INPUT_PULLUP);
  pinMode(RIGHT_REIN_PIN, INPUT_PULLUP);
  pinMode(SEAT_FORWARD_PIN, INPUT_PULLUP);
  pinMode(SEAT_REAR_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  // initialize keyboard/mouse control:
  Mouse.begin();
  Keyboard.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  leftLeg.update();
  if (leftLeg.fell()) {
    Mouse.press(MOUSE_LEFT);
  } else if (leftLeg.rose()) {
    Mouse.release(MOUSE_LEFT);
  }

  rightLeg.update();
  if (rightLeg.fell()) {
    Mouse.press(MOUSE_RIGHT);
  } else if (rightLeg.rose()) {
    Mouse.release(MOUSE_RIGHT);
  }

  leftRein.update();
  if (leftRein.fell()) {
    Keyboard.press('a');
  } else if (leftRein.rose()) {
    Keyboard.release('a');
  }

  rightRein.update();
  if (rightRein.fell()) {
    Keyboard.press('d');
  } else if (rightRein.rose()) {
    Keyboard.release('d');
  }

  seatForward.update();
  if (seatForward.fell()) {
    Keyboard.press('w');
  } else if (seatForward.rose()) {
    Keyboard.release('w');
  }

  seatRear.update();
  if (seatRear.fell()) {
    Keyboard.press('s');
  } else if (seatRear.rose()) {
    Keyboard.release('s');
  }
  

}
