#include <pitches.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int senzorT = A2;
int readValue;
float voltValue;
float temp;

int intervalLCD = 1000;
unsigned long prevMillisLCD;

int intervalServo = 20;
unsigned long prevMillisServo;

Servo servo;
int ptmUsa = A3;
int prevAngle = 0;

int buz = 11;
int btn = 8;
int melody[] = {
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C6, NOTE_G5
};
int noteT[] = {
  4, 4, 4, 4, 2
};

void setup() {
  servo.attach(9);
  lcd.init();
  lcd.backlight();
  pinMode(btn, INPUT_PULLUP);
  pinMode(buz, OUTPUT);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
}

void ecran() {
  unsigned long currentMillis = millis();

  if (currentMillis - prevMillisLCD >= intervalLCD) {
    prevMillisLCD = currentMillis;  

    analogRead(senzorT);
    readValue = analogRead(senzorT);
    voltValue = readValue * (5.0 / 1023.0);
    temp = voltValue * 100;

    lcd.setCursor(6,0);
    lcd.print("   ");      
    lcd.setCursor(6,0);
    lcd.print(temp);
  }


  // Incercam sa deschid usa si sa afisez mesaj pe lcd
  // if(prevAngle > angle)
  // {
  //   lcd.print("La revedere!"); 
  // }
  // else
  // {
  //   lcd.print("Salut!"); 
  // }
  // prevAngle=angle;

}

void sonerie()
{
  if (digitalRead(btn) == LOW) {

    for (int i = 0; i < 5; i++) {
      int noteDur = 1000 / noteT[i];   
      tone(buz, melody[i], noteDur);

      float delayNote = 1.30 * noteDur; 
      delay(delayNote);
    }
    noTone(buz); 
  }
}

void servoUsa()
{
  unsigned long currentMillis = millis();
  int readValue = analogRead(ptmUsa);
  int angle = map(readValue, 0 ,1023, 0, 180);
  if(currentMillis - prevMillisServo >= intervalServo) 
  {
    prevMillisServo = currentMillis;
    servo.write(angle);
  }
  //ecran(angle);
}

void loop()
{
  sonerie();
  servoUsa();
  ecran();
  
  
}
