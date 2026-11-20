// Arduino Starter Kit - Project 02 (Spaceship Interface)
// Button released: red LEDs blink alternately.
// Button pressed: green LED turns on and red LEDs turn off.

const int switchPin = 2;
const int ledGreen = 3;
const int ledRedA = 4;
const int ledRedB = 5;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRedA, OUTPUT);
  pinMode(ledRedB, OUTPUT);
}

void loop() {
  int switchState = digitalRead(switchPin);

  if (switchState == LOW) {
    digitalWrite(ledGreen, LOW);

    digitalWrite(ledRedA, HIGH);
    digitalWrite(ledRedB, LOW);
    delay(250);

    digitalWrite(ledRedA, LOW);
    digitalWrite(ledRedB, HIGH);
    delay(250);
  } else {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRedA, LOW);
    digitalWrite(ledRedB, LOW);
  }
}
