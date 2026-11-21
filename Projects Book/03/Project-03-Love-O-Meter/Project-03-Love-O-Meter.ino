// Arduino Starter Kit - Project 03 (Love-O-Meter)
// Read temperature from TMP36 and light more LEDs as temperature rises.

const int sensorPin = A0;
const float baselineTemp = 20.0;
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // Convert the ADC reading to voltage.
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // Convert voltage to temperature in degrees C (TMP36).
  float temperature = (voltage - 0.5) * 100.0;
  Serial.print(", Degrees C: ");
  Serial.println(temperature);

  // Below baseline + 2C (under 22C): all LEDs off.
  if (temperature < baselineTemp + 2) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  // baseline + 2C to below baseline + 4C (22C to <24C): first LED on.
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  // baseline + 4C to below baseline + 6C (24C to <26C): first two LEDs on.
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
  // baseline + 6C and above (26C+): all LEDs on.
  } else {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }

  delay(1);
}
