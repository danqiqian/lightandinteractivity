/*
  Sine fade
  Takes a linear input from an analog sensor
  and produces a sinusoidal fade curve

  created 30 Jan 2019
  by Tom Igoe and lighting & interactivity 2019 class
*/

int intensity = 255;
int change = 4;
void setup() {
  Serial.begin(9600);
      pinMode(2, INPUT);
}

void loop() {
  if (intensity <= 0 || intensity >= 255) {
    change = -change;
  }

  intensity = intensity +  change;
  float result = sineFade1(intensity, 0, 255);
     if (digitalRead(6) == HIGH) {
   result = 0;
  }
  analogWrite(10, result);

  if (result == 189.31) {
    delay(500);
  } else {
    delay(5);
  }

  Serial.println(result);
}

float sineFade1(int inValue, int minValue, int maxValue) {
  float angle = map(inValue, minValue, maxValue, 0, 179);

  if (angle >= 60) {
    float result = (sin((angle * PI / 180) + PI / 2) + 1) * 172.5;
    return result;
  } else {
    float result = (sin((angle * PI / 180) + PI / 2) + 1) * 70;
    return result;
  }

}
