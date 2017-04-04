/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

File myFile;

char ch;

void setup()
{
  
  char ch;
  
  char chr;
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  
  myFile = SD.open("test.txt", FILE_WRITE);

  /* 
  
  //write
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("Sup");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  } */

 /*
 //open file 
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  */
  
  
  
  /*  // delete the file:
  Serial.println("Removing test.txt...");
  SD.remove("test.txt");
  

  if (SD.exists("test.txt")) {
    Serial.println("test.txt exists.");
  }
  else {
    Serial.println("test.txt doesn't exist.");
  }

     */
  
  
  
  
  
}


void write_lines () {

//write
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  //myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.print(ch);
    // close the file:
    //myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }




}



void loop()
{
  // nothing happens after setup
  
  
  if (Serial.available())
  {
    ch = Serial.read();
    
    
    if (ch == '-'){
    
    myFile.println("");
    
    
    } 
    
    else if ( ch != '*' ) {
    
    write_lines ();
    
    ch = Serial.read();
    
    
    }
    
    
    
    
    else {
    
    
    myFile.close(); }
    
    
  }
  
  
  
  
  
  
  
  
  
}


