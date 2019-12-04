#include "clavier.h"
#include <Wire.h>

bool ToucheAppuye()
{
  if (VerificationLigne() == 15 && VerificationColonne() == 240)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int VerificationLigne() {
  int c;
  Wire.beginTransmission(ADRESSE);

  Wire.write(15);
  Wire.endTransmission();

  Wire.requestFrom(ADRESSE, 1);

  while (Wire.available()) {
    c = Wire.read();
  }
  return c;
}

int VerificationColonne() {
  int d;
  Wire.beginTransmission(ADRESSE);
  Wire.write(240);
  Wire.endTransmission();

  Wire.requestFrom(ADRESSE, 1);
  while (Wire.available()) {
    d = Wire.read();
  }
  return d;
}

char LireTouche(int ligne, int colonne)
{
  int code = 1234;

  int i;
  char touche;

  switch (ligne) {
    case 14  : switch (colonne) {
        case 224 : touche = '1'; // Serial.println(touche);
          break;

        case 208 : touche = '2'; //Serial.println(touche);
          break;

        case 176 : touche = '3'; // Serial.println(touche);
          break;
      }
      break;
    case 13 :   switch (colonne) {
        case 224 : touche = '4'; // Serial.println(touche) ;
          break;

        case 208 :  touche = '5'; //Serial.println(touche);
          break;

        case 176 :   touche = '6'; //Serial.println(touche);
          break;
      }
      break;
    case 11 :   switch (colonne) {
        case 224 : touche = '7'; //Serial.println(touche);
          break;

        case 208 : touche = '8'; // Serial.println(touche);
          break;

        case 176 : touche = '9'; //Serial.println(touche);
          break;
      }
      break;
    case 7 :   switch (colonne) {
        case 224 : touche = '*'; // Serial.println(touche);
          break;

        case 208 :  touche = '0'; // Serial.println(touche);
          break;

        case 176 :  touche = '#'; //Serial.println(touche);
          break;
      }
      break;
    default : break;
  }
  return touche;
}

bool code()
{
  int ligne, colonne;
  char tab[5]="";
  char code[5] = {"1234"};
  for (int i = 0; i < 4; i++)
  {
    delay(80);
    if (ToucheAppuye() == false)
    {
      ligne = VerificationLigne();
      colonne = VerificationColonne();
      tab[i] = LireTouche(ligne, colonne);
      Serial.println(tab);
    }
    else
    {
      i--;
    }
    while (ToucheAppuye() == false);
  }
  return strcmp(tab, code);
}
  
  
