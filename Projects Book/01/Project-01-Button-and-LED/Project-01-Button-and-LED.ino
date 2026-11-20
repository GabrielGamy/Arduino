// Arduino Starter Kit - Project 01 (Button and LED)
// Press the button to make the LED blink.

const int buttonPin = 2;
const int ledPin = 3;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
