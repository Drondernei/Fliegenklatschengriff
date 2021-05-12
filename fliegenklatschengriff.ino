//Used for buzzer sound
#include "pitches.h"

//LEDs for flash light
int blueLED = 10;
int redLED = 9;
//Buzzer as sound module
int passiveBuzzer = 8;
//Buttons to control functionality
int buttonGreen = 2;
int buttonBlue = 3;
int buttonRed = 4;
int buttonYellow = 5;

int ledArray[] = {blueLED, redLED};

int sirene[] = {NOTE_E3, 0, NOTE_E5, 0};
int toneDuration = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(passiveBuzzer, OUTPUT);
  pinMode(buttonGreen, INPUT);
  pinMode(buttonBlue, INPUT);
  pinMode(buttonRed, INPUT);
  pinMode(buttonYellow, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //green button controls sirene incl. flashing lights
  if (digitalRead(buttonGreen) == HIGH)
  {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledArray[i % 2], HIGH);
      digitalWrite(ledArray[abs(i % 2 - 1)], LOW);
      tone(passiveBuzzer, sirene[i], toneDuration);

      delay(500);
    }
    
  //blue button controls blue LED
  } else if (digitalRead(buttonBlue) == HIGH) {
    digitalWrite(blueLED, HIGH);
    delay(350);
    digitalWrite(blueLED, LOW);
    delay(350);
  //red button controls red LED
  } else if (digitalRead(buttonRed) == HIGH) {
    digitalWrite(redLED, HIGH);
    delay(350);
    digitalWrite(redLED, LOW);
    delay(350);
    
  //Pressing yellow button leads to "meep meep"
  }else if (digitalRead(buttonYellow) == HIGH) {
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
