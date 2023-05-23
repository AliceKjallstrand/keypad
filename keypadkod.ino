#include <Keyboard.h>   
#include <OneButton.h>   
#define KEYBOARD_h



OneButton button1(
  9,          // Pin Nummer  (funnktion: mute)
  true,       // Input is active LOW
  true        // Enable internal pull-up resistor
);
OneButton button2(
  6,         // Pin Nummmer  (funktion: deafen)
  true,       // Input is active LOW
  true        // Enable internal pull-up resistor
);
OneButton button3(
  3,          // Pin Nummer  (funktion: stream toggle)
  true,       // Input is active LOW
  true        // Enable internal pull-up resistor
);


void setup() {
  button1.attachClick(button1click); 
  button2.attachClick(button2click); 
  button3.attachClick(button3click); 

  Keyboard.begin(); 
  Serial.begin(9600); 
}



void loop() {
  button1.tick();
  button2.tick();
  button3.tick();
} 




// funktionerna sätts igång när de olika knapparna blir nedtryckta i mer än 50ms och mindre är 300ms
void button1click() {
  Serial.println("Pressing alt+a for Mute/Unmute");
  Keyboard.press(KEY_LEFT_ALT);
  delay(20);
  Keyboard.press('a');
  delay(10);
  Keyboard.release('a');
  delay(20);
  Keyboard.releaseAll();
}



void button2click() {
  Serial.println("Pressing alt+y for Hand");
  Keyboard.press(KEY_LEFT_ALT);
  delay(20);
  Keyboard.press('y');
  delay(10);
  Keyboard.release('y');
  delay(20);
  Keyboard.releaseAll();
}


void button3click() {
  Serial.println("Pressing alt+v for Video");
  Keyboard.press(KEY_LEFT_ALT);
  delay(20);
  Keyboard.press('v');
  delay(10);
  Keyboard.release('v');
  delay(20);
  Keyboard.releaseAll();
}