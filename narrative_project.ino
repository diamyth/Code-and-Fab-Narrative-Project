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

const int sunLedRed = 5;
const int sunLedGreen = 3;

int minosSwitchState = 0;
int tableSwitchState = 0;
int suitUpSwitchState = 0;
int sunSwitchState = 0;
int seaSwitchState = 0;

void setup() {

  servo1.attach(8);
  servo2.attach(7);
  servo3.attach(6);
  servo4.attach(4);

  pinMode(sunLedRed, OUTPUT);
  pinMode(sunLedGreen, OUTPUT);

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
      servo1.write(180);
  }
  if (minosSwitchState == LOW) {
      servo1.write(0);
  }

  // workbench
  int tableVal;
  if (tableSwitchState == HIGH) {
    tableVal = 100;
  }
  if (tableSwitchState == LOW) {
    tableVal = 90;
  }
  servo2.write(tableVal);
  delay(15);

  // suit up
if (suitUpSwitchState == HIGH) {
  servo3.write(165);
}
if (suitUpSwitchState == LOW) {
  servo3.write(180);
}

  // flying
if (sunSwitchState == HIGH) {
  digitalWrite(sunLedRed, 255);
  digitalWrite(sunLedGreen, 255);
}

if (sunSwitchState == LOW) {
  digitalWrite(sunLedRed, 0);
  digitalWrite(sunLedGreen, 0);
}

  // falling
  int seaVal;
  if (seaSwitchState == HIGH) {
    seaVal = 80;
  }
  if (seaSwitchState == LOW) {
    seaVal = 90;
  }
  servo4.write(seaVal);
  delay(15);
}
