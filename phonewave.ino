#include <SoftwareSerial.h>
#include "DFPlayer_Mini_Mp3.h"

SoftwareSerial mySerial(0, 1);
void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);
  mp3_set_volume (10);
}

bool done = true;
bool start = false;
void loop() {
  if(digitalRead(7)==HIGH && done){
    int result = 0;
    for(int i=0; i<4; i++)
      result += digitalRead(3+i) << i;

    if(result == 13 && start == false) {
      start = true;
      mp3_play(1);
    }
    if(result == 14 && start)
      start = false;
    if(start && result != 13) {
      Serial.print("pushed:");
      Serial.println(result);
    }
    done = false;
  } else {
    done = true;
  }
  delay(100);
}
