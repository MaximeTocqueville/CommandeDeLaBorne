#include <Wire.h>
#include "I2C.h"
#include "fonctionbarriere.h"
#include "affiche.h"
#include "clavier.h"

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  initI2C(220);
}

void loop()
{
  static int nbVoiture = 10;
  int tempo = 0, testTempo, essaie = 3;
  bool test1, test2;
  //fermeture(MECA);
  if (boucleAmond() == true && boucleAval() == false)
  {
    while (essaie != 0)
    {
      if (code() == false)
      {
        Serial.print("ouverture");
        ouverture(MECA);
        testTempo = 1;
        while (boucleAmond() == true && boucleAval() == false && testTempo == 1)
        {
          delay(30);
          tempo++;
          Serial.println(tempo);
          if (tempo == 1000)
          {
            testTempo = 0;
          }
        }
        delay(20);
        if (boucleAmond() == false || boucleAval() == true)
        {
          if (boucleAmond() == true || boucleAmond() == true)
          {
            while (boucleAmond() == true || boucleAval() == true)
            {
              test1 = boucleAmond();
              test2 = boucleAval();
            }
          }
        }
        essaie = 0;
        fermeture(MECA);
        if (test1 == false && test2 == true)
        {
          nbVoiture++;
          Serial.println(nbVoiture);
        }
      }
      else
      {
        essaie--;
        Serial.println("faux");
      }
    }
  }
  if (boucleAmond() == false && boucleAval() == true)
  {
    ouverture(MECA);
    while (boucleAmond() == false && boucleAval() == true);
    if (boucleAmond() == true || boucleAval() == true)
    {
      while (boucleAmond() == true || boucleAval() == true)
      {
        test1 = boucleAmond();
        test2 = boucleAval();
      }
    }
    fermeture(MECA);
    if (test1 == true && test2 == false)
    {
      nbVoiture--;
      Serial.println(nbVoiture);
    }
  }
}
