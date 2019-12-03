#include <Wire.h>
#include "I2C.h"
#include "fonctionbarriere.h"

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  initI2C(200);
}

void loop()
{
  static int nbVoiture = 0;
  int tempo = 0, testTempo;
  if (boucleAmond() == 1 && boucleAval() == 0)
  {
    /*if ()
      {*/
    ouverture(MECA);
    testTempo = 1;
    while (boucleAmond() == 1 && boucleAval() == 0 && testTempo == 1)
    {
      delay(30);
      tempo++;
      if (tempo == 1000)
      {
        testTempo = 0;
      }
    }
    delay(20);
    if (boucleAmond() == 0 && boucleAval() == 1)
    {
      if (boucleAmond() == 1)
      {

      }
      while (boucleAmond() == 1 && boucleAval() == 1);
      fermeture(MECA);
    }
    /*}*/
  }
  if (boucleAmond() == 0 && boucleAval() == 1)
  {
    ouverture(MECA);
    while (boucleAmond() == 0 && boucleAval() == 1);
    if (boucleAmond() == 1 || boucleAval() == 1)
    {
      while (boucleAmond() == 1 || boucleAval() == 1);
    }
    fermeture(MECA);
  }
}
