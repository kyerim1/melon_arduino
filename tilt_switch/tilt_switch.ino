#define TILT 7


void setup() {
  Serial.begin(9600);
  pinMode(TILT, INPUT_PULLUP);

}

void loop() {
  int value = digitalRead(TILT);
  Serial.println(value);
  delay(500);

}
