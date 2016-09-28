/***********************************
 * 
 * Arduino version of the classic game Snake.
 * 
 *User controls the snake which is made of a combination of different custom 
 *characters, based on the position of the snake. 
 *
 *Using LCD screen for display and DTMF for input. Displays the time and points 
 *at the end of the game.
 * 
 * @krohak
 *********************************/
 #include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//custom characters
byte body [8] = {
      
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111,
        B11111,
        B00000

};

byte eye_right [8] = {
      
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11101,
        B11111,
        B00000

};

byte eye_left [8] = {
      
         B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B10111,
        B11111,
        B00000

};

byte tail_right [8] = {

         B00000,
        B00000,
        B00000,
        B00000,
        B01111,
        B11111,
        B01111,
        B00000

};

byte tail_left [8] = {

         B00000,
        B00000,
        B00000,
        B00000,
        B11110,
        B11111,
        B11110,
        B00000

};


byte eat_right[8] = {
      
      B00000,
        B00000,
        B01100,
        B10111,
        B11000,
        B10010,
        B11000,
        B00111


};

byte eat_left[8] = {
      
       B00000,
        B00000,
        B00110,
        B11101,
        B00011,
        B01001,
        B00011,
        B11100


};

int x = 0;
int y = 0; 
int w = -1; 
int t = 0;
int u = 0;
int t_1[400];
int u_1[400];
int dela = 400;
int a =0;  //0
int b =0;  //1
int c =0;  //2
int d =0;  //3
int a_1 =0;  //ref 0
int b_1 = 0; //ref 1
int c_1 = 0; //ref 2
int d_1 = 0; //ref 3
int pix=0;
int z_1 = rand()%16; //for x of coin
int z_2 = rand()%2;  //for y of coin
int lim=2; // no of snake dots
int points=0;
const int max_points=14;
int time=0;

void setup() {

  lcd.begin(16, 3);

  pinMode (10,1); //for buzz out
  
  lcd.createChar (1, body);
   lcd.createChar (2, eye_right);
    lcd.createChar (5, eye_left );
   lcd.createChar (3, tail_right);
   lcd.createChar (4, tail_left);
   lcd.createChar (6, eat_right);
lcd.createChar (7, eat_left);


}

/********************************************************************/

void read_dtmf () {


  //get values constantly from DTMF

  a =    digitalRead (6); //0
  b =   digitalRead (7);  //1
  c =   digitalRead (8);  //2          
  d =   digitalRead (9);  //3


}


void Print (){     //print snake, coin, increment snake, randomize coin, pts++, time



  lcd.setCursor(t, u);  //eye
  
  if (a==0 && b== 0 && c==1 && d==0) {  //left
    
    lcd.write (5);
      
    } else {

  lcd.write (2); //right
 
    }
    
  for (int num = 1; num<lim; num++) {  //body and tail

    lcd.setCursor(t_1[(pix-num)], u_1[(pix-num)]); //body

    lcd.write (1);
    
    lcd.setCursor(t_1[(pix-(num+1))], u_1[(pix-(num+1))]);  //tail
    
 if (a==0 && b== 0 && c==1 && d==0) {  //left
    
    lcd.write (4);
      
    }
    
    else if ((a==0 && b== 1 && c==0 && d==0) || (a==0 && b== 0 && c==0 && d==1)) //up and down
    
    {  }
    
    else {  //right
    
    lcd.write (3); 
    
    }
    
  }
  
  

  lcd.setCursor(z_1, z_2);

  lcd.print("."); 


  if ( t== z_1 && u == z_2) {
    
    lcd.setCursor(t, u);       //eatface
         
   if (a==0 && b== 0 && c==1 && d==0) {  //left
    
    lcd.write (7);
    
    delay (dela/4);
      
    } else {

  lcd.write (6); //right
  
  delay (dela/4);
 
    }

    lim++;
    points++;

    z_1 = rand()%16;
    z_2= rand()%2;

  }

  time = millis()/1000;

}





void loop() {

  /**************************************************START*************************************************/

  if (w== -1) {

    int f=1000;
    
    read_dtmf ();
    
    a_1 = a;
    b_1 = b;
    c_1 = c;
    d_1 = d;

    if (a==1 && b== 0 && c==1 && d==1) { //A to start

      w=0;

    } 


    lcd.setCursor(0,0); 

    lcd.print("Press A to start"); 
    
    for (int ran=0; ran< f ; ran++) {  //for high level of randomizations
    
     read_dtmf ();


        if ( a != a_1 || b != b_1 || c != c_1 || d != d_1 ) {
        
        
        f= ran-1;
        
        
        }
        
        
      z_1 = rand()%16;
    z_2= rand()%2;
    
    
    }
    
    
    

  }

  /**********************************STOP***********************************************/


  if (w==2){


    lcd.setCursor(0, 0);

    lcd.print("   Points: "); 
    lcd.print(points); 


    lcd.setCursor(0, 1);

    lcd.print("   Time: "); 
    lcd.print(time);
    lcd.print("s");


  }



  /*************************************GAME************************************************************/



  if (w==0){     

    read_dtmf ();

    a_1 = a;
    b_1 = b;
    c_1 = c;
    d_1 = d;

    lcd.clear();



    if (a==0 && b== 1 && c==0 && d==0)  //2 to up

    { 


      int f=0; //to stop loop


      for (  y = u+240; y>= f; y-- ) {

        read_dtmf ();


        if ( a != a_1 || b != b_1 || c != c_1 || d != d_1 || points >= max_points) {

          f=y+1;

        } 
        u = y%2;



        Print();



        delay (dela+100);

        lcd.clear();

        t_1[pix] = t;
        u_1[pix] = u;

        pix++;

      }




    }

    else  if (a==0 && b== 0 && c==1 && d==0)  //4 to left

    { 


      int f=0; //to stop loop


      for (  x = t+240; x>= f; x--) {

        read_dtmf ();


        if ( a != a_1 || b != b_1 || c != c_1 || d != d_1 || points >= max_points) {

          f=x+1;

        } 
        t = x%16;

        Print();

        delay (dela);

        lcd.clear();

        t_1[pix] = t;
        u_1[pix] = u;

        pix++;

      }

    }




    else if (a==0 && b== 1 && c==1 && d==0)  //6 to right
    {
      int f= 256; //to stop loop

      for (  x = t; x<= f; x++) {

        read_dtmf ();

        if ( a != a_1 || b != b_1 || c != c_1 || d != d_1 || points >= max_points ) {

          f=x-1;

        }
        t= x%16;

        Print();

        delay (dela);

        lcd.clear();

        t_1[pix] = t;
        u_1[pix] = u;

        pix++;


      }

    }


    else if (a==0 && b== 0 && c==0 && d==1)  //8 to down
    {


      int f= 256; //to stop for loop

      for (  y = u; y<= f; y++) {

        read_dtmf ();

        if ( a != a_1 || b != b_1 || c != c_1 || d != d_1 || points >= max_points) {

          f=y-1;

        }
        u= y%2;

        Print();

        delay (dela+100);

        lcd.clear();

        t_1[pix] = t;
        u_1[pix] = u;

        pix++;

      }

    }

    else if (a==0 && b== 0 && c==0 && d==0) { //D for stop

      w=2;

    }

    else {

      int f= 256;

      for (  x = t; x<= f; x++) {

        read_dtmf ();

        if ( a != a_1 || b != b_1 || c != c_1 || d != d_1 || points >= max_points) {

          f=x-1;

        }
        t= x%16;

        Print();

        delay (dela);

        lcd.clear();

        t_1[pix] = t;
        u_1[pix] = u;

        pix++;


      }  

    } 


    if (points >=  max_points){
      w=2;
    } //to stop screen



  }



}

