#define rojo 11
#define azul 10
#define verde 6
#define pr A0
#define pv A1
#define pa A2
#define boton 2
int valorrojo;
int valorverde;
int valorazul;
int valorboton;
void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9800);
}

void loop()
{ valorboton = digitalRead(boton);
  delay(100);
  if(valorboton == LOW){
    Serial.println("tenes 10 segundos para configurar los colores");
    delay(10000);
    valorrojo = analogRead(pr);
    valorverde = analogRead(pv);
    valorazul = analogRead(pa);
    valorrojo = map(valorrojo, 0, 1023, 0, 255);
    valorverde = map(valorverde, 0, 1023, 0, 255);
    valorazul = map(valorazul, 0, 1023, 0, 255);
    Serial.print("tu configuracion del led: ");
    Serial.println("");
    Serial.println(valorrojo);
    Serial.println(valorverde);
    Serial.println(valorazul);
    
    PrendeyApaga();
   }
  }
void PrendeyApaga(){
  analogWrite(rojo, valorrojo);
  analogWrite(verde, valorverde);
  analogWrite(azul, valorazul);
  delay(10000);
  analogWrite(rojo, 0);
  analogWrite(verde, 0);
  analogWrite(azul, 0);
}
    