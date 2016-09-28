/***********************************
 * 
 * The code for a Rube Goldberg machine built for the final project of my Intro to
 * Electrical and Electronics Engineering course at The University of Hong Kong.
 * 
 * @krohak
 *********************************/
#include <Servo.h>

int motorstage1=11;
int solenoidstage3=8;
int stage5motor=12;

Servo Stage2; 
Servo Stage3;

int led4=7;
int led1=4;
int led2=6;
int led3=5;
int bc=A0;

void setup() {
  
  pinMode(8,1);//Solenoid st3
  
  Stage2.attach(9); 
  Stage2.write(90);
  Stage3.attach(10);
  Stage3.write(90);
  
  pinMode(12,1);
   pinMode(11,1);//Motor Stage 1
   pinMode(13,1);
   
   Serial.begin(9600);
   
   pinMode(4,1);
   pinMode(5,1);
   pinMode(6,1);
   pinMode(7,1);
   
   digitalWrite(led1,1);
   
   Serial.begin(9600);
   
}

void loop() {
  Serial.println(analogRead(A0));
 
  if((analogRead(A0))<500)
  {

/************************STAGE 1********************************************************/    
  
 Serial.println("BEGIN");
  digitalWrite(motorstage1, 1);
  delay(12500);
  digitalWrite(motorstage1, 1);
  Serial.println("s1done");

/************************STAGE 2********************************************************/
 
   delay(5000);
  Stage2.write(105);
  delay(700);
  Stage2.write(90);
  delay(1000);
  Stage2.write(75);
  delay(300);
  Stage2.write(90);
  delay(10);
  Serial.println("s2done");

  
 /************************STAGE 3********************************************************/ 
 
  delay(2000);     //20.200
  Stage3.write(75);
   delay(18000);
  //Solenoid starts here
  digitalWrite(solenoidstage3, 1);
  delay(3500);
 /* delay(500);
  digitalWrite(solenoidstage3, LOW);
  delay(500);
  digitalWrite(solenoidstage3, HIGH);
  delay(500);
  digitalWrite(solenoidstage3, LOW);
  delay(500);
  digitalWrite(solenoidstage3, HIGH);
  delay(500);
  delay(500);
  */
  
  Stage3.write(90);
  delay(1000);
 
  /////////////////////
  
  digitalWrite(solenoidstage3, 0);
  (3000);

  /************************STAGE 4********************************************************/
  
    digitalWrite(led1,1);
  delay(1000);
  
  digitalWrite(led2,1);
  delay(500);
  digitalWrite(led1,0);
  delay(1000);
  digitalWrite(led3,1); delay(500);digitalWrite(led2,0);
  delay(1000);
  digitalWrite(led4,1); delay(500);digitalWrite(led3,0);
  delay(1000);
  digitalWrite(led3,1); delay(500);digitalWrite(led4,0);
  delay(1000);
  digitalWrite(led2,1); delay(500);digitalWrite(led3,0);
  delay(1000);
  digitalWrite(led1,1); delay(500);digitalWrite(led2,0);
  //delay(1000);

/************************STAGE 5********************************************************/

  //delay(1000);
  digitalWrite(stage5motor,1);
  delay(4000);
  digitalWrite(stage5motor,0);
  delay(1000);

 ////////////////////////////////////Stage3 unwind
  Stage3.write(105);
  delay(3000);
  delay(18250);
  Stage3.write(90);
  delay(1000);
  
  delay(10000000);
  
  
  ////
  }

}
