#define LED1 2
#define LED2 4
#define LED3 7
#define LED4 8
#define LED5 12
#define LED6 13

int crosswalk[3][2]{ {LED1, LED2}, {LED3,LED4}, {LED5,LED6}};

void setup() {
  for(int i=0; i<3; i++){
    for(int k=0; k<2; k++){
      pinMode(crosswalk[i][k], OUTPUT);
    }
  }
}

void loop() {
}

void on( int *walk , int time){
  for(int i=0; i<3; i++){
    digitalWrite(crosswalk[i][0], HIGH);
    digitalWrite(crosswalk[i][1] , LOW);
  }

  digitalWrite(walk[0], LOW);
  digitalWrite(walk[1] , HIGH);

  // 5초남을때 깜빡깜빡
  int waitTime = time-5000;
  delay(waitTime);
  for(int i=1; i<=50; i++){
    digitalWrite(walk[1], LOW);
    delay(100);
    digitalWrite(walk[1],HIGH);
    delay(100);
  }
}






