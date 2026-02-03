const int buttonPin = 2;    // Button on pin 2 (INT0)
const int ledInterrupt = 12; // LED toggled by interrupt
const int ledLoop = 9;      // LED blinked in main loop

volatile bool ledState = LOW;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up
  pinMode(ledInterrupt, OUTPUT);
  pinMode(ledLoop, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, FALLING);
  Serial.begin(9600);
}

void loop() {
  // Blink LED in main loop using millis()
  static unsigned long prevMillis = 0;
  unsigned long currentMillis = millis();
  if (currentMillis - prevMillis >= 500) {
    prevMillis = currentMillis;
    digitalWrite(ledLoop, !digitalRead(ledLoop));
  }
}

void toggleLED() {
  ledState = !ledState;
  digitalWrite(ledInterrupt, ledState);
}
