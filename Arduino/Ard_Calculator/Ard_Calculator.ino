/***********************************
 * 
 * A very basic Arduino sketch for a Calculator using
 * DTMF as input and four 7-Segment LED displays as output.
 * 
 * Wrote this sketch to learn coding and electronics, please
 * pardon the unnecessary convolution of code.
 * 
 * @krohak
 *********************************/


int x=0;
int y=0;
int z=0;
int s=0;
int q_1=0;
int q_2=0;
int result =0;
int wait =1;
int dela = 700;
int opp = 0;


void setup(){

 //DTMF in  3-3 2-2 1-1 0-0
  
for (int i=0; i<4; i++) {

pinMode (i,0);

}  


//switch 4

pinMode (4,0);

//7 seg

for (int j=5; j<12; j++) {

pinMode (j,1);

//dsp 1&2&3&4

pinMode (14,1);
pinMode (15,1);
pinMode (16,1);
pinMode (17,1);

}  
}

/***********************************functions*********************************************************/
void print_nothing (){

    digitalWrite (9, 1);
  digitalWrite (10, 1);
  digitalWrite (5,1);
  digitalWrite (6, 1);
  digitalWrite (7, 1);
  digitalWrite (8, 1);
  digitalWrite (11, 1);
}


void print_1 (){

  //1    

    digitalWrite (9, 0);
  digitalWrite (10, 0);
  digitalWrite (5,1);
  digitalWrite (6, 1);
  digitalWrite (7, 1);
  digitalWrite (8, 1);
  digitalWrite (11, 1);
  
 

}


void print_2 (){


  //2

    digitalWrite (5,0);
  digitalWrite (6, 1);
  digitalWrite (7, 0);
  digitalWrite (8, 0);
  digitalWrite (9, 1);
  digitalWrite (10, 0);
  digitalWrite (11, 0);
  
  


}
void print_3 (){


  //3

    digitalWrite (5,0);
  digitalWrite (6, 1);
  digitalWrite (7, 1);
  digitalWrite (8, 0);
  digitalWrite (9, 0);
  digitalWrite (10, 0);
  digitalWrite (11, 0);
  
  


}
void print_4 (){

  //4


    digitalWrite (5,0);
  digitalWrite (6, 0);
  digitalWrite (7, 1);
  digitalWrite (8, 1);
  digitalWrite (9, 0);
  digitalWrite (10, 0);
  digitalWrite (11, 1);



}
void print_5 (){


  //5

    digitalWrite (5,0);
  digitalWrite (6, 0);
  digitalWrite (7, 1);
  digitalWrite (8, 0);
  digitalWrite (9, 0);
  digitalWrite (10, 1);
  digitalWrite (11, 0);



}
void print_6 (){


  //6

    digitalWrite (5,0);
  digitalWrite (6, 0);
  digitalWrite (7, 0);
  digitalWrite (8, 0);
  digitalWrite (9, 0);
  digitalWrite (10, 1);
  digitalWrite (11, 0);
  
 


}
void print_7 (){


  //7

    digitalWrite (9, 0);
  digitalWrite (10, 0);
  digitalWrite (5,1);
  digitalWrite (6, 1);
  digitalWrite (7, 1);
  digitalWrite (8, 1);
  digitalWrite (11, 0);
  
 


}
void print_8 (){

  //8

    digitalWrite (5,0);
  digitalWrite (6, 0);
  digitalWrite (7, 0);
  digitalWrite (8, 0);
  digitalWrite (9, 0);
  digitalWrite (10, 0);
  digitalWrite (11, 0);


}
void print_9 (){


  //9

    digitalWrite (5,0);
  digitalWrite (6, 0);
  digitalWrite (7, 1);
  digitalWrite (8, 0);
  digitalWrite (9, 0);
  digitalWrite (10, 0);
  digitalWrite (11, 0);
  
 


}
void print_0 (){

  // 0


    digitalWrite (5,1);
  digitalWrite (6, 0);
  digitalWrite (7, 0);
  digitalWrite (8, 0);
  digitalWrite (9, 0);
  digitalWrite (10, 0);
  digitalWrite (11, 0);



}

void print_plus () {

  //+
      digitalWrite (5,0);
  digitalWrite (6, 0);
  digitalWrite (7, 0);
  digitalWrite (8, 1);
  digitalWrite (9, 1);
  digitalWrite (10, 1);
  digitalWrite (11, 1);



}

void print_minus () {

//-
  
digitalWrite (5,0);
  digitalWrite (6, 1);
  digitalWrite (7, 1);
  digitalWrite (8, 1);
  digitalWrite (9, 1);
  digitalWrite (10, 1);
  digitalWrite (11, 1);



}

void print_multiply () {

   //*

    digitalWrite (5,0);
  digitalWrite (6, 0);
  digitalWrite (7, 0);
  digitalWrite (8, 1);
  digitalWrite (9, 0);
  digitalWrite (10, 0);
  digitalWrite (11, 1);
  
 
  
}

void print_divide () {

 // /

    digitalWrite (5,0);
  digitalWrite (6, 1);
  digitalWrite (7, 1);
  digitalWrite (8, 0);
  digitalWrite (9, 1);
  digitalWrite (10, 1);
  digitalWrite (11, 0);
  


}

/***************************************************/

void Print_r (int r) {
    
 if (r==0) {                  

      

      print_0();

    } 
    else if (r==1){

     

      print_1();
      
     

    } 
    else if (r==2){

   

      print_2();

     
    }
    
    else if (r==3){

     
      print_3();
      
      
    }

    else if (r==4){

    

      print_4();
      
     
    }

    else if (r==5){

     

      print_5();
      
    
    }

    else if (r==6){

    

      print_6();
      
     
    }

    else if (r==7){

      

      print_7();
      
     
    }

    else if (r==8){

      

      print_8();
      
   
    }

    else if (r==9){

      

      print_9();
      
     
    }


}

/***********************************************************************************************************/

void loop(){

   x=    digitalRead (0); 
   y =   digitalRead (1); 
   z =   digitalRead (2); 
   s =   digitalRead (3); 
   
   int w = wait;  //to set the step for loop

/***********************first number*********************/ 

if (w==1) {                 
   
   if (x==1 && y== 0 && z==0 && s==0)
  {
digitalWrite (15, 1);
    print_1();
    delay (dela);
    q_1=1;
    wait=2;
digitalWrite (15, 0);
  } 
  else if (x==0 && y== 1 && z==0 && s==0)
  {
digitalWrite (15, 1);
   print_2();
   delay (dela);
    q_1=2;
    wait=2;
digitalWrite (15, 0);
  } 
  else if (x==1 && y== 1 && z==0 && s==0)
  {
digitalWrite (15, 1);
    print_3();
    delay (dela);
     q_1=3;
     wait=2;
digitalWrite (15, 0);    
  } 


  else if (x==0 && y== 0 && z==1 && s==0)
  {
digitalWrite (15, 1);
   print_4();
   delay (dela);
    q_1=4;
    wait=2;
digitalWrite (15, 0);
  } 


  else if (x==1 && y== 0 && z==1 && s==0)
  {
digitalWrite (15, 1);
    print_5();
    delay (dela);
     q_1=5;
     wait=2;
digitalWrite (15, 0);    
  } 


  else if (x==0 && y== 1 && z==1 && s==0)
  {
digitalWrite (15, 1);
 print_6();  
 delay (dela);
  q_1=6;
  wait=2;
digitalWrite (15, 0);
  } 

  else if (x==1 && y== 1 && z==1 && s==0)
  {
digitalWrite (15, 1);
    print_7();
    delay (dela);
     q_1=7;
     wait=2;
digitalWrite (15, 0);    
  } 


  else if (x==0 && y== 0 && z==0 && s==1)
  {
digitalWrite (15, 1);    
print_8();
delay (dela);
 q_1=8;
 wait=2;
digitalWrite (15, 0);
  } 

  else if (x==1 && y== 0 && z==0 && s==1)
  {
digitalWrite (15, 1);    
print_9();
delay (dela);
 q_1=9;
 wait=2;
digitalWrite (15, 0);  
  } else if (x==0 && y== 1 && z==0 && s==1)
  {
digitalWrite (15, 1);
   print_0(); 
   delay (dela);
    q_1=0;
    wait=2;
digitalWrite (15, 0);
  }
  else {
digitalWrite (15, 1);
   print_nothing();
   wait=1;
digitalWrite (15, 0);    
  }

}

/********************************operation***************************/

if (w==2) {                    
  
 if (x==1 && y== 0 && z==1 && s==1)
  {
digitalWrite (15, 1);
    print_plus();
    delay (dela);
    opp = 0;
    wait=3;
digitalWrite (15, 0);
  } 
   
   else if (x==0 && y== 1 && z==1 && s==1)
  {
digitalWrite (15, 1);

    print_minus();
    delay (dela);
    opp = 1;
     wait=3;
digitalWrite (15, 0);
  } 
  
    else if (x==1 && y== 1 && z==1 && s==1)
  {
digitalWrite (15, 1);

    print_multiply();
    delay (dela);
    opp = 2;
     wait=3;
digitalWrite (15, 0);
  } 
    else if (x==0 && y== 0 && z== 0 && s== 0)
  {
digitalWrite (15, 1);

    print_divide();
    delay (dela);
    opp = 3;
     wait=3;
digitalWrite (15, 0);
  } 
  else {
digitalWrite (15, 1);
   print_nothing();
   wait=2;
digitalWrite (15, 0);    
  }
  
}

/***************************************second number************************************/

if (w==3) {                          
   
 if (x==1 && y== 0 && z==0 && s==0)
  {
digitalWrite (15, 1);
    print_1();
    delay (dela);
    q_2=1;
    wait=4;
digitalWrite (15, 0);
  } 
  else if (x==0 && y== 1 && z==0 && s==0)
  {
digitalWrite (15, 1);
   print_2();
   delay (dela);
    q_2=2;
    wait=4;
digitalWrite (15, 0);
  } 
  else if (x==1 && y== 1 && z==0 && s==0)
  {
digitalWrite (15, 1);
    print_3();
    delay (dela);
     q_2=3;
     wait=4;
digitalWrite (15, 0);    
  } 


  else if (x==0 && y== 0 && z==1 && s==0)
  {
digitalWrite (15, 1);
   print_4();
   delay (dela);
    q_2=4;
    wait=4;
digitalWrite (15, 0);
  } 


  else if (x==1 && y== 0 && z==1 && s==0)
  {
digitalWrite (15, 1);
    print_5();
    delay (dela);
     q_2=5;
     wait=4;
digitalWrite (15, 0);    
  } 


  else if (x==0 && y== 1 && z==1 && s==0)
  {
digitalWrite (15, 1);
 print_6();  
 delay (dela);
  q_2=6;
  wait=4;
digitalWrite (15, 0);
  } 

  else if (x==1 && y== 1 && z==1 && s==0)
  {
digitalWrite (15, 1);
    print_7();
    delay (dela);
     q_2=7;
     wait=4;
digitalWrite (15, 0);    
  } 


  else if (x==0 && y== 0 && z==0 && s==1)
  {
digitalWrite (15, 1);    
print_8();
delay (dela);
 q_2=8;
 wait=4;
digitalWrite (15, 0);
  } 

  else if (x==1 && y== 0 && z==0 && s==1)
  {
digitalWrite (15, 1);    
print_9();
delay (dela);
 q_2=9;
 wait=4;
digitalWrite (15, 0);  
  } else if (x==0 && y== 1 && z==0 && s==1)
  {
digitalWrite (15, 1);
   print_0(); 
   delay (dela);
    q_2=0;
    wait=4;
digitalWrite (15, 0);
  }
  else {
digitalWrite (15, 1);
   print_nothing();
   wait=3;
digitalWrite (15, 0);    
  }
  
  
}
  
/**************************Arithmetic***********************************************/  
  
  if (opp==0){
  
  result = q_1 + q_2;
  
  
  }
  
   else if (opp==1){
  
  result = q_1 - q_2;
  
  
  }
  
  else if (opp==2){
  
  result = q_1 * q_2;
  
  
  }
  
  else if (opp==3){
  
    if ( q_2 == 0) {
    
    result =20000;
    
    
    } else {
    
  result = q_1 / q_2;
  
    }
  
  }
  
/*********************Print Results****************************************/  

  
if (w==4){

  int r=0;
  
  if (result <0 && result> -1000) {  //handle negative
  
  digitalWrite (17, 1);
  
    print_minus();         //minus
    
    delay (5);
    
 digitalWrite (17, 0);
 
 int m = abs (result) ;
     
     r =  m / 100;         //-100s
  
  digitalWrite (16, 1);
  
    Print_r(r);
    
    delay (5);
    
 digitalWrite (16, 0);
 
   int n = m % 100;
   
   r = n /10;              //-10s
   
    digitalWrite (14, 1);
  
    Print_r(r);
    
    delay (5);
    
 digitalWrite (14, 0);
 
 r = n % 10;                //-1s
 
 digitalWrite (15, 1);
  
    Print_r(r);
    
    delay (5);
    
 digitalWrite (15, 0);

} 
  
  else if (result ==20000) {  //handle infinity 

   digitalWrite (14, 1);
    digitalWrite (15, 1);
     digitalWrite (16, 1);
    digitalWrite (17, 1);
  
    print_minus();
    
     digitalWrite (14, 0);
    digitalWrite (15, 0);
    digitalWrite (16, 0);
    digitalWrite (17, 0);
    
  }

 
  
if (result < 10000 && result >= 0){
  

   r = result / 1000;            //1000s
   
  digitalWrite (17, 1);
  
    Print_r(r);
    
    delay (5);
    
 digitalWrite (17, 0);
  
     int m = result %1000;
     
     r = m / 100;                //100s
  
  digitalWrite (16, 1);
  
    Print_r(r);
    
    delay (5);
    
 digitalWrite (16, 0);
 
   int n = m % 100;              //10s
   
   r = n /10;
   
    digitalWrite (14, 1);
  
    Print_r(r);
    
    delay (5);
    
 digitalWrite (14, 0);
 
 r = n % 10;                     //1s
 
 digitalWrite (15, 1);
  
    Print_r(r);
    
    delay (5);
    
 digitalWrite (15, 0);
 
 

}




if (x==0 && y== 0 && z==1 && s==1) { // # for carry on (for some reason, works only inside the condition)


wait=2;
q_1 = result;



}

}

if (x==1 && y== 1 && z==0 && s==1){ //* to terminate 


wait=1;


}





}
