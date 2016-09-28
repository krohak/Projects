/***********************************
 * 
 * Line-Following Car built for competing in a competition organized by
 * The Hong Kong Institute of Engineers, called 'Ambitions'. The Car uses 
 * two infrared sensors at the front to detect the line and two servo motors 
 * attached to a motor controller board for autonomous control
 * 
 * @krohak
 *********************************/

#include <Servo.h>

Servo rservo; 
Servo lservo; 

int rspeed=0;//fwdmax
int lspeed=180;//fwdmax

int rt=0;
int lt=0;

void setup() {
  
  pinMode (5,0);
  pinMode (6,0);
  pinMode (7,0);
  pinMode (8,0);

  rservo.attach(9);
  lservo.attach(10);
  pinMode (2,1);
  Serial.begin (9600);
}

int bob=2;
int bob2=30;


/************functions*********************************************/

void right_soft_turn()    
{
  rspeed=90-bob2;
  lspeed=90+bob;
  rservo.write(rspeed);
  lservo.write(lspeed);
  }
  
void left_soft_turn()
{
  rspeed=90-bob;
  lspeed=90+bob2;
  rservo.write(rspeed);
  lservo.write(lspeed);
  }
  
void left_hard_turn()
{
  rspeed=180;
  lspeed=180;
  rservo.write(rspeed);
  lservo.write(lspeed);
  }
  
 void right_hard_turn()
{
  rspeed=0;
  lspeed=0;
  rservo.write(rspeed);
  lservo.write(lspeed);
  }
  
void straight()
{
  rspeed=0;
  lspeed=180;  
  rservo.write(rspeed);
  lservo.write(lspeed);
  }
  
void loop() {
  
  rservo.write(rspeed);
  lservo.write(lspeed);

  int fl = digitalRead (5);
  int fr = digitalRead (6);
  int bl = digitalRead (7);
  int br = digitalRead (8);
  
  delay(10);

if (bl == 0 && br == 0 && fl == 0 && fr == 0) {


  straight();
  
  delay(10);
  
  }


if(bl==1 && fr==1 && rt==0){
  right_soft_turn();
  delay(10);
  rt=1;
  }
  
else if(br==1 && fl==1&& lt==0){
  left_soft_turn();
  delay(10);
  rt=1;
  }
  
else if(bl==1||fl==1){
 right_soft_turn(); 
 delay(10); 
 rt=1; 
 lt=0;
 }
 
  else if(br==1||fr==1){
  left_soft_turn(); 
  delay(10);
  rt=0; 
  lt=1;
  }
  
  
  else{
  straight(); 
  delay(10);
  rt=0; 
  lt=0;
  }


}



  

