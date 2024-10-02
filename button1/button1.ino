#define LED 7
#define BUTTON 8

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if( digitalRead(BUTTON) == HIGH){ // 버튼을 눌렀을경우
    digitalWrite(LED, HIGH);
  }else{ // 버튼을 누르지 않은경우
    digitalWrite(LED, LOW);
  }

}
