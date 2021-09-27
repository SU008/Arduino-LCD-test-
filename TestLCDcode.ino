/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// include the library code:
#include <Keypad.h>
#include <LiquidCrystal.h>


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Keypad Setup
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
                         {'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'},
                         {'#','0','*'}

                     };
byte rowPins[ROWS] = {1, 4, 7, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 8, 9}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



void setup() {

 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
                                                       // Print a message to the LCD.
  lcd.print("hello, world!");

  Serial.begin(9600);
}

void loop(){
  cha key = keypad.getKey();

  //if (key != NO_KEY)
  {
    Serial.println(key);
  }
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
