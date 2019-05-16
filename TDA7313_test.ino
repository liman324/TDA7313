#include <Wire.h>
#include <TDA7313.h>
  TDA7313 tda;
  
void setup(){ 
  Serial.begin(9600);Wire.begin();
  audio();
}

void loop(){}

void audio(){
  tda.setVolume(55); // громкость 0...63
  tda.setAttLR(0);   // аттенюатор LR 0...31
  tda.setAttRR(0);   // аттенюатор RR 0...31
  tda.setAttLF(0);   // аттенюатор LF 0...31
  tda.setAttRF(0);   // аттенюатор RF 0...31
  tda.setSwitch(0,0,0); // вход 0...3, тонкомпенсация 1 вкл 0 выкл, усиление 0...3
  tda.setBass(0);    // тембр НЧ -7...+7
  tda.setTreble(0);  // тембр ВЧ -7...+7
}
