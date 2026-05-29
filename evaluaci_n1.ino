#define azul 6
#define verde 5
#define sensorm 4
#define boton 2
#define sensorl A1
int sensorluz;
bool valorboton;
bool sensormov;
  
void setup()
{
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(sensorm, INPUT);
  pinMode(boton, INPUT);
  pinMode(sensorl, INPUT);
  Serial.begin(9800);
}

void loop()
{
  valorboton = digitalRead(boton);
  sensormov = digitalRead(sensorm);
  sensorluz = map(sensorl, 0, 1023, 0, 100);
  if(valorboton == LOW && sensorluz > 50)
  {
    if(sensormov == HIGH)
    {
      delay(300);
      analogWrite(azul, 150);
      analogWrite(verde, 90);
    } else
    {
      analogWrite(azul, 0);
      analogWrite(verde, 0);
    }
  }
  Serial.println(sensormov);
}