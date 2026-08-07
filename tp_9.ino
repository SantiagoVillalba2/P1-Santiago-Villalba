
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define boton1 7
#define boton2 4
#define boton3 2
#define A4 440
#define Fb4 370
#define A3 220
#define G3 196
#define Gb2 104
#define C3 131
#define E5 659

#define F5 698
#define B4 494
#define C6 1047
#define B6 1976
#define F4 349
#define G5 784
#define Ab5 932
#define Gb4 415
#define A6 1760
#define F6 1397

#define E4 330
#define G6 1568
#define D5 587
#define Cb5 554
#define D4 294
#define D6 1175

bool valorboton1;
bool valorboton2;
bool valorboton3;

const int midi1[11][3] = {
 {A4, 167, 500},
 {Fb4, 167, 500},
 {A3, 167, 0},
 {G3, 167, 333},
 {Gb2, 167, 1000},
 {C3, 167, 333},
 {E5, 167, 0},
};

const int midi2[10][3] = {
 {F5, 167, 500},
 {B4, 167, 333},
 {C6, 167, 167},
 {B6, 167, 1333},
 {F4, 167, 500},
 {G5, 167, 167},
 {Ab5, 167, 0},
 {Gb4, 167, 167},
 {A6, 167, 3000},
 {F6, 167, 0},
};

const int midi3[10][3] = {
 {E4, 167, 333},
 {G6, 167, 667},
 {D5, 167, 1833},
 {Cb5, 167, 1833},
 {D4, 167, 500},
 {D6, 167, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

void setup() {
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  Serial.begin(9800);
}

void loop() {
  valorboton1 = digitalRead(boton1);
  valorboton2 = digitalRead(boton2);
  valorboton3 = digitalRead(boton3);
  
  if(valorboton1 == LOW){
     delay(2000);
     playMidi(8, midi1, ARRAY_LEN(midi1));
  }
  
  if(valorboton2 == LOW){
    delay(2000);
    playMidi(8, midi2, ARRAY_LEN(midi2));
  }
   if(valorboton3 == LOW){
     delay(2000);
     playMidi(8, midi3, ARRAY_LEN(midi3));
   }
  
 Serial.println(valorboton1);
}
