/*
  Sine fade
  Takes a linear input from an analog sensor
  and produces a sinusoidal fade curve

  created 30 Jan 2019
  by Tom Igoe and lighting & interactivity 2019 class
*/

int intensity = 255;
int change = 17;
void setup() {
    pinMode(6, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (intensity <= 0 || intensity >= 255) {
    change = -change;
  }

  intensity = intensity +  change;


  float result = sineFade(intensity, 0, 255);
  if (digitalRead(6) == HIGH) {
    result = 0;
  }

  analogWrite(10, result);
  delay(5);
  Serial.println(result);
}

float sineFade(int inValue, int minValue, int maxValue) {
  float angle = map(inValue, minValue, maxValue, 0, 179);
  float result = (sin((angle * PI / 180) + PI / 2) + 1) * 127.5;
  return result;
}
