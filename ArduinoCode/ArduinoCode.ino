//define pins 
int red = 2;
int yellow = 3;
int green = 4;

const int B_1 = 8;
const int B_2 = 9;
const int A_2 = 10;
const int A_1 = 11;
const int buzzer = 12;


int on = LOW;
int off = HIGH;

void setup () {
  //buzzer
  pinMode (buzzer, OUTPUT);
  //LED
  pinMode (red,OUTPUT);
  pinMode (yellow,OUTPUT);
  pinMode (green,OUTPUT);
  //motor
  pinMode (B_1, OUTPUT) ;
  pinMode (B_2, OUTPUT) ;
  pinMode (A_1, OUTPUT) ;
  pinMode (A_2, OUTPUT) ;  
  Serial.begin (9600);}
 
void loop() {
  // read the input on analog pin 0:
  int value = analogRead(A0);

  //dangerous driving conditions - auto-pilot is automatically disabled 
  if (value > 500) {
    //"Very heavy Rain"
    Serial.println("VERY HEAVY Rain! Auto-pilot de-activated - please take over the wheel!"); 
    digitalWrite (red,on);
    digitalWrite(yellow,off);
    digitalWrite(green,off);
    //auto-pilot off
    digitalWrite(B_1,off);
    digitalWrite(B_2,off);
    digitalWrite(A_1,off);
    digitalWrite(A_2,off);
    //buzzer on
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);
    }
  //auto-pilot gives warning as driving conditions may be dangerous
  else if ((value > 300) && (value <= 500)) {
    //"AVERAGE Rain"
    Serial.println("AVERAGE Rain! Reduced speed - WET mode activated!"); 
    digitalWrite (green,off);
    digitalWrite (yellow,on);
    digitalWrite (red,off);
    //auto-pilot still on
    digitalWrite(B_1,on);
    digitalWrite(B_2,off);
    digitalWrite(A_1,on);
    digitalWrite(A_2,off);
    }
  //normal driving conditions
  else {
    //"Dry Weather"
    Serial.println("Great weather today!"); 
    digitalWrite (green,on);
    digitalWrite (yellow,off);
    digitalWrite (red,off);
    delay(100);
    //auto-pilot on
    digitalWrite(B_1,on);
    digitalWrite(B_2,off);
    digitalWrite(A_1,on);
    digitalWrite(A_2,off);

  }
  }
