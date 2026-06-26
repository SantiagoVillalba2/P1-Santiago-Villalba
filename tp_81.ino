#define rojo 6
#define azul 5
#define verde 3
#define pot A0
int valorpot;
int valores[3] = {5, 6, 8};
int factor = 5;
void setup()
{
 pinMode(rojo, OUTPUT);
 pinMode(azul, OUTPUT);
 pinMode(verde, OUTPUT);
 Serial.begin(9800);
}

void loop()
{
 valorpot = analogRead(pot);
 valorpot = map(valorpot, 0, 1023, 0, 101);
  Serial.print("porcentaje potenciometro: ");
  Serial.println(valorpot);
  if(valorpot >= 0 && valorpot < 20)
 {
   int valores[3] = {5, 6, 8};
   int factor = 5;
   int mult[3];
   for(int i = 0; i < 3; i++)
{
   mult[i] = valores[i] * factor;
     if(mult[i] > 255){
       mult[i] = 255;}
}
    for(int i = 0; i< 3; i++){
      int valor = mult[i];
      analogWrite(rojo, valor);
      analogWrite(azul, valor);
      analogWrite(verde, valor);
      delay(1000);
    }
  } else if(valorpot >= 20 && valorpot < 40){
    float notas[10] = {8,8,9,5,2,9,9,2,1,1};
    float suma = 0;
    for(int i = 0; i< 10; i++){
      suma += notas[i];
    }
    float promedio = suma / 10.0;
    Serial.print("Suma: ");
    Serial.println(suma);
    Serial.print("Promedio: ");
    Serial.println(promedio);
    
    if(promedio >= 1.0 && promedio <= 5.0){
      analogWrite(rojo, 255);
    } else if(promedio > 5.0 && promedio <= 8.0){
      analogWrite(verde, 255);
    } else if(promedio > 8.0 && promedio <= 10.0){
      analogWrite(azul, 255);
      analogWrite(verde, 255);
    }
  }
}