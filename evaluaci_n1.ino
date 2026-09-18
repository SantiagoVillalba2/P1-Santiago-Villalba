#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>
#define rojo 8
#define azul 12
#define verde 13
#define serv A0
#define temp A1
#define pot A2
#define bot 2

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220

Adafruit_LiquidCrystal lcd1(0);

bool boton;
int potencio;
bool melodia = false;
Servo servo1;
int temperatura;


const int midi1[10][3] = {
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 115},
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

  


void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(boton, INPUT);
  lcd1.begin(16, 2);
  servo1.Write(0);
}

void loop()
{
  boton = digitalRead(bot);
  potencio = analogRead(pot);
  potencio = map(pot, 0, 1023, 0, 100);
  temperatura = analogRead(temp);
  temperatura = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);
  LeerTemp();
  moverservo()
  if(melodia == true){
    lcd1.setCursor(0,0);
    lcd1.print("Melodia");
    digitalWrite(verde, HIGH);
  } else{
   digitalWrite(verde, LOW); 
  }
  
}

void moverservo(){
 
  if(boton == LOW && potencio < 25)
  {
  lcd1.setCursor(0,0);
  lcd1.print("Servo Moviendose");
  for(int i = 0; i <= 10; i++){
   servo1.write(0);
   delay(2000);
   servo1.write(90);
    
   }
    playMidi(7, midi1, size_t len);
    melodia = true;
  }
  
  if(boton == LOW && potencio <= 50 && potencio >= 25){
    lcd1.setCursor(0,0);
    lcd1.print("Servo Moviendose"); 
    for(int i = 0; i <= 10; i++){
   servomot.write(0);
   delay(5000);
   servomot.write(90);
   }
  playMidi(7, midi1, size_t len);
  melodia = true;
  }
  
  if(boton == LOW && potencio > 50){
   lcd1.setCursor(0,0);
   lcd1.print("Servo Moviendose");
   for(int i = 0; i <= 10; i++){
   servo1.write(0);
   delay(8000);
   servo1.write(90);
   }
  playMidi(7, midi1, size_t len);
  melodia = true;
  }
}

void LeerTemp(){
 
  if(temperatura > 40){
   
    digitalWrite(rojo, HIGH);
  } else{
    digitalWrite(azul, HIGH);
  }
}
