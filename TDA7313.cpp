#include <Arduino.h>
#include <Wire.h>
#include "TDA7313.h"

TDA7313::TDA7313(){
	Wire.begin();
}

void TDA7313::setVolume(int vol){
  vol = 63 - vol;
  writeWire(vol);
}

void TDA7313::setAttLF(int att_lf){
  att_lf = 0b10000000 + att_lf;
  writeWire(att_lf);
}

void TDA7313::setAttRF(int att_rf){
  att_rf = 0b10100000 + att_rf;
  writeWire(att_rf);
}

void TDA7313::setAttLR(int att_lr){
  att_lr = 0b11000000 + att_lr;
  writeWire(att_lr);
}

void TDA7313::setAttRR(int att_rr){
  att_rr = 0b11100000 + att_rr;
  writeWire(att_rr);
}

void TDA7313::setSwitch(int input, int loud, int usil){
  switch (input){
    case 0:input = 0b01000000;break;
    case 1:input = 0b01000001;break;
    case 2:input = 0b01000010;break;
    case 3:input = 0b01000011;break; 
  }
  switch (loud){
    case 1:loud = 0b01000000;break;
    case 0:loud = 0b01000100;break;
  }
  switch (usil){
    case 0:usil = 0b01011000;break;
    case 1:usil = 0b01010000;break;
    case 2:usil = 0b01001000;break;
    case 3:usil = 0b01000000;break; 
  }
  int sw = input + loud + usil;
  writeWire(sw);
}

void TDA7313::setBass(int bass){
  switch (bass){
    case -7: bass = 0b01100000;break;
    case -6: bass = 0b01100001;break;
    case -5: bass = 0b01100010;break;
    case -4: bass = 0b01100011;break; 
    case -3: bass = 0b01100100;break;
    case -2: bass = 0b01100101;break;
    case -1: bass = 0b01100110;break;
    case 0:  bass = 0b01100111;break;
    case 1:  bass = 0b01101110;break;
    case 2:  bass = 0b01101101;break;
    case 3:  bass = 0b01101100;break;
    case 4:  bass = 0b01101011;break;
    case 5:  bass = 0b01101010;break;
    case 6:  bass = 0b01101001;break;
    case 7:  bass = 0b01101000;break;
  }
  writeWire(bass);
}

void TDA7313::setTreble(int treble){
  switch (treble){
    case -7: treble = 0b01110000;break;
    case -6: treble = 0b01110001;break;
    case -5: treble = 0b01110010;break;
    case -4: treble = 0b01110011;break; 
    case -3: treble = 0b01110100;break;
    case -2: treble = 0b01110101;break;
    case -1: treble = 0b01110110;break;
    case 0:  treble = 0b01110111;break;
    case 1:  treble = 0b01111110;break;
    case 2:  treble = 0b01111101;break;
    case 3:  treble = 0b01111100;break;
    case 4:  treble = 0b01111011;break;
    case 5:  treble = 0b01111010;break;
    case 6:  treble = 0b01111001;break;
    case 7:  treble = 0b01111000;break;
  }
  writeWire(treble);
}

void TDA7313::writeWire(char a){
  Wire.beginTransmission(TDA7313_address);
  Wire.write (a);
  Wire.endTransmission();
}
