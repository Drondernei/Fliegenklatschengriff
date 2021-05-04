#include "pitches.h"

int blueLED = 10;
int redLED = 9;
int passiveBuzzer = 8;
int tiltSwitch = 2;

int ledArray[] = {blueLED, redLED};

int sirene[] = {NOTE_E3, 0, NOTE_E5, 0};
int toneDuration = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(passiveBuzzer, OUTPUT);
  pinMode(tiltSwitch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(tiltSwitch) == HIGH)
  {
    for(int i = 0; i<4; i++){
      digitalWrite(ledArray[i%2], HIGH);
      digitalWrite(ledArray[abs(i%2-1)], LOW);
      tone(passiveBuzzer, sirene[i], toneDuration);
      delay(500);
    }
  }else{
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, LOW);
    tone(passiveBuzzer, 0, toneDuration);
  }



  delay(10);
}

/*
 ******************************************
 *Website: www.elegoo.com
 * 
 *Time:2018.1.23
 *
 *****************************************

#include "pitches.h"
 
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;  // 500 miliseconds
 
void setup() {
 
}
 
void loop() {  
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
    tone(12, melody[thisNote], duration);
     
    // Output the voice after several minutes
    delay(1000);
  }
   
  // restart after two seconds 
  delay(2000);
}
 */
