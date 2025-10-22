  Proiect Arduino: Termometru cu LCD, Servo și Sonerie
Acest proiect folosește un Arduino pentru a măsura temperatura, a o afișa pe un ecran LCD, a mișca un servomotor și a reda o melodie pe un buzzer atunci când este apăsat un buton.

  Componente folosite
Arduino UNO
LCD 16x2 cu I2C (adresă 0x27)
Senzor de temperatură (ex. LM35) – pin A2
Servomotor – pin 9
Potențiometru pentru servo – pin A3
Buzzer – pin 11
Buton – pin 8

Ce face programul:

🔹 Afișarea temperaturii
Senzorul de pe pinul A2 citește temperatura.
Valoarea este convertită în grade Celsius și afișată pe LCD.
Afișarea se actualizează o dată pe secundă.

🔹 Controlul servomotorului
Potențiometrul de pe A3 controlează poziția servomotorului.
Unghiul variază între 0° și 180°.

🔹 Soneria (buzzer)
Când se apasă butonul, buzzerul redă o scurtă melodie formată din 5 note.

Structura codului
setup() – inițializează LCD-ul, servo-ul, buzzerul și butonul.
loop() – rulează continuu cele 3 funcții principale:
ecran() – citește și afișează temperatura.
servoUsa() – controlează mișcarea servomotorului.
sonerie() – redă melodia dacă este apăsat butonul.

Proiect realizat ca exercițiu pentru învățarea componentelor Arduino (LCD, servo, senzor, buzzer, buton).
