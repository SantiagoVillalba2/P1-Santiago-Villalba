// C++ code
//
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  analogWrite(11, 255);
  delay(500);
  analogWrite(11,0);
  delay(100);
  for(int x = 1; x<=5;x++)
  {
  analogWrite(11, 255);
  analogWrite(6,165);
  digitalWrite(13, HIGH);
  analogWrite(5, 255);
  analogWrite(9, 30);
  delay(100);
  analogWrite(11, 0);
  analogWrite(6,0);
  digitalWrite(13, LOW);
  analogWrite(5, 0);
  analogWrite(9, 0);
  delay(100);
  }
  
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(100);
  for(int x = 1; x<=5;x++)
  {
  analogWrite(11, 255);
  analogWrite(6,165);
  digitalWrite(13, HIGH);
  analogWrite(5, 255);
  analogWrite(9, 30);
  delay(100);
  analogWrite(11, 0);
  analogWrite(6,0);
  digitalWrite(13, LOW);
  analogWrite(5, 0);
  analogWrite(9, 0);
  delay(100);
  }
  analogWrite(10, 10);
  analogWrite(9, 10);
  delay(500);
  analogWrite(10, 0);
  analogWrite(9, 0);
  delay(100);
  for(int x = 1; x<=5;x++)
  {
  analogWrite(11, 255);
  analogWrite(6,165);
  digitalWrite(13, HIGH);
  analogWrite(5, 255);
  analogWrite(9, 30);
  delay(100);
  analogWrite(11, 0);
  analogWrite(6,0);
  digitalWrite(13, LOW);
  analogWrite(5, 0);
  analogWrite(9, 0);
  delay(100);
  }
}
  