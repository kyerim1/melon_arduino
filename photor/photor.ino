#define PHOTO A5
#define LED 8

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int val = analogRead(PHOTO);
  Serial.println(val);
  delay(1000);
  if(val>1000){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
