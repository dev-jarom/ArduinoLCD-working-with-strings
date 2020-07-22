// compiled using Platform IO
#include <Arduino.h> // remove this line if using ARDUINO IDE

/********************************************************
*********  Using Strings in Arduino LCD I2C *************
*********************************************************/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define BACKLIGHT_PIN     13

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE);  // Set the LCD I2C address
//LiquidCrystal_I2C lcd(0x38, BACKLIGHT_PIN, POSITIVE);  // Set the LCD I2C address

String msg1 = "Hello"; // String variables
String msg2 = "World";
String msg3 = "CoET";
String msg4 = "Kami";
void setup()
{
  // Switch on the backlight
  pinMode ( BACKLIGHT_PIN, OUTPUT );
  digitalWrite ( BACKLIGHT_PIN, HIGH );
  lcd.begin(16,2);               // initialize the lcd 

   lcd.home ();                   // go home
   lcd.print("Test print Using ");  
   lcd.setCursor ( 0, 1 );        // go to the next line
   lcd.print ("String variable");
   delay(1000);
}

void showDisplay(int duration, String message, String message2) { // creation of a subroutine with parameters
   lcd.clear();
   lcd.home ();
   lcd.print(message);
   lcd.setCursor ( 0, 1 );        // go to the next line
   lcd.print(message2);
   delay(duration);
}


void loop()
{
   showDisplay(2000, msg1, msg2); // calling of a subroutine
   showDisplay(2000, msg3, msg4);

}

