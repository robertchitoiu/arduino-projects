#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int waterSensor = 0;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Nivelul");
  lcd.setCursor(0,1);
  lcd.print("apei: ");
}

void loop()
{
    int value = analogRead(waterSensor);
    lcd.print("      ");
    lcd.setCursor(6,1);

    if(value>=0 && value<=300)
    {
      lcd.print("LOW");
    }
    else if(value>300 && value<=370)
    {
      lcd.print("MEDIUM");
    }
    else if(value>370 && value<=600)
    {
      lcd.print("HIGH");
    }
    delay(200);



}
