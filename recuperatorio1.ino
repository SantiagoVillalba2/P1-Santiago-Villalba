#define sensort 3
#define rojo 13
#define amarillo 8
#define verde 12
#define sensorluz A1
#define pot A0
#define sensormov 4

int sensorl;
int sensortemp;
int potencio;
int temperatura;
bool sensorm;


void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(sensorluz, INPUT);
  pinMode(sensort, INPUT);
  pinMode(sensormov, INPUT);
  pinMode(pot, INPUT);
  Serial.begin(9800);
}

void loop()
{
  sensorl = analogRead(sensorluz);
  sensortemp = analogRead(sensort);
  temperatura = map(((sensortemp - 20) * 3.04), 0, 1023, -40, 125);
  potencio = analogRead(pot);
  sensorm = digitalRead(sensormov);
  potencio = map(potencio, 0, 1023, 0, 100);
  sensorl = map(sensorl, 0, 1023, 100, 0);
  ledorden();
}


void ledorden()
{
  if(potencio >= 50 && potencio <= 75 && temperatura < 15){
    if(sensormov == HIGH){
      digitalWrite(rojo, HIGH);
      delay(1000);
      digitalWrite(verde, HIGH);
      delay(1000);
      digitalWrite(amarillo, HIGH);
    } else{
      digitalWrite(rojo, LOW);
      digitalWrite(verde, LOW);
      digitalWrite(amarillo, LOW);
    }
  }
  if(sensorl == 29){
    
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    digitalWrite(amarillo, HIGH);
  } else{
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, LOW);
  }
}