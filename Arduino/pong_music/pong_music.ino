/***********************************
 * 
 * Arduino version of the classic game 'Pong' using 16x2 LCD. Input from DTMF.
 * A small buzzer in use for random 8-bit sound effects.
 * 
 * Wrote this sketch to learn coding and electronics, please
 * pardon the unnecessary convolution of code.
 * 
 * @krohak
 *********************************/
 
 #include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int y = 0; 
int w = -1; 
int dela = 50;
int a =1;  //0
int b =0;  //1
int c =1;  //2
int d =1;  //3
int r =0;
int l=0;
int points_A = 0;
int points_B = 0;
int point_disp = 700;
int P=0;
int O=0;
int N=0;
int G=0;

void setup() {

  lcd.begin(16, 3);
  
  pinMode (10,1); //for buzz out


}

void loop() {

  //get values constantly from DTMF

  a =    digitalRead (6); //0
  b =   digitalRead (7);  //1
  c =   digitalRead (8);  //2          
  d =   digitalRead (9);  //3


/**************************************************START******************************************************************/

  if (w== -1) {


    if (a==1 && b== 0 && c==1 && d==1) { //A to start

      w=0;

    } 
    else if (a==0 && b== 0 && c==0 && d==0) { //D for animation

      w=8;

    }


    lcd.setCursor(0,0); 

    lcd.print("Press A to start"); 

  }



  /*******************************GAME***********************************/



  if (w==0){     // go right

    for ( int x = 2; x<= 14; x++) {



      //get values constantly from DTMF


      a =    digitalRead (6); //0
      b =   digitalRead (7);  //1
      c =   digitalRead (8);  //2          
      d =   digitalRead (9);  //3


      //print and set left 

      lcd.setCursor(0,l);

      lcd.print("|"); 

      delay (dela);


      //change right as pong goes to right

      if (a==1 && b== 1 && c==0 && d==1)
      { 

        r = 1;  
      } 

      else if (a==0 && b== 0 && c==1 && d==1)
      {

        r=0;

      }


      lcd.setCursor(15,r);

      lcd.print("|"); 

      delay (dela);



      //randomize pong (due to the fact that there are only two rows in the matrix)



      y= rand() % 2;

      lcd.clear();

      lcd.setCursor(x, y);

      lcd.print("*"); 



      delay (dela);


      if (x== 14){         //go left

        if (r==y){
          tone (10, 1200, 100);


          w=1;

        } 
        else {


          w=5;

          points_A++;


        }



      }
    }

  }


  if (w==1){     //left



    for ( int x = 13; x>=1; x--) {


      a =    digitalRead (6); //0
      b =   digitalRead (7);  //1
      c =   digitalRead (8);  //2
      d =   digitalRead (9);  //3


      lcd.setCursor(15,r);   //set right acc to prev value

      lcd.print("|"); 

      delay (dela);



      if (a==1 && b== 0 && c==0 && d==0)
      { 

        l = 1;

      } 

      else if (a==1 && b== 1 && c==0 && d==0)
      {

        l=0;


      } 

      lcd.setCursor(0,l);

      lcd.print("|"); 

      delay (dela);



      y= rand() % 2;



      lcd.clear(); 

      lcd.setCursor(x, y);

      lcd.print("*"); 

      delay (dela);

      if (x== 1){


        if (l==y){

          tone (10, 1200, 100);

          w=0;
        } 
        else {

          w=5;
          points_B++;


        }
      } 
    }

  }


  /******************Display points*****************************/


  if (w==5){

    //fancaayy

    for (int i =2200; i>200; i=i-100){  //for points display sound


      lcd.setCursor(15,r);   //set right acc to prev value

      lcd.print("|"); 



      lcd.setCursor(0,l);     //print and set left 

      lcd.print("|"); 



      lcd.setCursor(5,0);

      lcd.print("A");


      lcd.setCursor(5,1);

      lcd.print(points_A);


      lcd.setCursor(10,0);

      lcd.print("B");


      lcd.setCursor(10,1);

      lcd.print(points_B);
      
      

      tone (10, i, 150);
      
      
      

      w= rand()%2;   //start from random position
    }
    
    

    delay (point_disp);
    
    
    
    
    
    /********STOP (works only when points are displayed)*******************/


    if (a==1 && b== 1 && c==1 && d==1) {    //C


      w=6;

    }

  } 


  //display winner on stop and cue fancy music


  if (w==6){


    lcd.clear();

    for (int i =200; i<2200; i=i+100){ 

      if (points_A > points_B){

        lcd.setCursor(0,0); 

        lcd.print("     A WINS "); 

        //delay (dela);


      } 
      else if (points_A < points_B){

        lcd.setCursor(0,0); 

        lcd.print("     B WINS "); 

        //delay (dela);



      } 
      else {


        lcd.setCursor(0,0); 

        lcd.print("       TIE  "); 

        //delay (dela);

      }



      tone (10, i, 50);

      delay (100);



    }

    //to reset

    if (a==0 && b==1 && c==1 && d==1){  //B


      w=-1;
int points_A = 0;
int points_B = 0;


    }




  }


  /*********************Fancy ann-D*******************************************/

  if (w==8) {



    for (int i =200; i<2200; i=i+100){ //pongtheme


      lcd.setCursor(1, 0);

      lcd.print("PONG"); 



      tone (10, i, 50);

      delay (100);

      lcd.clear();


    }   


    P=1;
    O=1;
    N=1;
    G=1;

    w=11;

  }


  if (P==1){


    for ( int x = 1; x<= 15; x++) {

      y= rand() % 2;

      lcd.clear();

      lcd.setCursor(x, y);

      lcd.print("P"); 

      delay (dela);

      if (x== 15){         //go left

        tone (10, 1000, 100);

        P=2;

      } 
    }
  }


  if (O==1){

    for ( int x = 2; x<= 15; x++) {

      y= rand() % 2;

      lcd.clear();

      lcd.setCursor(x, y);

      lcd.print("O"); 

      delay (dela);

      if (x== 15){         //go left

        tone (10, 1000, 100);
        O=2;

      } 
    } 
  }



  if (N==1){        


    for ( int x = 3; x<= 15; x++) {

      y= rand() % 2;

      lcd.clear();

      lcd.setCursor(x, y);

      lcd.print("N"); 

      delay (dela);

      if (x== 15){         //go left

        tone (10, 1000, 100);
        N=2;

      }
    }
  }




  if (G==1){        


    for ( int x = 4; x<= 15; x++) {

      y= rand() % 2;

      lcd.clear();

      lcd.setCursor(x, y);

      lcd.print("G"); 

      delay (dela);

      if (x== 15){         //go left

        tone (10, 1000, 100);
        G=2;

      }


    }
  }


  if (P==2){

    for ( int x = 15; x>=0; x--) {

      y= rand() % 2;

      lcd.clear(); 

      lcd.setCursor(x, y);

      lcd.print("P"); 

      delay (dela);

      if (x== 0){

        tone (10, 1500, 100);
        P=1;

      }
    }
  }

  if (O==2){

    for ( int x = 15; x>=0; x--) {

      y= rand() % 2;

      lcd.clear(); 

      lcd.setCursor(x, y);

      lcd.print("O"); 

      delay (dela);

      if (x== 0){
        tone (10, 1000, 100);

        O=1;


      }
    }



  }

  if (N==2){

    for ( int x = 15; x>=0; x--) {

      y= rand() % 2;

      lcd.clear(); 

      lcd.setCursor(x, y);

      lcd.print("N"); 

      delay (dela);

      if (x== 0){

        tone (10, 1000, 100);
        N=1;


      }
    }



  }

  if (G==2){

    for ( int x = 15; x>=0; x--) {

      y= rand() % 2;

      lcd.clear(); 

      lcd.setCursor(x, y);

      lcd.print("G"); 

      delay (dela);

      if (x== 0){

        tone (10, 1000, 100);
        G=1;


      }
    }



  }



}





