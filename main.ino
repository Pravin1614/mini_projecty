#include <Arduino.h>

String readString;
int baz = 5;

void setup() {
  Serial.begin(9600);
  pinMode(baz, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    delay(50);
    char c = Serial.read();
    readString += c;
  }
  
  if (readString.length() > 0) {
    Serial.println(readString);
    if (readString == "R") {
      digitalWrite(baz, HIGH);
    }
    readString = "";
  }
}
