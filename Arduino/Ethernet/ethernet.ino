/*--------------------------------------------------------------
  Program:      webserver_3_LED

  Description:  Arduino web server that serves up a web page
                allowing the user to control three LEDs

  Ethernet shield attached to pins 10, 11, 12, 13

Circuit:
------------------------------------------------------

 pin 2 ----- LED long leg/LED short leg ----- GND
 pin 3 ----- LED long leg/LED short leg ----- GND
 pin 4 ----- LED long leg/LED short leg ----- GND
 etc
------------------------------------------------------
*/

#include <SPI.h>
#include <Ethernet.h>

//CHANGE THIS MAC ADDRESS
byte mac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x05 }; // MAC address

// ADD MORE LEDs HERE
// 0 and 1 are used for Tx/Rx chat with the computer
// so start at 2...
const byte LED_pins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,}; // Arduino pins used as outputs for LEDs
byte prev_led_num = 42;

byte LED[sizeof(LED_pins)] = {0}; // the state of each LED
byte XED[sizeof(LED_pins)] = {0}; // new state of each LED
EthernetServer server(80);
char char_in = 0; // used to store a character from the Ethernet port
String HTTP_req; // stores the received HTTP request

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Ethernet.begin(mac);
  server.begin();
  Serial.print("Arduino webserver can be found at ");
  Serial.println(Ethernet.localIP());

  // set up the LED pins as outputs
 for (byte index = 0; index < sizeof(LED_pins); index++) {
    pinMode(LED_pins[index], OUTPUT);
  }


}


void loop()
{

digitalWrite (14, 1);

  EthernetClient client = server.available();

  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char_in = client.read();  // get a single character from the Ethernet port
        HTTP_req += char_in;      // build a string out of the received characters

        Serial.println(HTTP_req);


        // answer first HTTP request immediately
        if (char_in == '\n') {
          // respond to HTTP request
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html><head>");
          client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
          client.println("<style> div{margin:20px; border: 2px solid black; padding:20px;}input{font-size:1.2em;}</style>");
          client.println("</head><body>");

          //
          //CheckLEDs();              // get state of LED checkboxes from web page
          UpdateLEDs();
          DisplayLEDs(&client);     // display checkboxes on web & write to LEDs
          //

          client.println("</body></html>");
          HTTP_req = "";      // delete string contents
          client.stop();
        } // end if (char_in == '\n')
      } // end if (client.available()
    } // end while (client.connected())
  } // end if (client)
}

// get the state of the LED checkboxes from the HTTP request
void CheckLEDs()
{
  for (byte led_num = 0; led_num < sizeof(LED_pins); led_num++) {
    if ((HTTP_req.charAt(9) == (LED_pins[led_num] + '0')) &&
        (HTTP_req.charAt(17) == (LED_pins[led_num] + '0'))) {  // LED box is checked
      XED[led_num] = 1;

  if (XED[led_num] != LED[led_num]) {

for (int x = 0; x < sizeof(LED_pins); x++) {

  if ( x != led_num) {

    XED[x] = 0;

    } else {}


  }



        }
           else {}

      LED[led_num] = XED[led_num];


    //  Serial.println(String(LED_pins[led_num]) + " is ON");
    }
    else if (HTTP_req.charAt(9) == (LED_pins[led_num] + '0')) {        // LED box is unchecked
      XED[led_num] = 0;

      LED[led_num] = XED[led_num];

    //  Serial.println(String(LED_pins[led_num]) + " is OFF");
    }
  }
}

// write the HTML that includes the state of the LED checkboxes for displaying on the web browser



void UpdateLEDs() {

  for (byte led_num = 0; led_num < sizeof(LED_pins); led_num++) {
    if ((HTTP_req.charAt(9) == (LED_pins[led_num] + '0')) &&
        (HTTP_req.charAt(16) == (LED_pins[led_num] + '0'))) {  // LED box is checked

      XED[led_num] = 1;

     if (XED[led_num] != LED[led_num]) {

for (int x = 0; x < sizeof(LED_pins); x++) {

  if ( x != led_num) {

    XED[x] = 0;

    } else {}


  }



        } else {}

      LED[led_num] = XED[led_num];



      Serial.println(String(LED_pins[led_num]) + " is ON");
    }
    else if (HTTP_req.charAt(9) == (LED_pins[led_num] + '0')) {        // LED box is unchecked
      XED[led_num] = 0;



  if (XED[led_num] != LED[led_num]) {

for (int x = 0; x < sizeof(LED_pins); x++) {

  if ( x != led_num) {

    XED[x] = 0;

    } else {}


  }



        } else {}


      LED[led_num] = XED[led_num];

      Serial.println(String(LED_pins[led_num]) + " is OFF");
    }
  }


  }



void DisplayLEDs(Client *client)
{
  // some CSS in the HTML to change colours and position of the box containing the LED checkboxes
  client->print("<div>");
  client->print("<h1>LED Outputs</h1>");
  // send each LED checkbox in turn
  for (byte led_num = 0; led_num < sizeof(LED_pins); led_num++) {
    // use hidden checkbox so that unchecking a checkbox sends a value to the Arduino
    // if only a normal checkbox is used, nothing is sent when it is unchecked
    // both hidden and normal checkboxes are produced here for each LED
    client->print("<form> <input type='hidden' name='LED");
    client->print(LED_pins[led_num], DEC);
    client->print("' value='0'> <input type='checkbox' name='LED");
    client->print(LED_pins[led_num], DEC);
    client->print("' value='");
    client->print(LED_pins[led_num], DEC);
    client->print("'");
    // write to the LED connected to the Arduino board
    if (LED[led_num]) {
      client->print(" checked ");             // part of HTML if checkbox is to be displayed checked

      //
      //digitalWrite(LED_pins[led_num], HIGH);  // switch LED on

      //print_1 ();

      printt (led_num);

      delay (1000);
      //


    }
    else {

      //
      //digitalWrite(LED_pins[led_num], LOW);  // switch LED off
      //print_nothing ();
      //delay (1000);
      //

    }
    client->print(" onclick='submit(); '>L ");
    client->print(LED_pins[led_num], DEC);
    client->print(" </form>");                 // end of HTML for 1 LED's form
  }
  client->print("</div>");                       // end of box containing LEDs
}
