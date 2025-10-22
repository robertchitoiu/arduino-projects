#define SG 2
#define SF 3
#define SA 4
#define SB 5
#define SE 6
#define SD 7
#define SC 8

int timp=500;

int segmente[7]={2,3,4,5,6,7,8};
void setup() {
  for(int i=0;i<7;i++)
  {
     pinMode(segmente[i],OUTPUT);
  }
}
 
void loop() { 
  //1
  digitalWrite(SB, HIGH);
  digitalWrite(SC, HIGH);
  delay(1000);
  digitalWrite(SB, LOW);
  digitalWrite(SC, LOW);


  //2
  digitalWrite(SA, HIGH);
  digitalWrite(SB, HIGH);
  digitalWrite(SG, HIGH);
  digitalWrite(SE, HIGH);
  digitalWrite(SD, HIGH);
  delay(1000);
  digitalWrite(SA, LOW);
  digitalWrite(SB, LOW);
  digitalWrite(SG, LOW);
  digitalWrite(SE, LOW);
  digitalWrite(SD, LOW);

  //3
  digitalWrite(SA, HIGH);
  digitalWrite(SB, HIGH);
  digitalWrite(SG, HIGH);
  digitalWrite(SC, HIGH);
  digitalWrite(SD, HIGH);
  delay(1000);
  digitalWrite(SA, LOW);
  digitalWrite(SB, LOW);
  digitalWrite(SG, LOW);
  digitalWrite(SC, LOW);
  digitalWrite(SD, LOW);
 

  //4
  digitalWrite(SF, HIGH);
  digitalWrite(SB, HIGH);
  digitalWrite(SG, HIGH);
  digitalWrite(SC, HIGH);
  delay(1000);
  digitalWrite(SF, LOW);
  digitalWrite(SB, LOW);
  digitalWrite(SG, LOW);
  digitalWrite(SC, LOW);
 

  //5
  digitalWrite(SA, HIGH);
  digitalWrite(SF, HIGH);
  digitalWrite(SG, HIGH);
  digitalWrite(SC, HIGH);
  digitalWrite(SD, HIGH);
  delay(1000);
  digitalWrite(SA, LOW);
  digitalWrite(SF, LOW);
  digitalWrite(SG, LOW);
  digitalWrite(SC, LOW);
  digitalWrite(SD, LOW);
  

  //6
  digitalWrite(SA, HIGH);
  digitalWrite(SF, HIGH);
  digitalWrite(SC, HIGH);
  digitalWrite(SG, HIGH);
  digitalWrite(SE, HIGH);
  digitalWrite(SD, HIGH);
  delay(1000);
  digitalWrite(SA, LOW);
  digitalWrite(SF, LOW);
  digitalWrite(SG, LOW);
  digitalWrite(SE, LOW);
  digitalWrite(SD, LOW);
  digitalWrite(SC, LOW);
  

  //7 
  digitalWrite(SA, HIGH); 
  digitalWrite(SB, HIGH);
  digitalWrite(SC, HIGH); 
  delay(1000);
  digitalWrite(SA, LOW); 
  digitalWrite(SB, LOW);
  digitalWrite(SC, LOW); 
  

  //8
  digitalWrite(SA, HIGH);
  digitalWrite(SB, HIGH);
  digitalWrite(SF, HIGH);
  digitalWrite(SC, HIGH);
  digitalWrite(SG, HIGH);
  digitalWrite(SE, HIGH);
  digitalWrite(SD, HIGH);
  delay(1000);
  digitalWrite(SA, LOW);
  digitalWrite(SB, LOW);
  digitalWrite(SF, LOW);
  digitalWrite(SG, LOW);
  digitalWrite(SE, LOW);
  digitalWrite(SD, LOW);
  digitalWrite(SC, LOW);
 
  //9
  digitalWrite(SA, HIGH);
  digitalWrite(SB, HIGH);
  digitalWrite(SF, HIGH);
  digitalWrite(SC, HIGH);
  digitalWrite(SG, HIGH);
  digitalWrite(SD, HIGH);
  delay(1000);
  digitalWrite(SA, LOW);
  digitalWrite(SB, LOW);
  digitalWrite(SF, LOW);
  digitalWrite(SG, LOW);
  digitalWrite(SD, LOW);
  digitalWrite(SC, LOW);


}
