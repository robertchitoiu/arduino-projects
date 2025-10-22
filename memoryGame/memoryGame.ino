#include <pitches.h>

#define btn1 2
#define btn2 3
#define btn3 4
#define btn4 7
#define buz 6
#define led1 9
#define led2 10
#define led3 11
#define led4 12

int leds[] = {led1, led2, led3, led4};
int btns[] = {btn1, btn2, btn3, btn4};
const int maxSteps = 10;
int pat[maxSteps];
int patLength = 0;

void setup() {
  for(int i=0;i<4;i++){
    pinMode(leds[i], OUTPUT);
    pinMode(btns[i], INPUT_PULLUP);
  }
  pinMode(buz, OUTPUT);
  randomSeed(analogRead(A0));
  intro();
}

void intro(){
  for(int p=0; p<3; p++){
    for(int i=0; i<4; i++){
      digitalWrite(leds[i], HIGH);
      delay(150);
      digitalWrite(leds[i], LOW);
    }
  }
}

void loop(){

  if(patLength < maxSteps){
    int randIndex = random(0, 4);
    pat[patLength] = leds[randIndex];
    patLength++;
  }

  for(int i=0; i<patLength; i++){
    digitalWrite(pat[i], HIGH);
    tone(buz, NOTE_C6, 150);
    delay(500);
    digitalWrite(pat[i], LOW);
    noTone(buz);
    delay(200);
  }

  for(int i=0; i<patLength; i++){
    bool apasat=false;
    while(!apasat){
      for(int k=0; k<4; k++){
        if(digitalRead(btns[k]) == LOW){
          delay(200); 
          apasat = true;
          if(leds[k] == pat[i]){
            tone(buz, NOTE_E6, 100);
            digitalWrite(leds[k], HIGH);
            delay(150);
            digitalWrite(leds[k], LOW);
            noTone(buz);
          } else {
            tone(buz, NOTE_DS5, 800);
            for(int j=0;j<4;j++) digitalWrite(leds[j], HIGH);
            delay(1000);
            for(int j=0;j<4;j++) digitalWrite(leds[j], LOW);
            noTone(buz);
            patLength = 0;
            delay(1000);
            return; 
          }
        }
      }
    }
  }

  delay(1000);
}
