#define buzzer 12
#define verde 4
#define rojo 7
#define mov 2
bool movimiento1;

void setup()
{
  pinMode(mov, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);
}

void loop()
{
  movimiento1 = digitalRead(mov);
  
  if(movimiento1 == HIGH){
    digitalWrite(verde, LOW);
    digitalWrite(rojo, HIGH);
    tone(buzzer, 1000);
    delay(100);
  } 
  if(movimiento1 == LOW){
    digitalWrite(rojo, LOW);
    noTone(buzzer);
    digitalWrite(verde, HIGH);
    delay(100);
  }
}
