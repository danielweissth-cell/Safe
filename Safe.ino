#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 11 , 10 , 9 , 8 };
byte colPins[COLS] = { 4 , 5 , 6 , 7 };

Keypad kp = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String input = "";
const String correctPIN = "2482";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Введите PIN8 (# - для подтверждения, * - для сброса)");
}

void loop() {
  // put your main code here, to run repeatedly:
  char but = kp.getKey();
  if (!but) return;
  if (but == '#') {
    if (input == correctPIN) {
      Serial.println();
      Serial.println("Access available!");
    } else {
      Serial.println();
      Serial.println("Access not available! Try again!");
    }
     input = "";
  } else if (but == '*') {
    input = "";
    Serial.println();
    Serial.println("RELOAD...");
  } else {
    input += but;
    Serial.print("*");
  }
  delay(50);
}