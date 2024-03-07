/*
 * Copyright (c) 2024 Devansh Shukla R
 *
 * This code is licensed under the Apache license.
 * See LICENSE file for more details.
 * 
 *  **Software Debounce:**
 *
 * This code implements a software debounce algorithm to address a common
 * issue with physical buttons called "button bounce." When a button is
 * pressed, its contacts may bounce several times before settling into a
 * stable state. This can cause the code to misread the button state
 * as multiple presses or misses the press altogether.
 *
 * The debounce algorithm filters out these rapid transitions by only
 * registering a button press when the button state remains stable (pressed
 * or released) for a specific time (debounce time). This ensures reliable
 * button press detection.
 */

const int dataPin = 20; /* Q7 */
const int clockPin = 21; /* CP */
const int latchPin = 47; /* PL */

const int numBits = 8; /* Set to 8 * number of shift registers */

int previousValue = 0; // Stores the previously read value

void setup() {
  Serial.begin(115200);
  pinMode(dataPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

bool buttonPressed = false;
unsigned long lastDebounceTime = 0; // Stores timestamp of last button change

void loop() {
  // Debounce logic for button press
  int bit = digitalRead(dataPin);
  if (bit != buttonPressed) {
    if (millis() - lastDebounceTime > 50) { // Debounce time in milliseconds (adjust as needed)
      buttonPressed = bit;
    }
    lastDebounceTime = millis();
  }

  // Sample data from shift register
  digitalWrite(latchPin, LOW);
  digitalWrite(latchPin, HIGH);

  // Shift and combine bits into a single value
  int newValue = 0;
  for (int i = 0; i < numBits; i++) {
    bit = digitalRead(dataPin);
    newValue |= (bit << i);
    digitalWrite(clockPin, HIGH);
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
