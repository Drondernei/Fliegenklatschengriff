//Used for buzzer sound
#include "pitches.h"

//LEDs for flash light
int blueLED = 10;
int redLED = 9;
//Buzzer as sound module
int passiveBuzzer = 8;
//Joystick as control unit
int xAxis = A0;
int yAxis = A1;
int zButton = 0;

int ledArray[] = {blueLED, redLED};

int sirene[] = {NOTE_E3, 0, NOTE_E5, 0};
int toneDuration = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(passiveBuzzer, OUTPUT);
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);
  pinMode(zButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //The Joysticks Y-Axis means X-Axis on the real "Hardware" due to installation method; priority on this event

  //yAxis controls sirene incl. flashing lights
  if (analogRead(yAxis) < 50 || analogRead(yAxis) > 950)
  {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledArray[i % 2], HIGH);
      digitalWrite(ledArray[abs(i % 2 - 1)], LOW);
      tone(passiveBuzzer, sirene[i], toneDuration);

      delay(500);
    }
    
  //xAxis controls blue and red LED, depends on direction
  } else if (analogRead(xAxis) < 50) {
    digitalWrite(blueLED, HIGH);
    delay(350);
    digitalWrite(blueLED, LOW);
    delay(350);
  } else if (analogRead(xAxis) > 950) {
    digitalWrite(redLED, HIGH);
    delay(350);
    digitalWrite(redLED, LOW);
    delay(350);
    
  //Pressing the Joystick (zButton) leads to "meep meep"
  }else if (digitalRead(zButton) == LOW) {
    Serial.println(digitalRead(zButton));
    tone(passiveBuzzer, NOTE_E5, toneDuration);
    delay(500);
    tone(passiveBuzzer, 0, toneDuration);
    delay(250);
    tone(passiveBuzzer, NOTE_E5, toneDuration);
    delay(500);
    tone(passiveBuzzer, 0, toneDuration);
    delay(500);
  }
  //reset afterwards
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
}
