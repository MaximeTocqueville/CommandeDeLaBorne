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
  initAfficheur(AFFICHEUR);
}

void loop()
{
  static int nbVoiture = 10;
  int tempo = 0, testTempo, essaie = 3;
  bool test1, test2;
 //fermeture(MECA);
 //effacerAfficheur (AFFICHEUR);
  if (boucleAmond() == true && boucleAval() == false)
  {
    setEclairage(AFFICHEUR, 1);
    envoyerMessage(AFFICHEUR,  MESSAGE1, LIGNE1);
    delay(200);
    effacerAfficheur (AFFICHEUR);
    envoyerMessage(AFFICHEUR,  MESSAGE2, LIGNE1);
    envoyerMessage(AFFICHEUR,  MESSAGE3, LIGNE2);
    while (essaie != 0)
    {
      if (code() == false)
      {
        effacerAfficheur (AFFICHEUR);
        envoyerMessage(AFFICHEUR,  MESSAGE8, LIGNE1);
        ouverture(MECA);
        testTempo = 1;
        while (boucleAmond() == true && boucleAval() == false && testTempo == 1)
        {
          delay(30);
          tempo++;
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
        effacerAfficheur (AFFICHEUR);
        if (test1 == false && test2 == true)
        {
          nbVoiture++;
          envoyerMessage(AFFICHEUR,  MESSAGE11, LIGNE1);
          Serial.println(nbVoiture);
        }
      }
      else
      {
        essaie--;
        if(essaie == 2)
        {
          effacerAfficheur (AFFICHEUR);
          envoyerMessage(AFFICHEUR,  MESSAGE9, LIGNE1);
          envoyerMessage(AFFICHEUR,  MESSAGE6, LIGNE2);
        }
        else if(essaie == 1)
        {
          effacerAfficheur (AFFICHEUR);
          envoyerMessage(AFFICHEUR,  MESSAGE9, LIGNE1);
          envoyerMessage(AFFICHEUR,  MESSAGE7, LIGNE2);
        }
        else
        {
          effacerAfficheur (AFFICHEUR);
          envoyerMessage(AFFICHEUR,  MESSAGE9, LIGNE1);
          envoyerMessage(AFFICHEUR,  MESSAGE10, LIGNE2);
          while(boucleAmond() == true);
          effacerAfficheur (AFFICHEUR);
        }
      }
      setEclairage(AFFICHEUR, 0);
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
