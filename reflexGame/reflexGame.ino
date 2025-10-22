#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <pitches.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int ledROSU1 = 8;
int ledROSU2 = 9;
int buzzer = 11;
int galben = 5, albastru = 6 , rosu = 7;
int btnSt = 2, btnDr = 3;
bool gameON = 0;
int randomD;
int score1=0, score2=0;
long prevTime;

int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5
};

int noteDurations[] = {
  8, 8, 8, 4, 8, 8, 8, 4, 2
};

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(ledROSU1, OUTPUT);
  pinMode(ledROSU2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(galben, OUTPUT);
  pinMode(albastru, OUTPUT);
  pinMode(rosu, OUTPUT);
  pinMode(btnSt, INPUT_PULLUP);
  pinMode(btnDr, INPUT_PULLUP);
  lcd.setCursor(4,0);
  lcd.print("Good Luck!");
}

void restart()
{
    digitalWrite(ledROSU1, LOW);
    digitalWrite(ledROSU2, LOW);
    digitalWrite(galben, LOW);
    digitalWrite(rosu, LOW);
    digitalWrite(albastru, LOW);
    gameON=1;
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(4,0);
    lcd.print("Good Luck!");
}

void victorySound()
{
  for(int i=0; i<9; i++)
      {
        int noteD = 1000/ noteDurations[i];
        tone(buzzer, melody[i], noteD);
        delay(noteD * 1.3);
        noTone(buzzer);
      }
}

void cheatSound()
{
  int time=300;
  tone(buzzer, NOTE_G5, time);
  delay(1.30*time);
  tone(buzzer, NOTE_E5, time);
  delay(1.30*time);
  tone(buzzer, NOTE_G5, time);
  delay(1.30*time);
  noTone(buzzer);
}

void score()
{
  lcd.setCursor(0,1);
  lcd.print("P1: ");
  lcd.setCursor(4,1);
  lcd.print(score1);
  lcd.setCursor(7,1);
  lcd.print("P2: ");
  lcd.setCursor(11,1);
  lcd.print(score2);
}

void loop() {
  

    gameON=0;
    randomSeed(analogRead(A0));
    randomD=random(1000,5000);
    digitalWrite(galben, HIGH);
    analogWrite(buzzer, 500);
    delay(500);
    analogWrite(buzzer, 0);
    delay(500);
    digitalWrite(albastru, HIGH);
    analogWrite(buzzer, 500);
    delay(500);
    analogWrite(buzzer, 0);
    delay(500);
    digitalWrite(rosu, HIGH);
    analogWrite(buzzer, 500);
    delay(500);
    analogWrite(buzzer, 0);
    delay(500);
    prevTime = millis();
    while (millis() - prevTime < randomD) {
      if (digitalRead(btnSt) == LOW) {
        score1--;
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Don't cheat P1!");
        score();
        cheatSound();
        delay(2000);
        restart();
        return; 
      }

      if (digitalRead(btnDr) == LOW) {
        score2--;
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Don't cheat P2!");
        score();
        cheatSound();
        delay(2000);
        restart();
        return;
      }
    }
    while(gameON == 0)
    {   
        digitalWrite(ledROSU1, HIGH);
        digitalWrite(ledROSU2, HIGH);

        if(digitalRead(btnSt) == 0)
        {
          score1++;
          lcd.setCursor(4,0);
          lcd.print("           ");
          lcd.setCursor(0,0);
          lcd.print("Winner 1");
          lcd.setCursor(0,1);
          digitalWrite(ledROSU2, LOW);
          score();
          victorySound();
          restart();
        }
        else if(digitalRead(btnDr) == 0)
        {
          score2++;
          lcd.setCursor(4,0);
          lcd.print("           ");
          lcd.setCursor(0,0);
          lcd.print("Winner 2");
          score();
          digitalWrite(ledROSU1, LOW);
          victorySound();
          restart();
      }
    }

}
