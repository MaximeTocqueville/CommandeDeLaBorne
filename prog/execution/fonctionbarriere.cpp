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
  if (lectureBoucle(MECA) == 64)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

boolean boucleAval()
{
  if (lectureBoucle(MECA) == 32)
  {
    return 1;
  }
  else
  {
    return 0;
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
