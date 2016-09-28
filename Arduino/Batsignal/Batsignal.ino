/***********************************
 * 
 * Custom Batman Logo programmed on Arduino Uno. 
 * It creates custom characters using 8 byte arrays 
 * to display the design on the 20x4 LCD screen.
 * 
 * @krohak
 *********************************/
 #include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



byte wing_right_up [8] = {

        B00000,
        B00000,
        B00000,
        B11000,
        B01100,
        B01110,
        B11110,
        B11111  
         
     
};   


byte head_right_up [8] = {

        B00000,
        B00000,
        B01000,
        B01100,
        B01110,
        B11110,
        B11110,
        B11111   
     
}; 


byte head_left_up [8] = {

        B00000,
        B00000,
        B00010,
        B00110,
        B01110,
        B01111,
        B01111,
        B11111
     
};

byte wing_left_up [8] = {

        B00000,
        B00000,
        B00000,
        B00011,
        B00110,
        B01110,
        B01111,
        B11111 
         
     
}; 





byte wing_right_down [8] = {

        B11111,
        B11111,
        B01111,
        B00110,
        B00110,
        B00100,
        B00000,
        B00000
         
     
};

byte wing_left_down [8] = {

        B11111,
        B11111,
        B11110,
        B01100,
        B01100,
        B00100,
        B00000,
        B00000
         
     
};




byte tail_right_down [8] = {

        B11111,
        B11111,
        B11001,
        B11000,
        B10000,
        B10000,
        B10000,
        B00000
         
     
};


byte tail_left_down [8] = {

        B11111,
        B11111,
        B10011,
        B00011,
        B00001,
        B00001,
        B00001,
        B00000   
         
     
};




void setup() {

  lcd.begin(20, 4);
  
   
lcd.createChar(1, wing_left_up);
lcd.createChar(2, head_left_up);
lcd.createChar(3, head_right_up);
lcd.createChar(4, wing_right_up);
lcd.createChar(5, wing_left_down);
lcd.createChar(6, tail_left_down);
lcd.createChar(7, tail_right_down);
lcd.createChar(8, wing_right_down);

lcd.clear ();




}

void loop (){

 
lcd.setCursor (8,0);  



lcd.write(1); 
lcd.write(2); 
lcd.write(3); 

lcd.write(4); 

lcd.setCursor (8,1); 
lcd.write(5); 
lcd.write(6);
lcd.write(7);
lcd.write(8); 


delay(500);

lcd.clear();

delay(500); 


}

