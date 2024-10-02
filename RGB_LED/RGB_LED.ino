#define RED 3
#define GREEN 10
#define BLUE 11
#define DOWN 8
#define UP 7
#define COLOR 4
#define RLED 2
#define GLED 12
#define BLED 13

int LED[3] = {RLED,GLED,BLED};
int RGB[3][2] = {{RED,255},{GREEN,0},{BLUE,0}};
int selectColor =0;
int before=LOW;
void setup(){
  Serial.begin(9600);
  for(int i=0; i<3; i++){
    pinMode(LED[i],OUTPUT);
    pinMode(RGB[i][0], OUTPUT);
  }
  pinMode(COLOR,INPUT);
  pinMode(DOWN,INPUT);
  pinMode(UP,INPUT);
  analogWrite(RED, 255);
}
void loop(){
  int now = digitalRead(COLOR);
  if( now == LOW && before==HIGH){
    selectColor++;
    if(selectColor>2) selectColor=0;
  }
  selectLED();
  if( digitalRead(UP)==HIGH){
    RGB[selectColor][1]++;
    if(RGB[selectColor][1]>255) RGB[selectColor][1]=0;
    analogWrite(RGB[selectColor][0], RGB[selectColor][1]);
  }
  if( digitalRead(DOWN)==HIGH){
    RGB[selectColor][1]--;
    if(RGB[selectColor][1]<0) RGB[selectColor][1]=255;
    analogWrite(RGB[selectColor][0], RGB[selectColor][1]);
  }

  String res = "r : "+String(RGB[0][1])+" g: "+String(RGB[1][1])+" b:"+String(RGB[2][1]);
  Serial.println(res);
  before=now;
}
void selectLED(){
  for(int i=0; i<3; i++){
    digitalWrite(LED[i],LOW);
  }
  digitalWrite(LED[selectColor],HIGH);
}


// // 버튼으로 색표현
// #define RED 11
// #define GREEN 10
// #define BLUE 9
// #define RBT 8
// #define GBT 7
// #define BBT 4

// int r=0, g=0, b=0;
// void setup(){
//   Serial.begin(9600);
//   pinMode(RED, OUTPUT);
//   pinMode(GREEN, OUTPUT);
//   pinMode(BLUE, OUTPUT);
//   pinMode(RBT, INPUT);
//   pinMode(GBT , INPUT);
//   pinMode(BBT, INPUT);
//   analogWrite( RED, 0);
//   analogWrite(GREEN, 0);
//   analogWrite(BLUE,0);
// }

// void loop(){
//   if( digitalRead(RBT)==HIGH){
//     r++;
//     if( r>255) r=0;
//   }
//   if( digitalRead(GBT) == HIGH){
//     g++;
//     if(g>255) g=0;
//   }
//   if( digitalRead(BBT) == HIGH){
//     b++;
//     if(b>255) b=0;
//   }
  
//   String res = "red : " +String(r)+" green : "+ String(g)+" blue : "+String(b);
//   Serial.println( res );

//   analogWrite(RED,r);
//   analogWrite(GREEN, g);
//   analogWrite(BLUE, b);

// }



// RGB LED 색 출력방법
// #define RED 11
// #define GREEN 10
// #define BLUE 9
// int r=0, g=0, b=0;
// void setup() {
//   pinMode(RED, OUTPUT);
//   pinMode(GREEN, OUTPUT);
//   pinMode(BLUE, OUTPUT);
// }
// void loop() {
//   r = random(0, 255);
//   g = random(0, 255);
//   b = random(0, 255);
//   analogWrite(RED, r);
//   analogWrite(GREEN, g);
//   analogWrite(BLUE, b);
//   delay(500);
// }


