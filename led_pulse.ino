/*
  Sine fade
  Takes a linear input from an analog sensor
  and produces a sinusoidal fade curve

  created 30 Jan 2019
  by Tom Igoe and lighting & interactivity 2019 class
*/

int intensity = 255;
int change = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // decrease or increase by 1 point each time
  // if at the bottom or top, change the direction:



  if (intensity <= 0 ) {
    change = -change / 3;
  }

  if ( intensity >= 255) {
    change = -change * 3;
  }


  intensity = intensity + change;

  // get the sine of the intensity so you're not doing a linear fade:
  float result = sineFade(intensity, 0, 255);
  if (digitalRead(6) == HIGH) {
    result = 0;
  }
  
  analogWrite(10, result);
  delay(5);
  Serial.println(result);
}

float sineFade(int inValue, int minValue, int maxValue) {
  // map input to a 0-179 range:
  float angle = map(inValue, minValue, maxValue, 0, 179);
  float result = (sin((angle * PI / 180) + PI / 2) + 1) * 127.5;
  return result;
}
