#include <Servo.h>

// Code and Fab Narrative Project

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int minosSwitch = 13;
const int tableSwitch = 12;
const int suitUpSwitch = 11;
const int sunSwitch = 10;
const int seaSwitch = 9;

const int sunLed = 4;

int minosSwitchState = 0;
int tableSwitchState = 0;
int suitUpSwitchState = 0;
int sunSwitchState = 0;
int seaSwitchState = 0;

void setup() {

  servo1.attach(8);
  servo2.attach(7);
  servo3.attach(6);
  servo4.attach(5);

  pinMode(sunLed, OUTPUT);

  pinMode(minosSwitch, INPUT);
  pinMode(tableSwitch, INPUT);
  pinMode(suitUpSwitch, INPUT);
  pinMode(sunSwitch, INPUT);
  pinMode(seaSwitch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  minosSwitchState = digitalRead(minosSwitch);
  tableSwitchState = digitalRead(tableSwitch);
  suitUpSwitchState = digitalRead(suitUpSwitch);
  sunSwitchState = digitalRead(sunSwitch);
  seaSwitchState = digitalRead(seaSwitch);

  // tower
  if (minosSwitchState == HIGH) {
    for (int i = 0; i <= 180; i++) {
      servo1.write(i);
    }
  }
  if (minosSwitchState == LOW) {
    for (int i = 180; i >= 0; i--)
      servo1.write(i);
  }

  // workbench
  int tableVal;
  if (tableSwitchState == HIGH) {
    tableVal = 90;
  }
  if (tableSwitchState == LOW) {
    tableVal = 0;
  }
  servo2.write(tableVal);
  delay(15);

  // suit up

  // flying

  // falling
}
