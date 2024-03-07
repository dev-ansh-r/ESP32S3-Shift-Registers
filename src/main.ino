/*
 * Copyright (c) 2024 Devansh Shukla R
 *
 * This code is licensed under the Apache license.
 * See LICENSE file for more details.
 * 
 * /

const int dataPin = 20; /* Q7 */
const int clockPin = 21; /* CP */
const int latchPin = 47; /* PL */

const int numBits = 8; /* Set to 8 * number of shift registers */

int previousValue = 0; // Stores the previously read value 

bool buttonPressed = false;
unsigned long lastDebounceTime = 0; //Stores timestamp of last button change

void setup() {
  Serial.begin(115200);
  pinMode(dataPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  // Step 1: Sample
  digitalWrite(latchPin, LOW);
  digitalWrite(latchPin, HIGH);

  // Step 2: Shift and compare
  int newValue = 0;
  for (int i = 0; i < numBits; i++) {
    int bit = digitalRead(dataPin);
    newValue |= (bit << i); // Shift and combine bits into a single value
    digitalWrite(clockPin, HIGH); // Shift out the next bit
    digitalWrite(clockPin, LOW);
  }

  // Print only if the value has changed
  if (newValue != previousValue) {
    Serial.print("Bits: ");
    for (int i = 0; i < numBits; i++) {
      if (newValue & (1 << i)) {
        Serial.print("1");
      } else {
        Serial.print("0");
      }
    }
    Serial.println();
    previousValue = newValue; // Update the previously read value
  }
  delay(1000);
}
