#include <Wire.h>
#include <Arduino.h>
#include "fonctionbarriere.h"

void ouverture(int address)
{
  Wire.beginTransmission(address);
  Wire.write(OUVRIR);
  Wire.endTransmission();
  delay(500);
}

void fermeture(int address)
{
  Wire.beginTransmission(address);
  Wire.write(FERMER);
  Wire.endTransmission();
  delay(500);
}

boolean boucleAmond()
{
  if (lectureBoucle(MECA) == 64  || lectureBoucle(MECA) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

boolean boucleAval()
{
  if (lectureBoucle(MECA) == 32 || lectureBoucle(MECA) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int lectureBoucle(int address)
{
  int c;
  Wire.beginTransmission(address);
  Wire.write(BARRIERE);
  Wire.endTransmission();
  
  Wire.requestFrom(address, 1);
  while (Wire.available())
  {
    c = Wire.read();
  }
  return c;
}
