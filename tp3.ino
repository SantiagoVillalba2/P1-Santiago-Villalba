#define rojo 11
#define verde 6
#define azul 9
#define sensorluz A0
#define sensortemp A1
int a;
int r;
int v;
int sensort;
int sensorl;


void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(sensorluz, INPUT);
  pinMode(sensortemp, INPUT);
  Serial.begin(9800);
}

void loop()
{
  sensort = analogRead(sensortemp);
  sensorl = analogRead(sensorluz);
  sensort = map(sensort, 0, 1023, 0, 255);
  sensorl = map(sensorl, 0, 1023, 0, 100);
  prenderleds();
  Serial.println(sensorl);
}
void prenderleds(){
    if(sensorl >= 77 || sensorl <= 86){
    if(sensort > 71)
    {
      analogWrite(rojo, 255);
    } 
      else
      {
        analogWrite(rojo, 0);
      }
      
      if(sensort < 34)
      {
        analogWrite(azul, 255);
      }
      else
      {
        analogWrite(azul, 0);
      } 
      if(sensort >= 34 && sensort <= 71)
      {
        analogWrite(verde, 255);
      }
      else
      {
        analogWrite(verde, 0);
      }}
      else
      {
        
      }}
void apagartodo(){
 analogWrite(rojo, 0);
  analogWrite(verde, 0);
  analogWrite(azul, 0);}