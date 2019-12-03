//fichier d'entete
#ifndef AFFICHE_H
#define AFFICHE_H

#include "Arduino.h"

#define LIGNE1 0x00
#define LIGNE2 0x40

#define MESSAGE1 "Bonjour"
#define MESSAGE2 "Entrez code ou insere carte SVP"
#define MESSAGE3 "Code correct"
#define MESSAGE4 "Bienvenu"
#define MESSAGE7 "carte non valide"
#define MESSAGE8 "Quittez la place"
#define MESSAGE9 "code non valide "
#define MESSAGE10 "Quittez la place"



void initAfficheur(int adress); // fonction qui initialise un afficheur on place l'adresse en parametre
void effacerAfficheur (int adress);
void setEclairage(int adress,int valeur);

void activerAfficheur (int adress);
void desactiverAfficheur (int adress);

void envoyerCommande(int adress,int valeur);
void envoyerDonnee(int adress,int valeur);
void envoyerMessage(int adress,const char* maChaine,int ligne);
void blinkAfficheur(int adress,int nombre,unsigned long duree);
void shiftAfficheur(int adress, int valeur);

#endif
