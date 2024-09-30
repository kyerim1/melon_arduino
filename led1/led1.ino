#define LED1 2
#define LED2 4
#define LED3 7
#define LED4 8

int led[4]={LED1,LED2,LED3,LED4};

void setup() {
  for( int i=0; i<4; i++){
    pinMode(led[i], OUTPUT);
  }
  
}

void loop() {
   for(int i=0; i<4; i++){
    digitalWrite(led[i], HIGH);
    for(int k=0; k<4; k++){
      if(k!=i)
      digitalWrite(led[k],LOW);
    }
    delay(1000);
  }
}


//void setup() {
//  pinMode(8, OUTPUT);
//
//}

//void loop() {
//  digitalWrite(8 , HIGH);
//  delay(1000);
//  digitalWrite(8, LOW);
//  delay(1000);

//}
