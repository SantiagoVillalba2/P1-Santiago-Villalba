#define rojo 6
#define azul 5
#define verde 3
void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(azuñ, OUTPUT);
  pinMode(verde, OUTPUT);
  Serial.begin(9800);
}
  

void loop()
{

  for (int i = 1; i <= 255; i++){
     analogWrite(rojo,i);
     for(int o = 1; o <= 255; o++){
      analogWrite(azul,o);
      for(int j = 1; j <= 255; j++){
      analogWrite(verde,j);
      }
    }
  }
}